/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

void reverse(char* str, int start, int end){
	int i , j;
	for (i = start,j = end-1; i < j; i++,j--){
		char ch;
		ch = str[i];
		str[i] = str[j];
		str[j] = ch;
	}
}

void str_words_in_rev(char *input, int len){
	int f = 0,i = 0, start = 0, flag = 0;
	while(i < len){
		f = 0;
		if (input[i] == ' '){
			flag = 1;
			reverse(input, start, i);
			while (input[i] == ' '){
				i++;
			}
			start = i;
		}
		i++;
	}
	if(flag == 1){
		reverse(input, start, i);
		reverse(input, 0, len);
	}
}
