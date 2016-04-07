package com.example.aleksandarx.myplaces;

import java.util.ArrayList;

/**
 * Created by aleksandarx on 4/7/16.
 */
public class MyPlacesData {
    private ArrayList<MyPlace> myPlaces;

    private MyPlacesData(){
        this.myPlaces = new ArrayList<>();
        myPlaces.add(new MyPlace("Place A"));
        myPlaces.add(new MyPlace("Place B"));
        myPlaces.add(new MyPlace("Place C"));
        myPlaces.add(new MyPlace("Place D"));
        myPlaces.add(new MyPlace("Place E"));
    }

    private static class singletonHolder {
        public static final MyPlacesData instance = new MyPlacesData();
    }

    public static MyPlacesData getInstance(){
        return singletonHolder.instance;
    }

    public ArrayList<MyPlace> getMyPlaces() {
        return myPlaces;
    }

    public void setMyPlaces(ArrayList<MyPlace> myPlaces) {
        this.myPlaces = myPlaces;
    }

    public void addNewPlace(MyPlace newPlace){
        this.myPlaces.add(newPlace);
    }

    public void removePlace(int index){
        this.myPlaces.remove(index);
    }
}
