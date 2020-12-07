#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;
/*
The purpose of the program is to prepare a report on guest's room charges.
By: Gianluca Venditti
Due: November 22, 2020
*/

int main()
{
	string name, roomType, roomName;
	double rate;
	double roomCharge;
	double totalRoomCharge = 0.0;
	string cpaTitle = "CPA Resort Hotel Room Charge";
	string guestNameTitle = "Guest Name";
	string roomTypeTitle = "Room Type";
	string numberDaysTitle = "# Days";
	string roomChargeTitle = "Room Charge";
	int numberDays;
	int counter = 0;
	ofstream fout("charges.dat");
	if (!fout.is_open())
	{
		cout << " error opening charges.dat" << endl;
		system("pause");
		exit(-1);
	}
	fout << fixed << setprecision(2);

	cout << "Enter name (or ctrl z to end):";
	getline(cin, name);
	while (!cin.eof())
	{
		cout << "Enter room type:";
		getline(cin, roomType);
		cout << "Enter number of days:";
		cin >> numberDays;

		if (roomType == "G" || roomType == "g")
		{
			rate = 125;
			roomName = "Garden View";
		}
		else if (roomType == "P" || roomType == "p")
		{
			rate = 145;
			roomName = "Pool View";
		}
		else
		{
			rate = 180;
			roomName = "Lake View";
		}

		roomCharge = rate * numberDays;
		totalRoomCharge += roomCharge;


		if (counter < 1)
		{
			fout << right << setw(45) << cpaTitle << endl << endl;
			fout << left << setw(25) << guestNameTitle;
			fout << setw(14) << roomTypeTitle;
			fout << setw(15) << numberDaysTitle;
			fout << right << setw(7) << roomChargeTitle << endl;
			fout << endl << endl;
			
		}
		counter++;
	        fout << left << setw(25) << name;
		    fout << setw(18) << roomName;
		    fout << setw(5) << numberDays;
		    fout << right << setw(17) << roomCharge;
		    fout << endl << endl << endl;
		
			cin.ignore(80, '\n');
		    cout << "Enter name (or ctrl z to end):";
		    getline(cin, name);
	}
	        fout << "Average Room Cost";
	        fout << right << setw(48) << totalRoomCharge / counter << endl << endl;
	        cout << endl << "Program ended successfully" << endl;
	        cout << endl << "Printout of charges.dat file" << endl << endl;
	        system("type charges.dat");
	        system("pause");

}
/*
Enter name (or ctrl z to end):Gianluca
Enter room type:G
Enter number of days:3
Enter name (or ctrl z to end):Jonathan
Enter room type:P
Enter number of days:5
Enter name (or ctrl z to end):^Z

Program ended successfully

Printout of charges.dat file

				 CPA Resort Hotel Room Charge

Guest Name               Room Type     # Days         Room Charge


Gianluca                 Garden View       3               375.00


Jonathan                 Pool View         5               725.00


Average Room Cost                                          550.00

Press any key to continue . . .
*/
