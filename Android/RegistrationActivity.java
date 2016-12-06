package com.smart;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.ArrayList;
import java.util.List;
import com.serverconnection.ServerConnection;
import android.app.Activity;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.RatingBar;
import android.widget.Toast;

public class RegistrationActivity extends Activity {
	public EditText name, email, dept, phone, ipaddr;
	private Button submit;
	private Intent intent;
	private String ip;
	Bundle bdl = new Bundle();
	List<String> list = new ArrayList<String>();
	AlertDialog alertDialog = null;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		try {
			// TODO Auto-generated method stub
			super.onCreate(savedInstanceState);
			setContentView(R.layout.activity_registration);
			name = (EditText) findViewById(R.id.regname);
			email = (EditText) findViewById(R.id.regemail);
			dept = (EditText) findViewById(R.id.edtitTextDept);
			ipaddr = (EditText) findViewById(R.id.editTextIP);
			phone = (EditText) findViewById(R.id.editTextPhone);
			submit = (Button) findViewById(R.id.regbutton);
			list.add("ECE");
			list.add("IT");
			submit.setOnClickListener(new View.OnClickListener() {
				@Override
				public void onClick(View v) {
					// TODO Auto-generated method stub
					if (!name.getText().toString().equalsIgnoreCase("")) {
						if (!email.getText().toString().equalsIgnoreCase("")
								&& email.getText().toString().contains("@")) {
							if (!dept.getText().toString().equalsIgnoreCase("")
									&& list.contains(dept.getText().toString().trim().toUpperCase())) {
								if (!phone.getText().toString().equalsIgnoreCase("")
										&& phone.getText().toString().trim().length() ==10)
									if (!ipaddr.getText().toString().equalsIgnoreCase("")) {
										try {
											String parameters = "uname=" + name.getText().toString().trim() + "&email="
													+ email.getText().toString().trim() + "&dept="
													+ dept.getText().toString().trim() + "&phone="
													+ phone.getText().toString().trim() + "&ip="
													+ ipaddr.getText().toString().trim();
											String res = ServerConnection.serverCall("register", parameters);
											Toast.makeText(getApplicationContext(), res, Toast.LENGTH_SHORT).show();
											if (res.split("\\$")[0].equalsIgnoreCase("success")) {
												String msg = "Staff id:" + res.split("\\$")[1] + "\nPassword:"
														+ res.split("\\$")[2];
												alertBox(msg);
											} else if (res.split("\\$")[0].equalsIgnoreCase("fail")) {
												intent = new Intent(RegistrationActivity.this, LoginActivity.class);
												startActivity(intent);
											}
										} catch (Exception e) {
											Toast.makeText(getApplicationContext(), "" + e, Toast.LENGTH_SHORT).show();
										}
									} else {

										ipaddr.setError("Enter the ip address");
									}

								else {

									phone.setError("Enter the valid phone number");
								}

							} else {
								dept.setError("Enter the valid department");

							}
						} else {
							email.setError("Enter the valid email");

						}

					}

					else {
						name.setError("enter the name");
					}

				}
			});
			
		} catch (Exception e) {
			showToast(" Exe oncreate :" + e);
		}

	}

	private void alertBox(String msg) {
		try {
			AlertDialog.Builder alertDialogBuilder = new AlertDialog.Builder(RegistrationActivity.this);
			alertDialogBuilder.setTitle("Staff Id");
			alertDialogBuilder.setMessage(msg);
			alertDialogBuilder.setPositiveButton("OK", new DialogInterface.OnClickListener() {
				@Override
				public void onClick(DialogInterface arg0, int arg1) {
					alertDialog.dismiss();
					Intent intent = new Intent(RegistrationActivity.this, LoginActivity.class);
					startActivity(intent);
				}
			});
			alertDialog = alertDialogBuilder.create();
			alertDialog.show();
		} catch (Exception e) {
			showToast(" Exe alert :" + e);
		}
	}

	private void showToast(String msg) {
		Toast.makeText(getBaseContext(), " " + msg, Toast.LENGTH_SHORT).show();
	}
}
