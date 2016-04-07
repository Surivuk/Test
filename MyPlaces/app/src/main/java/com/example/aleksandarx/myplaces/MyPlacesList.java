package com.example.aleksandarx.myplaces;

import android.content.Intent;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.ActionBarActivity;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewConfiguration;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.Toast;

import java.lang.reflect.Field;
import java.util.ArrayList;

public class MyPlacesList extends ActionBarActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        getOverflowMenu();
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_my_places_list);


        ListView myPlaces = (ListView)findViewById(R.id.my_places_list);
        myPlaces.setAdapter(new ArrayAdapter<>(this, android.R.layout.simple_list_item_1, MyPlacesData.getInstance().getMyPlaces()));
        
        myPlaces.setOnClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                parent.getAdapter().getItem(position);
            }
        });
        /*myPlaces.setOnClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                MyPlace place = (MyPlace) parent.getAdapter().getItem(position);
                Toast.makeText(getApplicationContext(), place.getName() + " selected", Toast.LENGTH_SHORT).show();
            }
        });*/

    }

    private void getOverflowMenu() {
        try {
            ViewConfiguration config = ViewConfiguration.get(this);
            Field menuKeyField = ViewConfiguration.class.getDeclaredField("sHasPermanentMenuKey");
            if(menuKeyField != null) {
                menuKeyField.setAccessible(true);
                menuKeyField.setBoolean(config, false);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.menu_my_places_list, menu);
        return super.onCreateOptionsMenu(menu);
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        int id = item.getItemId();

        if (id == R.id.show_map_item)
            Toast.makeText(this, "Show Map!", Toast.LENGTH_SHORT).show();
        if (id == R.id.new_place_item)
            Toast.makeText(this, "New Place!", Toast.LENGTH_SHORT).show();
        if (id == R.id.about_item){
            Intent i = new Intent(this, About.class);
            startActivity(i);
        }

        return super.onOptionsItemSelected(item);
    }
}
