#include <binder/BinderService.h>
#include "SensorHubService.h"
using namespace android;

int main()
{

    SensorHubService::publishAndJoinThreadPool();
    return 0;
}
