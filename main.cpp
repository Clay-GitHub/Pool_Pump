#include <iostream>
#include <string>
#include "swimmingPool.h"

using namespace std;

void menu();
int main ()
{

double length, width, depth, fillRate, drainRate;
char reply;
int choice;
int currentGal;
int time;

swimmingPool pool(length=0,width=0,depth=0,fillRate=0,drainRate=0);



cout << "What are the pool's length, width, and depth? "; 
cin >> length >> width >> depth;
pool.setDemensions(length, width, depth);

cout << "How fast does the pump fill up the pool in gallons per minute? ";
cin >> fillRate;
cout << "How fast does the pump drain the pool in gallons per minute? ";
cin >> drainRate;
pool.setRates(fillRate, drainRate);
cout << endl; 

menu();
cin >> choice;
while (choice != 10)
{
	switch (choice)
	{
		case 1:
			cout << endl << "Has the pool been partially filled up? (y/n) ";
			cin >> reply;
			cout << endl;
			switch (reply)
			{					
				case 'y':
					cout << "How many gallons are currently in the pool? ";
					cin >> currentGal; cout << endl;
					pool.printPartGalNeeded(currentGal); cout << endl;					
					pool.printPartFillTime(currentGal);
					break;

				case 'n':
					cout << "Calulate how much water would be in the pool after a certain amount of time? (y/n) ";
					cin >> reply;
					switch (reply)
					{ 
						case 'y':
							cout << "How many minutes filling the pool? ";
							cin >> time;
							pool.printTimedFillAmount(time);
							break;
						case 'n':
							pool.printGalNeeded(); cout << endl;
							pool.printFillTime();
							break;
					}
			}
			break;
		case 2:
			cout << endl << "Has the pool been partially drained? (y/n) ";
			cin >> reply; cout << endl;
			switch (reply)
			{					
				case 'y':
					cout << "How many gallons are currently in the pool? ";
					cin >> currentGal;	cout << endl;			
					pool.printPartDrainTime(currentGal);
					break;

				case 'n':
					cout << "Calculate how much water would be in the pool after draining a certain amount of time? (y/n) ";
					cin >> reply;
					switch (reply)
					{
						case 'y':
							cout << "How many minutes draining the pool? ";
							cin >> time;
							pool.printTimedDrainAmount(time);
							break;
						case 'n':
							pool.printDrainTime();
							break;
					}
			break;
			}
	}

	cout << endl << endl;
	cout << "Press ENTER to continue..." << endl;
	cin.ignore();
	cin.get();
	menu();
	cin >> choice;

}


return 0;
}


void menu()
{
	cout << "MAIN MENU" << endl;
	cout << "=-=-=-=-=-=-=-=-=-=-=" << endl
		 << "Please select an option" << endl
		 << "1  - Fill Information" << endl
		 << "2  - Drain Information" << endl << endl
		 << "10 - Exit" << endl;
	cout << "=-=-=-=-=-=-=-=-=-=-=" << endl;
	cout << "Option: " ;
}