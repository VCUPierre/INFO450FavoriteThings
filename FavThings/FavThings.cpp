// FavThings.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Restaurant.h"
#include <iostream>
#include <fstream>
using namespace std;

const int TRACKERSIZE = 100;

void getURL(string &url);

int main()
{
	Restaurant **mytracker;
	int count = 0;
	string userURL;
	string response = "Y";

	mytracker = new Restaurant*[TRACKERSIZE];

	// read from a file - get recently saved restaurant
	getURL(userURL);

	ifstream infile(userURL);

	if (infile.good())
	{
		while (!infile.eof())
		{
			string name, type, fQuality, sQuality;
			getline(infile, name, '|');
			if (name.length())
			{
				getline(infile, type, '|');
				getline(infile, fQuality, '|');
				getline(infile, sQuality, '\n');
				mytracker[count] = new Restaurant(name, type, stoi(fQuality), stoi(sQuality));
				count++;
			}
		}
	}

	// enter more???
	cout << "Current number of Restaurants in tracker: " << count << " Add More? " << endl;
	cout << "Please use Y for yes and N for No" << endl;
	cin >> response;
	cin.ignore();
	cin.clear();


	// get inventory items from user
	while (response == "Y" || response == "y")
	{
		mytracker[count] = new Restaurant();
		if (mytracker[count]->newRestaurant() == 0)
			count++;

		cout << "Another one? (Y = yes and N = no)" << endl;
		cin >> response;
	}

	// now that we have array populated w/ object, show them
	for (int i = 0; i < count; i++)
	{
		mytracker[i]->displayRestaurant();
	}

	//Save to a File 
	ofstream outfile(userURL);
	if (!outfile.good())
	{
		cout << "ERROR - cant open file for output! " << endl;
		return -1;
	}
	// Use to print new restaurant to console
	for (int i = 0; i < count; i++)
	{
		outfile << mytracker[i];
	}

	// Cleaning up allocated space used for double pointer
	for (int i = 0; i < count; i++)
	{
		delete mytracker[i];
	}
	delete mytracker;

	return 0;
}
// a function that will capture path to tracker given from user.
void getURL(string &url) {
	cout << "Please enter a valid URL to the Tracker you would like to use." << endl;
	//cout << "Make sure to use \\\\ instead \\" << endl;
	getline(cin, url);
}

