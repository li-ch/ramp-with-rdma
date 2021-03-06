/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_yahoo_ycsb_db_JNIRAMPClient */

#ifndef _Included_com_yahoo_ycsb_db_JNIRAMPClient
#define _Included_com_yahoo_ycsb_db_JNIRAMPClient
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_yahoo_ycsb_db_JNIRAMPClient
 * Method:    _configure
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_yahoo_ycsb_db_JNIRAMPClient__1configure
  (JNIEnv *, jclass);

/*
 * Class:     com_yahoo_ycsb_db_JNIRAMPClient
 * Method:    _construct
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_yahoo_ycsb_db_JNIRAMPClient__1construct
  (JNIEnv *, jobject);

/*
 * Class:     com_yahoo_ycsb_db_JNIRAMPClient
 * Method:    _destruct
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_yahoo_ycsb_db_JNIRAMPClient__1destruct
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_yahoo_ycsb_db_JNIRAMPClient
 * Method:    _connect_all
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_yahoo_ycsb_db_JNIRAMPClient__1connect_1all
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_yahoo_ycsb_db_JNIRAMPClient
 * Method:    _close_all
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_yahoo_ycsb_db_JNIRAMPClient__1close_1all
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_yahoo_ycsb_db_JNIRAMPClient
 * Method:    _read
 * Signature: (JLjava/lang/String;Ljava/util/Set;)V
 */
JNIEXPORT void JNICALL Java_com_yahoo_ycsb_db_JNIRAMPClient__1read
  (JNIEnv *, jobject, jlong, jstring, jobject);

/*
 * Class:     com_yahoo_ycsb_db_JNIRAMPClient
 * Method:    _insert
 * Signature: (JLjava/lang/String;Ljava/util/HashMap;)V
 */
JNIEXPORT void JNICALL Java_com_yahoo_ycsb_db_JNIRAMPClient__1insert
  (JNIEnv *, jobject, jlong, jstring, jobject);

/*
 * Class:     com_yahoo_ycsb_db_JNIRAMPClient
 * Method:    _put_all
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_yahoo_ycsb_db_JNIRAMPClient__1put_1all
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_yahoo_ycsb_db_JNIRAMPClient
 * Method:    _get_all
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_yahoo_ycsb_db_JNIRAMPClient__1get_1all
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_yahoo_ycsb_db_JNIRAMPClient
 * Method:    _clear
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_yahoo_ycsb_db_JNIRAMPClient__1clear
  (JNIEnv *, jobject, jlong);

#ifdef __cplusplus
}
#endif
#endif
