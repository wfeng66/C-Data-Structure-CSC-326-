#include <iostream>
#include <math.h>
#include <time.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> &ranks) {
	// write your code in C++14 (g++ 6.2.0)
	int sum=0;
	for (int s : ranks){
		for (int sup : ranks){
			if (sup == s + 1) {
				sum++;
				cout << s << "\t" << sup << "\t" << sum << endl;
				break;
			}
		}
	}
	return sum;
}

void main(){


		int array[] = { 23, 5, -10, 0, 0, 321, 1, 2, 99, 30 };
		int elements = sizeof(array) / sizeof(array[0]);
		std::sort(array, array + elements);
		for (int i = 0; i < elements; ++i)
			std::cout << array[i] << ' ';
	
	system("pause");
}