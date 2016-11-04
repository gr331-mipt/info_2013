#include <stdio.h>

int isLatin(char c) {
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return 1;
	return 0;
}

//3) Text begins and ends with Latin characters
int check(char *s) {
	int n;
	for (n = 0; s[n]; n++);
	if (n == 0)
		return 0;
	if (isLatin(s[0]) && isLatin(s[n-1]))
		return 1;
	return 0;
}

//4) Replace each lower-case letter with corresponding upper-case one
void rule1(char *s) {
	int i;
	for (i = 0; s[i]; i++)
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 'a' - 'A';
}

//1) Move all digits to beginning of text, saving order
void rule2(char *s) {
	int i, j;
	char c;
	if (s[0] == '\0')
		return;
	for (i = 1; s[i]; i++)
		if (s[i] >= '0' && s[i] <= '9') {
			//shift
			c = s[i];
			for (j = i - 1; j >= 0 && !(s[j] >= '0' && s[j] <= '9'); j--)
				s[j+1] = s[j];
			s[j+1] = c;
		}
}

int main(void) {
	char s[101];
	int n;
	fgets(s, sizeof s, stdin);
	for (n = 0; s[n]; n++); //n = strlen(s);
	if (n > 0)
		if (s[n-1] == '\n')
			s[n-1] = '\0';
	puts(s);
	if (check(s))
		rule1(s);
	else
		rule2(s);
	puts(s);
	return 0;
}
