/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>

#include <malloc.h>

#define SIZE 31
int compare(char* str1, char* str2, int start1, int end1, int start2, int end2){
	int i, j;
	for (i = start1, j = start2; i < end1; i++, j++){
		if (str1[i] != str2[j]){
			return 0;
		}
	}
	return 1;
}

char ** commonWords(char *str1, char *str2) {
	if (str1 != NULL && str2 != NULL){
		char** res = (char**)malloc(sizeof(char*)* 5);
		int ptr = 0;
		for (int i = 0; i < 5; i++){
			res[i] = (char*)malloc(sizeof(char)*SIZE);
		}
		int flag = 0, i = 0, j = 0, start1 = 0, end1 = 0, start2 = 0, end2 = 0, f = 0;
		while (str1[i]){
			while (str1[i] == ' ' && str1[i] != '\0'){
				i++;
			}
			if (str1[i] == '\0' && flag == 0){
				return NULL;
			}
			flag = 1;
			start1 = i;
			while (str1[i] != ' ' && str1[i] != '\0'){
				i++;
			}
			end1 = i;
			j = 0;
			/*char *str1 = "the are all is well";
			char *str2 = " who what";
			*/
			while (str2[j]){
				while (str2[j] == ' ' && str2[j] != '\0'){
					j++;
				}
				if (str2[j] == '\0'){
					return res;
				}
				start2 = j;
				while (str2[j] != ' ' && str2[j] != '\0'){
					j++;
				}
				end2 = j;
				if ((end1 - start1) == (end2 - start2)){
					int l = compare(str1, str2, start1, end1, start2, end2);
					if (l == 1){
						f = 1;
						int k, m;
						for (m = 0, k = start1; k < end1; k++){
							res[ptr][m++] = str1[k];
						}
						res[ptr][m] = '\0';
						ptr++;
					}
				}

			}
		}
		if (f == 0)
			return NULL;
		return res;
	}
	return NULL;
}
