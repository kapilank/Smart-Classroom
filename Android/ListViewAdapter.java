package com.smart;

import java.io.File;
import java.util.List;

import android.app.Activity;
import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.TextView;

public class ListViewAdapter extends ArrayAdapter<EmailRowItems> {

	Context context;

	public ListViewAdapter(Context context, int resourceId, List<EmailRowItems> items) {
		super(context, resourceId, items);
		this.context = context;
	}

	/* private view holder class */
	private class ViewHolder {

		TextView txtFrom, txtSub, txtMsg, txtAttachment;

	}

	public View getView(int position, View convertView, ViewGroup parent) {
		ViewHolder holder = null;
		EmailRowItems rowItem = getItem(position);

		LayoutInflater mInflater = (LayoutInflater) context.getSystemService(Activity.LAYOUT_INFLATER_SERVICE);
		if (convertView == null) {
			convertView = mInflater.inflate(R.layout.shop_name_list_item, null);
			holder = new ViewHolder();
			holder.txtFrom = (TextView) convertView.findViewById(R.id.textViewFrom);
			holder.txtSub = (TextView) convertView.findViewById(R.id.textViewSubject);
			holder.txtMsg = (TextView) convertView.findViewById(R.id.textViewMessage);
			convertView.setTag(holder);
		} else {
			holder = (ViewHolder) convertView.getTag();
		}
		holder.txtFrom.setText(rowItem.getFrom());
		holder.txtSub.setText(rowItem.getSubject());
		holder.txtMsg.setText(rowItem.getMessage());
		return convertView;
	}

}
