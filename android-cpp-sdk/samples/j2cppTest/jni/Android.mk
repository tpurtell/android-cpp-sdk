LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE		:= j2cppTest
LOCAL_SRC_FILES		:= com_j2cpp_Test.cpp so_main.cpp

LOCAL_C_INCLUDES	:=	$(LOCAL_PATH)/../../../j2cpp \
						$(LOCAL_PATH)/../../../platforms/android-7
						
LOCAL_LDLIBS    	:= -llog

include $(BUILD_SHARED_LIBRARY)
