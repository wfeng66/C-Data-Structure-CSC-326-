#include<stdlib.h>
#include<stdio.h>

int* divide(int len, int *s1, int *s2)
{
	s2 = &s1[len/2];
	return s2;
}


void main()
{
	int *s1, *s2, num = 10, i;
	s1 = (int*)malloc(10*sizeof(int));
	s2 = &num;
	for (i = 0; i < num; i++) *(s1 + i) = i + 1;
	printf("S1: \n");
	for (i = 0; i < num; i++) printf("%d\t", *(s1+i));
	s2 = divide(num, s1, s2);
	printf("\n\nS1: \n");
	for (i = 0; i < num/2; i++) printf("%d\t", *(s1 + i));
	printf("\n\nS2: \n");
	for (i = 0; i < num / 2; i++) printf("%d\t", *(s2 + i));
	system("pause");
}
