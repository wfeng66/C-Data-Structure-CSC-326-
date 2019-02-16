#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include <iostream>
using namespace std;

class thermostat
{
public:
	thermostat();			// default constructor
	thermostat(bool, int, int, int);
	~thermostat() {};
	inline bool checkSwi() { return swit; };
	inline int checkDg() { return degree; };
	inline void turnoff() { swit = false; cout << "It is turned off!\n"; };
	void set(int);
	void change(int);
private:
	bool swit;
	int degree;
	int highD;
	int lowD;
};

#endif