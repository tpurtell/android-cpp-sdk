#include <j2cpp/j2cpp.hpp>
#include <java/lang/String.hpp>
#include <java/lang/Math.hpp>
#include <android/widget/TextView.hpp>
#include "com_j2cpp_Test.h"

using namespace j2cpp;

void Java_com_j2cpp_Test_doTests(JNIEnv *env, jclass Test, jobject tv)
{
	android::widget::TextView theTextView(tv);
	//char stringChars[] = "Android C++ SDK Example";

	//cpp_byte_array<1> theByteArray(sizeof(stringChars));



	theTextView.append(java::lang::String(array<jbyte,1>("Android C++ SDK Example")));
}

