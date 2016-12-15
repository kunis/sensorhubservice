/*
 * Copyright (C) 2010 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdint.h>
#include<stdlib.h>
#include <sys/types.h>

#include <utils/Errors.h>
#include <utils/RefBase.h>
#include <utils/Vector.h>
#include <utils/Timers.h>

#include <binder/Parcel.h>
#include <binder/IInterface.h>

#include "ISensorHubServer.h"

namespace android {
// ----------------------------------------------------------------------------

enum {
    GET_STRING = IBinder::FIRST_CALL_TRANSACTION,
};

class BpSensorHubServer : public BpInterface<ISensorHubServer>
{
public:
    BpSensorHubServer(const sp<IBinder>& impl)
        : BpInterface<ISensorHubServer>(impl)
    {
    }

    virtual char *getString()
    {
        char *fullstr =NULL;
        Parcel data, reply;
        data.writeInterfaceToken(ISensorHubServer::getInterfaceDescriptor());
        remote()->transact(GET_STRING, data, &reply);
        const char *s = reply.readCString();
        fullstr = (char *)malloc(128);
        strcpy(fullstr,s);
        return fullstr;
    }

};

IMPLEMENT_META_INTERFACE(SensorHubServer, "ISensorHubServer");

// ----------------------------------------------------------------------

status_t BnSensorHubServer::onTransact(
    uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags)
{
    switch(code) {
        case GET_STRING: {

            CHECK_INTERFACE(ISensorHubServer, data, reply);
            char *s = getString();
            reply->writeCString(s);
            return NO_ERROR;
        } break;
    }
    return BBinder::onTransact(code, data, reply, flags);
}

// ----------------------------------------------------------------------------
}; // namespace android
