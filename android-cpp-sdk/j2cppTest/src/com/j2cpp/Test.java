package com.j2cpp;

import android.app.Activity;
import android.os.Bundle;


public class Test extends Activity {
	
	static {
		System.loadLibrary("j2cppTest");
	}
	
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        
        
        android.app.ActivityManager.RecentTaskInfo rti=testField();
        if(rti.id==100)
        {
        	math_cos(0.0);        	
        }
        math_cos(0.0);
        math_sin(0.0);
        java.util.BitSet bs=new java.util.BitSet(8);
        bs.set(2,true);
        boolean bitValue1=testBitSetBit(bs,2);
        bs.set(2,false);
        boolean bitValue2=testBitSetBit(bs,2);
        if(bitValue1 && !bitValue2)
        {
        }
        
        java.util.BitSet theBitSet=testBitSetCreate();
        int bitsetSize=theBitSet.length();
        
        int theValueOf_GL_TRUE_is=testGetValueOf_GL_TRUE();
        if(theValueOf_GL_TRUE_is==android.opengl.GLES10.GL_TRUE)
        {
        	int ok=1;
        }
                
        java.lang.String createdString=testStringCreate();
        int strLength=createdString.length();
        
        
        java.lang.String strTest=new java.lang.String("this is a test string");
        char charValue;
        for(int i=0;i<testStringLength(strTest);i++)
        {
        	charValue=testStringCharAt(strTest,i);
        	if(charValue=='t')
        	{
        		
        	}
        }
        
        setContentView(R.layout.main);
    }
    
    public native double math_cos(double angle);
    public native double math_sin(double angle);
    public native boolean testBitSetBit(java.util.BitSet bs, int bit);
    public native int testStringLength(java.lang.String str);
    public native char testStringCharAt(java.lang.String str, int at);
    public native java.lang.String testStringCreate();
    public native java.util.BitSet testBitSetCreate();
    public native int testGetValueOf_GL_TRUE();
    public native android.app.ActivityManager.RecentTaskInfo testField();
    
}