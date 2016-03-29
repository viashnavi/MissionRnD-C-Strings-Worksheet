/*
OVERVIEW: Given a string, return the letter at Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the letter at Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/

int length1(char* str){
	int i;
	for (i = 0; str[i]; i++);
	return i;
}

char KthIndexFromEnd(char *str, int K) {
	if (str != "" && str != '\0'){
		int len = length1(str);
		if ((K >= len) || (K < 0)){
			return '\0';
		}
		return str[len - K - 1];
	}
	return '\0';
}