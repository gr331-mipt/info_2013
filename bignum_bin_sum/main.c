/*
 * main.c
 *
 *  Created on: 21 февр. 2014 г.
 *      Author: ALTAIR
 */

#include <stdio.h>
#include <string.h>

char *sum(char *a, char *b) {
	int dl = strlen(a) - strlen(b);
	if(dl < 0) {
		char *w = a;
		a = b;
		b = w;
		dl = -dl;
	}
	int i;
	char buf = 0;
	for(i = strlen(a) - 1; i >= 0; i--) {
		if(0 <= i - dl)
			a[i] += (b[i - dl] - '0');
		a[i] += buf;
		buf  = (a[i] - '0') / 2;
		a[i] = (a[i] - '0') % 2 + '0';
	}
	for(i = 0; a[i] != '1' && a[i] != '\0'; i++);
	if(!a[i] && i > 0)
		return a + i - 1;
	return a+i;
}

int main() {
	char a[1003] = "0";
	char b[1003] = "0";
	scanf("%s", a + 1);
	scanf("%s", b + 1);
	printf("%s\n", sum(a, b));
	return 0;
}
