# Copyright 2010 The Android Open Source Project

LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)
LOCAL_CPPFLAGS := -Wall

LOCAL_SRC_FILES := main.cpp  SensorHubService.cpp ISensorHubServer.cpp
LOCAL_MODULE := sensorhubd
LOCAL_SHARED_LIBRARIES := \
	liblog \
	libutils \
	libcutils \
	libbinder 

include $(BUILD_EXECUTABLE)






include $(CLEAR_VARS)
LOCAL_CPPFLAGS := -Wall

LOCAL_SRC_FILES := test/main.cpp   ISensorHubServer.cpp
LOCAL_MODULE := service_test
LOCAL_SHARED_LIBRARIES := \
	liblog \
	libutils \
	libcutils \
	libbinder 


include $(BUILD_EXECUTABLE)

