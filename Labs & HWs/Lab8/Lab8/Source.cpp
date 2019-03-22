
#include <iostream>
using namespace std;

void DecToHex(int num);

int main()
{
	int num = 0;
	cout << "Welcome !!!" << endl;
	while (num != -9999) {
		cout << "Please input a decimal number: ";
		cin >> num;

		DecToHex(num);
		cout << endl << endl;
	}

	system("pause");
	return 1;
}

// iterative funciton, used to transfer decimal digits to hexadecimal digits
// input: the decimal number need to be transfered
// return: none
// ouput: print out the hexadecimal digit on console
void DecToHex(int num)
{
	int mod = num % 16;
	if (num > 0)
	{
		DecToHex(num / 16);
		switch (mod)
		{
		case 10:
			cout << 'A';
			break;
		case 11:
			cout << 'B';
			break;
		case 12:
			cout << 'C';
			break;
		case 13:
			cout << 'D';
			break;
		case 14:
			cout << 'E';
			break;
		case 15:
			cout << 'F';
			break;
		default:
			cout << mod;
			break;
		}
	}
}

