#include "com_j2cpp_Test.h"
#include <j2cpp/j2cpp.hpp>

#include <java/lang/Math.hpp>
#include <java/util/BitSet.hpp>
#include <java/lang/String.hpp>
#include <android/opengl/GLES10.hpp>
#include <android/app/ActivityManager.hpp>
#define J2CPP_INCLUDE_IMPLEMENTATION
#include <java/lang/Math.hpp>
#include <java/util/BitSet.hpp>
#include <java/lang/String.hpp>
#include <android/opengl/GLES10.hpp>
#include <android/app/ActivityManager.hpp>


jdouble Java_com_j2cpp_Test_math_1cos(JNIEnv *env, jobject theTest, jdouble angle)
{
	return j2cpp::java::lang::Math::cos(angle);
}

jdouble Java_com_j2cpp_Test_math_1sin(JNIEnv *env, jobject theTest, jdouble angle)
{
	return j2cpp::java::lang::Math::sin(angle);
}

jboolean Java_com_j2cpp_Test_testBitSetBit(JNIEnv *env, jobject theTest, jobject bs, jint bit)
{
	j2cpp::java::util::BitSet theBitset(bs);
	return theBitset.get(bit);
}

jint Java_com_j2cpp_Test_testStringLength(JNIEnv *env, jobject theTest, jstring testString)
{
	j2cpp::java::lang::String theString(testString);
	return theString.length();
}

jchar Java_com_j2cpp_Test_testStringCharAt(JNIEnv *env, jobject theTest, jstring testString, jint charAt)
{

	j2cpp::java::lang::String theString(testString);
	return theString.charAt(charAt);
}

jstring Java_com_j2cpp_Test_testStringCreate(JNIEnv *env, jobject theTest)
{
	char stringChars[] = "test string ha ha hi!";
	j2cpp::local_ref< j2cpp::cpp_byte_array<1> > theStringChars(
		j2cpp::create<1>(sizeof(stringChars))
	);
	theStringChars->set(0,sizeof(stringChars),reinterpret_cast<jbyte*>(stringChars));
	return reinterpret_cast<jstring>(j2cpp::create<j2cpp::java::lang::String>(theStringChars).get_jtype());
}

jobject Java_com_j2cpp_Test_testBitSetCreate(JNIEnv *env, jobject theTest)
{
	return j2cpp::create<j2cpp::java::util::BitSet>(j2cpp::cpp_int(10));
}

jint Java_com_j2cpp_Test_testGetValueOf_1GL_1TRUE(JNIEnv *env, jobject theTest)
{

	return j2cpp::cpp_int(j2cpp::android::opengl::GLES10::GL_TRUE);
}

jobject Java_com_j2cpp_Test_testField(JNIEnv *env, jobject theTest)
{
	j2cpp::global_ref<j2cpp::android::app::ActivityManager::RecentTaskInfo> retValue(
			j2cpp::create<j2cpp::android::app::ActivityManager::RecentTaskInfo>()
	);
	retValue->id=100;
	return retValue.get_jtype();
}
