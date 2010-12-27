package com.j2cpp;

import android.app.Activity;
import android.os.Bundle;
import android.widget.*;

public class Test extends Activity {
	
	static {
		System.loadLibrary("j2cppTest");
	}
	
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        
        TextView consoleView = new TextView(this);
        setContentView(consoleView);
        
        doTests(consoleView);
        
    }
    
    private static native void doTests(TextView tv);
}