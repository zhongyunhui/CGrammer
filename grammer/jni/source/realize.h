//
// Created by Administrator on 2020/12/15.
//

#ifndef H264PLAYER_REALIZE_H
#define H264PLAYER_REALIZE_H

#include <jni.h>
#include "librtmp/rtmp.h"
jboolean NativeConnect(JNIEnv *env,jobject jobject1,jstring jurl);
jboolean NativeSendData(JNIEnv *env,jobject jobject1,jbyteArray jdata,jint len,jlong tms);

namespace Delimiter{
    int8_t Dsps[4]={0x00,0x00,0x01,0x67};
    int8_t Dpps[4]={0x00,0x00,0x01,0x68};
}
#endif //H264PLAYER_REALIZE_H
