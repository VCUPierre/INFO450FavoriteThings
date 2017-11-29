#include "stdafx.h"
#include "Restaurant.h"
#include <string>
#include <iostream>
#include <fstream>


using namespace std;


Restaurant::Restaurant() {
	//default construct
}
Restaurant::Restaurant(string n, string t, int fq, int sq) {
	name = n;
	type = t;
	fQuality = fq;
	sQuality = sq;
}
int Restaurant::newRestaurant() {
	cout << "Restaurant name? " << endl;
	getline(cin, name);
	cout << "What type of restaurant is " << name << "?" << endl;
	getline(cin, type);
	cout << "Food rating? (1 - 10 scale)" << endl;
	cin >> fQuality;
	cin.ignore();	//clears cin input buffer
	cin.clear();
	cout << "What would you rate the overall service? (1 - 10 scale)" << endl;
	cin >> sQuality;
	cin.ignore();	//clears cin input buffer
	cin.clear();

	return 0;
}
void Restaurant::displayRestaurant() {

	cout << "** New Restaurant **" << endl;
	cout << "Resturant name: " << name << endl;
	cout << "Resturant type: " << type << endl;
	cout << "Food Quality rating: " << fQuality << endl;
	cout << "Overall Service rating: " << sQuality << endl;

}

ofstream& operator<<(ofstream &fs, Restaurant *FavThing) {

	fs << FavThing->name << "|" << FavThing->type << "|" << FavThing->fQuality << "|" << FavThing->fQuality << endl;
	return fs;
}