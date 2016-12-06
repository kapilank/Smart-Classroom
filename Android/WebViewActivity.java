package com.smart;


import android.annotation.SuppressLint;
import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.webkit.JavascriptInterface;
import android.webkit.WebView;
import android.widget.Toast;

@SuppressLint("SetJavaScriptEnabled")
public class WebViewActivity extends Activity {

	private WebView webView;

	public void onCreate(Bundle savedInstanceState) {
		try {
			super.onCreate(savedInstanceState);
			setContentView(R.layout.activity_webview);
			String url = getIntent().getExtras().getString("url");
			Toast.makeText(getApplicationContext(), "url:" + url, Toast.LENGTH_LONG).show();
			if (url != null) {
				webView = (WebView) findViewById(R.id.webView1);
				webView.loadUrl(url);
//				webView.getSettings().setJavaScriptEnabled(true);
//				webView.addJavascriptInterface(new WebViewJavaScriptInterface(this), "app");
			}
		} catch (Exception e) {
			Toast.makeText(getApplicationContext(), "Redirecting to Kit Server:" + e, Toast.LENGTH_LONG).show();
		}
	}

	public class WebViewJavaScriptInterface {

		private Context context;

		/*
		 * Need a reference to the context in order to sent a post message
		 */
		public WebViewJavaScriptInterface(Context context) {
			this.context = context;
		}

		/*
		 * This method can be called from Android. @JavascriptInterface required
		 * after SDK version 17.
		 */
		@JavascriptInterface
		public void makeToast(String message) {
			// Toast.makeText(context, message, (lengthLong ? Toast.LENGTH_LONG
			// : Toast.LENGTH_SHORT)).show();
			Toast.makeText(getApplicationContext(), message + " ", Toast.LENGTH_LONG).show();
			
		}
	}

}