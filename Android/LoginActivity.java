package com.smart;

//import com.logic.R;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.MalformedURLException;
import java.net.URL;

import com.serverconnection.ServerConnection;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.os.StrictMode;
import android.text.TextUtils;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.Spinner;
import android.widget.TextView;
import android.widget.Toast;

public class LoginActivity extends Activity {
	private EditText et1, et2;
	private Button b1;
	private TextView t1;
	private RadioButton rad1, rad2;
	Spinner spn;
	private Intent i = new Intent();
	Bundle extras = new Bundle();

	public void onCreate(Bundle savedInstanceState) {
		try {
			if (android.os.Build.VERSION.SDK_INT > 9) {
				StrictMode.ThreadPolicy policy = new StrictMode.ThreadPolicy.Builder().permitAll().build();
				StrictMode.setThreadPolicy(policy);
			}
			super.onCreate(savedInstanceState);
			setContentView(R.layout.activity_login);
			b1 = (Button) findViewById(R.id.button12);
			t1 = (TextView) findViewById(R.id.registrationtext1);
			et1 = (EditText) findViewById(R.id.editTextId);
			et2 = (EditText) findViewById(R.id.editTextPassword);
			b1.setOnClickListener(new View.OnClickListener() {
				@Override
				public void onClick(View v) {
					// TODO Auto-generated method stub
					Toast.makeText(getApplicationContext(), et1.getText().toString().trim(), Toast.LENGTH_SHORT).show();

					try {

						if (et1.getText().toString().trim().equalsIgnoreCase("admin")
								&& et2.getText().toString().trim().equalsIgnoreCase("admin")) {
							Intent in1 = new Intent(LoginActivity.this, AdminActivity.class);
							startActivity(in1);
						} else {
							String parameters = "staffId=" + et1.getText().toString().trim() + "&password="
									+ et2.getText().toString().trim();
							String res = ServerConnection.serverCall("login", parameters);
							if (res.contains("success")) {
								MainApplication.STAFF_IP=res.split("\\$")[1];
								MainApplication.STAFF_DEPT=res.split("\\$")[2];
								Toast.makeText(getApplicationContext(), MainApplication.STAFF_IP+"   "+MainApplication.STAFF_DEPT, Toast.LENGTH_SHORT).show();
								Intent in1 = new Intent(LoginActivity.this, StaffActivity.class);
								startActivity(in1);
							}
							else
							{
								Toast.makeText(getApplicationContext(), res, Toast.LENGTH_SHORT).show();
							}
						}
					} catch (Exception e) {
						Toast.makeText(getApplicationContext(), "" + e, Toast.LENGTH_SHORT).show();
					}

				}
			});
			t1.setOnClickListener(new View.OnClickListener() {

				@Override
				public void onClick(View v) {
					// TODO Auto-generated method stub
					i = new Intent(LoginActivity.this, RegistrationActivity.class);
					startActivity(i);
				}
			});
			// spn=(Spinner) findViewById(R.id.spinner1);
			// t2 = (EditText) findViewById(R.id.editText2);
			// t3=(EditText) findViewById(R.id.registrationtext);
			// b1 = (Button) findViewById(R.id.button1);
			//
			//
			// Bundle bdl= new Bundle();
			// bdl=getIntent().getExtras();
			// ip=bdl.getString("ip").toString();
			//
			//
			// b1.setOnClickListener(new View.OnClickListener()
			// {
			// public void onClick(View v)
			// {
			// try {
			//
			// // if(rad1.isChecked())
			// // {
			// // Toast.makeText(getApplicationContext(),
			// // "hi user", Toast.LENGTH_LONG)
			// // .show();
			// // }
			// // String strUserName = t1.getText().toString();
			// //
			// // if(TextUtils.isEmpty(strUserName)) {
			// // t1.setError("enter the username");
			// //
			// // }
			// URL u = new URL(
			// "http://"+ip+":9999/SMARTCLASS/register?user="
			// + t1.getText().toString().trim()
			// + "&pass="
			// + t2.getText().toString().trim());
			// BufferedReader in = new BufferedReader(
			// new InputStreamReader(u.openStream()));
			// String str = in.readLine();
			// Toast.makeText(getApplicationContext(),
			// str, Toast.LENGTH_SHORT)
			// .show();
			// // String s[] = str.split("\\$");
			// if (str.equalsIgnoreCase("success")) {
			// Toast.makeText(getApplicationContext(),
			// "Registration Success", Toast.LENGTH_SHORT)
			// .show();
			// Intent intent = new
			// Intent(LoginsampleActivity.this,Registration.class);
			//
			//
			// // intent.putExtra("name", s[1]);
			// // startActivityForResult(intent, 3);
			// startActivity(intent);
			// } else if (str.equalsIgnoreCase("failure")) {
			// Toast.makeText(getApplicationContext(),
			// "Registration failed", Toast.LENGTH_SHORT)
			// .show();
			// Intent intent = new Intent(getApplicationContext(),
			// LoginsampleActivity.class);
			// }
			// } catch (Exception e) {
			// e.printStackTrace();
			// }
			//
			// }
			//
			//
			// });
			// t3.setOnClickListener(new View.OnClickListener() {
			//
			// public void onClick(View v) {
			// // TODO Auto-generated method stub
			// Toast.makeText(getApplicationContext(),
			// "Registration Success", Toast.LENGTH_SHORT)
			// .show();
			// Intent intent = new
			// Intent(LoginsampleActivity.this,Registration.class);
			// intent.putExtra("ip", ip);
			// startActivity(intent);
			// }
			// });
		} catch (Exception e) {
			Toast.makeText(getApplicationContext(), "" + e, Toast.LENGTH_SHORT).show();
		}
	}
}