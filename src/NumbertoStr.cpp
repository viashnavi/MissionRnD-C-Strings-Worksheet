/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>

int length(char* str){
	int i;
	for (i = 0; str[i]; i++);
	return i;
}

void reverse(char* str,int start){
	int i = start, j = length(str) - 1;
	while (i<j){
		char ch = str[i];
		str[i] = str[j];
		str[j] = ch;
		i++;
		j--;
	}
}

void numberToString(int number, char*str,int start){
	int i = start;
	while (number > 0){
		str[i++] = (number % 10) + '0';
		number /= 10;
	}
	str[i] = '\0';
	reverse(str,start);
}

int multiply(float f, int num){
	float res = f;
	for (int i = 0; i<num; i++){
		res = res * 10;
	}
	return res;
}

void number_to_str(float number, char *str,int afterdecimal){
	if (number > 0){
		if (afterdecimal == 0){
			numberToString(number, str,0);
		}
		else{
			int nval = (int)number;
			float temp = (float)number - nval;
			int fval = multiply(temp, afterdecimal);
			numberToString(nval, str, 0);
			int l = length(str);
			str[l] = '.';
			numberToString(fval, str, l + 1);
		}
	}
	else{
		if (afterdecimal == 0){
			str[0] = '-';
			numberToString(number*-1, str, 1);
		}
		else{
			str[0] = '-';
			number *= -1;
			int nval = (int)number;
			float temp = (float)number - nval;
			int fval = multiply(temp, afterdecimal);
			numberToString(nval, str, 1);
			int l = length(str);
			str[l] = '.';
			numberToString(fval, str, l + 1);
		}
	}
}
