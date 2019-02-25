#pragma once
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
	inline bool checkSwi();
	inline int checkDg();
	inline void turnoff();
	inline void turnon();
	void set(int);
	void change(int);
	void operator+(const int);
private:
	bool swit;
	int degree;
	int highD;
	int lowD;
};

inline bool thermostat::checkSwi(){ return swit; };
inline int thermostat::checkDg() { return degree; };
inline void thermostat::turnoff() { swit = false; cout << "It is turned off!\n"; }
inline void thermostat::turnon() { swit = true; cout << "It is turned on!\n"; }

#endif
