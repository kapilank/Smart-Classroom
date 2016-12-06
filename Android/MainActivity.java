package com.smart;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends Activity {
	/** Called when the activity is first created. */

	private Button obj;
	private EditText txt;
	public static String ip = "";

	public void onCreate(Bundle savedInstanceState) {
		try {
			super.onCreate(savedInstanceState);
			setContentView(R.layout.activity_main);
			obj = (Button) findViewById(R.id.submit1);
			txt = (EditText) findViewById(R.id.ipaddr);
			obj.setOnClickListener(new OnClickListener() {

				@Override
				public void onClick(View v) {
					ip = txt.getText().toString().trim();
					if ((ip == null) || ip.isEmpty() || (ip.length() < 6) || (ip.length() > 15)) {
						txt.setError("Enter  valid ip");
					} else {
						MainApplication.IP_ADDRESS = ip;
						Toast.makeText(getApplicationContext(), ip, Toast.LENGTH_SHORT).show();
						Intent i = new Intent(MainActivity.this, LoginActivity.class);
						startActivity(i);
					}

				}
			});
		} catch (Exception e) {
			// TODO: handle exception
			Toast.makeText(getApplicationContext(), " " + e.toString(), Toast.LENGTH_SHORT).show();
		}

	}
}