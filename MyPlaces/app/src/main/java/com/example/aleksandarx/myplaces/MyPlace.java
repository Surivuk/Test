package com.example.aleksandarx.myplaces;

import android.widget.Adapter;

/**
 * Created by aleksandarx on 4/7/16.
 */
public class MyPlace {

    private String name;
    private String description;


    public MyPlace(String name, String description){
        this.name = name;
        this.description = description;
    }

    public  MyPlace(String name){
        this(name, "");
    }

    public String getDescription() {
        return description;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    @Override
    public String toString() {
        return name;
    }
}
