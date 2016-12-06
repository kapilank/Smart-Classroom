package com.smart;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.MalformedURLException;
import java.net.URL;

import com.serverconnection.ServerConnection;
import com.smart.TimeTableActivity.Post;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class AdminActivity extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		try {
			// TODO Auto-generated method stub
			super.onCreate(savedInstanceState);
			setContentView(R.layout.activity_admin);
			Button p = (Button) findViewById(R.id.buttonPresent);
			Button n = (Button) findViewById(R.id.buttonNotPresent);
			Button btnOpen = (Button) findViewById(R.id.buttonOpen);
			Button btnStatus = (Button) findViewById(R.id.buttonStatus);
			Button btndeptTable = (Button) findViewById(R.id.buttonViewDeptTable);

			btnStatus.setOnClickListener(new View.OnClickListener() {

				@Override
				public void onClick(View v) {
					try {
						EditText et_status = (EditText) findViewById(R.id.editTextSendStatus);
						String st = et_status.getText().toString().trim();
						if (!st.equals("") && st.length() == 1) {
							String response = ServerConnection.serverCall("Status", "teacherStatus=" + st);
							Toast.makeText(getApplicationContext(), response, Toast.LENGTH_SHORT).show();
						} else {
							Toast.makeText(getApplicationContext(), "Please Check Input !!!", Toast.LENGTH_SHORT)
									.show();
						}
					} catch (Exception e) {
						Toast.makeText(getApplicationContext(), "" + e, Toast.LENGTH_SHORT).show();
					}
				}
			});
			p.setOnClickListener(new View.OnClickListener() {

				@Override
				public void onClick(View v) {
					String response = ServerConnection.serverCall("TeacherStatus", "teacherStatus=P");
					Toast.makeText(getApplicationContext(), response, Toast.LENGTH_SHORT).show();
				}
			});
			n.setOnClickListener(new View.OnClickListener() {

				@Override
				public void onClick(View v) {
					String response=ServerConnection.serverCall("TeacherStatus", "teacherStatus=N");
					Toast.makeText(getApplicationContext(), response, Toast.LENGTH_SHORT).show();
				}
			});
			btnOpen.setOnClickListener(new View.OnClickListener() {

				@Override
				public void onClick(View v) {
					try {
						EditText ipaddr = (EditText) findViewById(R.id.editTextWebIp);
						if (!ipaddr.getText().toString().trim().equalsIgnoreCase("")) {
							Intent i = new Intent(AdminActivity.this, WebViewActivity.class);
							String url = "http://" + ipaddr.getText().toString().trim();
							Toast.makeText(getApplicationContext(), "Web Kit Url " + url, Toast.LENGTH_SHORT).show();
							Bundle bundle = new Bundle();
							bundle.putString("url", url);
							i.putExtras(bundle);
							startActivity(i);
						}

					} catch (Exception e) {
						Toast.makeText(getApplicationContext(), "" + e, Toast.LENGTH_SHORT).show();
					}
				}
			});
			btndeptTable.setOnClickListener(new View.OnClickListener() {

				@Override
				public void onClick(View v) {
					final String items[] = { "ECE", "IT" };
					AlertDialog.Builder alertDialogBuilder = new AlertDialog.Builder(AdminActivity.this);
					alertDialogBuilder.setTitle("View Dept");
					alertDialogBuilder.setSingleChoiceItems(items, 1, new DialogInterface.OnClickListener() {
						public void onClick(DialogInterface dialog, int item) {

							try {
								String viewto = items[item];
								MainApplication.STAFF_DEPT = viewto;
								Toast.makeText(getApplicationContext(), "Selected Dept: " + viewto, Toast.LENGTH_LONG)
										.show();
								Intent r = new Intent(getApplicationContext(), TimeTableActivity.class);
								startActivity(r);

							} catch (Exception e) {
								Toast.makeText(getApplicationContext(), "" + e, Toast.LENGTH_LONG).show();
							}
						}
					});
					alertDialogBuilder.show();
				}
			});
		} catch (Exception e) {
			Toast.makeText(getApplicationContext(), "" + e, Toast.LENGTH_SHORT).show();
		}
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		// Take appropriate action for each action item click
		switch (item.getItemId()) {
		case R.id.action_logout:
			startActivity(new Intent(getApplicationContext(), LoginActivity.class));
			return true;
		default:
			return super.onOptionsItemSelected(item);
		}
	}

	@Override
	public boolean onPrepareOptionsMenu(Menu menu) {
		menu.findItem(R.id.action_mon).setVisible(false);
		menu.findItem(R.id.action_tue).setVisible(false);
		menu.findItem(R.id.action_wed).setVisible(false);
		menu.findItem(R.id.action_thu).setVisible(false);
		menu.findItem(R.id.action_fri).setVisible(false);
		return super.onPrepareOptionsMenu(menu);
	}
}
