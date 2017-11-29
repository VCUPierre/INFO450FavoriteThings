#pragma once
#include "stdafx.h"
#include <string>

using namespace std;

class Restaurant
{
private:
	string name;
	string type;	//type of restaurant
	int fQuality;	//food quality
	int sQuality;	//Service quality

public:
	Restaurant();
	Restaurant(string n, string t, int fq, int sq);
	int newRestaurant();
	void displayRestaurant();

	friend ofstream& operator<<(ofstream &fs, Restaurant *item);

};