#include "ISensorHubServer.h"
#include <binder/IServiceManager.h>
#include <unistd.h>
#include <stdio.h>

    
using namespace android;

int main()
{
    sp<IServiceManager> sm =defaultServiceManager();  
    sp<IBinder> binder =sm->getService(String16("sensorhubservice"));  
    sp<ISensorHubServer> server =interface_cast<ISensorHubServer>(binder);  
    printf("%s",server->getString());  

    return 0;
}
