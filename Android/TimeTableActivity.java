package com.smart;

import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.OutputStream;
import java.io.StreamCorruptedException;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.URL;
import java.net.URLConnection;
import java.net.UnknownHostException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Properties;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import com.serverconnection.ServerConnection;
import android.app.Activity;
import android.app.AlertDialog;
import android.app.Dialog;
import android.app.Notification;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.app.ProgressDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.SharedPreferences.Editor;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.media.RingtoneManager;
import android.media.ThumbnailUtils;
import android.net.Uri;
import android.os.AsyncTask;
import android.os.Build;
import android.os.Bundle;
import android.os.Handler;
import android.os.StrictMode;
import android.provider.MediaStore.Images.Thumbnails;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.ListView;
import android.widget.ProgressBar;
import android.widget.TextView;
import android.widget.Toast;

public class TimeTableActivity extends Activity {
	Button btnEmail;
	ProgressDialog dialog, mProgressDialog;
	ServerConnection conn = new ServerConnection();
	Boolean serverHandlerStatus = true;
	TextView tv_serverStatus;
	String fileName;
	int totalMessages = 0;
	AlertDialog.Builder alertDialogBuilder;
	ListView listViewEmail;
	String items[];

	String shop;
	HashMap<String, String> periodsMap = new HashMap<String, String>();

	public void onCreate(Bundle savedInstancestate) {
		super.onCreate(savedInstancestate);
		try {
			setContentView(R.layout.activity_time_table);
			listViewEmail = (ListView) findViewById(R.id.listViewEmails);
			tv_serverStatus = (TextView) findViewById(R.id.textViewStatus);
			tv_serverStatus.setText("Day : Monday");
			if (MainApplication.STAFF_DEPT.equalsIgnoreCase("ECE")) {
				String response = ServerConnection.serverCall("TimeTableEce", "dept=" + MainApplication.STAFF_DEPT);
				for (String value : response.split("@@")) {
					periodsMap.put(value.split("=")[0], value.split("=")[1]);
				}
			} else {
				String response = ServerConnection.serverCall("TimeTableIt", "dept=" + MainApplication.STAFF_DEPT);
				for (String value : response.split("@@")) {
					periodsMap.put(value.split("=")[0], value.split("=")[1]);
				}
			}

			new Post().setPost("monday");
		} catch (Exception e) {
			showToast("" + e);
		}
	}

	/** Show Toast */
	private void showToast(String msg) {
		Toast.makeText(getApplicationContext(), msg, Toast.LENGTH_SHORT).show();
	}

	public class Post {
		public void setPost(String day) {
			try {
				showToast(day);
				List<String> itemList = new ArrayList<String>();
				List<EmailRowItems> rowItems = new ArrayList<EmailRowItems>();
				if (periodsMap.containsKey(day)) {
					String periods = periodsMap.get(day);
					int count = 1;
					for (String period : periods.split("@")) {
						itemList.add("Period " + count + "@" + period);
						count++;
					}

				}
				for (String pdt : itemList) {
					EmailRowItems item = new EmailRowItems(pdt.split("@")[0], pdt.split("@")[1], "");
					rowItems.add(item);
				}
				ListViewAdapter adapter = new ListViewAdapter(getApplicationContext(), R.layout.shop_name_list_item,
						rowItems);
				listViewEmail.setAdapter(adapter);
				listViewEmail.setOnItemClickListener(new AdapterView.OnItemClickListener() {
					public void onItemClick(AdapterView<?> parent, final View view, int position, long id) {
						try {
							// String post = itemList.get(position);
							// Intent intt=new Intent(getApplicationContext(),
							// Purchase_Product.class);
							// intt.putExtra("purchase", post);
							// startActivityForResult(intt, 2);
						} catch (Exception e) {
							Toast.makeText(getApplicationContext(), "onclick:" + e, Toast.LENGTH_SHORT).show();
						}
					}
				});
			} catch (Exception e) {
				Toast.makeText(getApplicationContext(), "Email exe:" + e, Toast.LENGTH_SHORT).show();
			}
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
		case R.id.action_mon:
			tv_serverStatus.setText("Day : Monday");
			new Post().setPost("monday");
			return true;
		case R.id.action_tue:
			tv_serverStatus.setText("Day :Tuesday");
			new Post().setPost("tuesday");
			return true;
		case R.id.action_wed:
			tv_serverStatus.setText("Day : Wednesday");
			new Post().setPost("wednesday");
			return true;
		case R.id.action_thu:
			tv_serverStatus.setText("Day : Thursday");
			new Post().setPost("thursday");
			return true;
		case R.id.action_fri:
			tv_serverStatus.setText("Day : Friday");
			new Post().setPost("friday");
			return true;
		default:
			return super.onOptionsItemSelected(item);
		}
	}

	@Override
	public boolean onPrepareOptionsMenu(Menu menu) {

		return super.onPrepareOptionsMenu(menu);
	}
}
