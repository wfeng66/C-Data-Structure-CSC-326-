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
thermostat::thermostat(bool s = true, int d = 50, int h = 90, int l = 50)
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
	if (dg >= lowD && dg <= highD) {					// check if the required value is in operating range
		if (!(this->checkSwi())) this->turnon();		// if the switch status is off, turn it on 
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
	if (!(this->checkSwi())) {		// if the switch status is off, turn it on 
		this->turnon();
		cout << "The thermostat is turned on!" << endl;
	}
	if ((degree + ch) >= lowD && (degree + ch) <= highD) {		// check if the end degree is in the operating range
		degree += ch;
		cout << "Changing success!" << endl;
	}
	else cout << "You input is beyond the scope of this thermostat, changing fale!" << endl;
}

void thermostat::operator+(const int d)
{
	if (!(this->checkSwi())) {		// if the switch status is off, turn it on 
		this->turnon();
		cout << "The thermostat is turned on!" << endl;
	}
	if ((degree + d) >= lowD && (degree + d) <= highD) {		// check if the end degree is in the operating range
		degree += d;
		cout << "Changing success!" << endl;
	}
	else cout << "You input is beyond the scope of this thermostat, changing fale!" << endl;
}
