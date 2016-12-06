package com.smart;

import java.io.IOException;
import java.io.InputStream;
import java.net.MalformedURLException;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;

public class EmailRowItems {
	// private int imageId;
	public String from, subject, message;

	public String getFrom() {
		return from;
	}

	public String getSubject() {
		return subject;
	}

	public String getMessage() {
		return message;
	}
	
	public EmailRowItems(String from, String subject, String message) {
		this.from = from;
		this.subject = subject;
		this.message = message;
		
	}

}
