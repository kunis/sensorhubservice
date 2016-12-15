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

#include <inttypes.h>
#include <math.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <dlfcn.h>

#include <cutils/properties.h>

#include <utils/SortedVector.h>
#include <utils/KeyedVector.h>
#include <utils/threads.h>
#include <utils/Atomic.h>
#include <utils/Errors.h>
#include <utils/RefBase.h>
#include <utils/Singleton.h>
#include <utils/String16.h>

#include <binder/BinderService.h>
#include <binder/IServiceManager.h>
#include <binder/PermissionCache.h>


#include "SensorHubService.h"

namespace android {
// ---------------------------------------------------------------------------

/*
 * Notes:
 *
 * - what about a gyro-corrected magnetic-field sensor?
 * - run mag sensor from time to time to force calibration
 * - gravity sensor length is wrong (=> drift in linear-acc sensor)
 *
 */


SensorHubService::SensorHubService()
{
}


SensorHubService::~SensorHubService()
{
}

#if 0
status_t SensorHubService::dump(int fd, const Vector<String16>& /*args*/)
{
    String8 result;
        
    result.append("Hello SensorHubService!\n");
    write(fd, result.string(), result.size());
    return NO_ERROR;
}
#endif
char* SensorHubService::getString()
{

    char *s = "hello world\n";
    return s;

}


}; // namespace android

