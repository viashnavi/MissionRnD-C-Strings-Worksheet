/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/

void remove_spaces(char* str, int start, int end){
	int i, j;
	for (i = start, j = end; str[j]; i++, j++){
		str[i] = str[j];
	}
	str[i] = '\0';
}

char removeSpaces(char *str) {
	if (str != '\0' && str != ""){
		int i = 0, start = 0;
		while (str[i]){
			if (str[i] == ' '){
				start = i;
				i++;
				while (str[i] == ' ' && str[i]!='\0'){
					i++;
				}
				remove_spaces(str, start, i);
				i = start;
			}
			i++;
		}
	}
	return '\0';
}