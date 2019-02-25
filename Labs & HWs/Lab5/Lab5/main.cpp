#include "thermostat.h"


int main()
{	
	thermostat *thm = new thermostat;		// initialize a thermostat
	thm->turnoff();				// turn it off
	// print the state of thermostat on or not
	if (thm->checkSwi()) cout << "The thermostat is on now!" << endl;
	else cout << "The thermostat is off now!" << endl << endl;

	// set the degree
	thm->set(101);
	thm->set(51);
	// print the state of thermostat that is on or not
	if (thm->checkSwi()) cout << "The thermostat is on now!" << endl;
	else cout << "The thermostat is off now!" << endl << endl;

	thm->set(76);				// set the degree to 76
	cout << "The degree of thermostat is " << thm->checkDg() << " degree." << endl << endl;

	*thm + 2;					// raise by 2 degree 
	cout << "The degree of thermostat is " << thm->checkDg() << " degree." << endl << endl;
	// print the state of thermostat that is on or not
	if (thm->checkSwi()) cout << "The thermostat is on now!" << endl;
	else cout << "The thermostat is off now!" << endl << endl;

	thm->change(-8);				// lower by 8 degree
	cout << "The degree of thermostat is " << thm->checkDg() << " degree." << endl << endl;

	thm->turnoff();
	// print the state of thermostat that is on or not
	if (thm->checkSwi()) cout << "The thermostat is on now!" << endl;
	else cout << "The thermostat is off now!" << endl;

	system("pause");
	return 0;
}

