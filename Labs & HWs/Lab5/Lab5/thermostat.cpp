#include "thermostat.h"

// definition of default constructor of thermostat class
// input: noon
// return: noon
// function: initialize members default value
thermostat::thermostat()
{
	swit = true;
	degree = 50;
	highD = 90;
	lowD = 50;
}

// definition of the second constructor of thermostat class
// input: switch status, degree, the high threshold value, the low threshold value
// return: noon
// function: initialize members 
thermostat::thermostat(bool s, int d, int h, int l)
{
	swit = s;
	degree = d;
	highD = h;
	lowD = l;
};

// definition of set function
// input: the degree need to set
// return: noon
// function: set the degree value as input value
void thermostat::set(int dg)
{
	if (dg >= lowD && dg <= highD) {		// check if the required value is in operating range
		if (swit == false) swit = true;		// if the switch status is off, turn it on 
		degree = dg;
		cout << "Setting sucess!" << endl;
	}
	else cout << "You input is beyond the scope of this thermostat, setting fale!" << endl;
}


// definition of change function
// input: the degree need to be changed
// return: noon
// function: increase or decrease the degrees basing on current degree, increase the degree if the inpute is positive, decrease the degrees if the input is negative
void thermostat::change(int ch)
{
	if (swit == false) {		// if the switch status is off, turn it on 
		swit = true;
		cout << "The thermostat is turned on!" << endl;
	}
	if ((degree + ch) >= lowD && (degree + ch) <= highD) {		// check if the end degree is in the operating range
		degree += ch;
		cout << "Changing success!" << endl;
	}
	else cout << "You input is beyond the scope of this thermostat, changing fale!" << endl;
}