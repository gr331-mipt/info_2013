/*
 * main.c
 *
 *  Created on: 13 дек. 2013 г.
 *      Author: ALTAIR
 */
/*#include <stdio.h>
#include "str.h"


int main() {
	char s[] = "String";
	strdel(s, 0 ,2);
	printf("%s", s);
	getchar();
	return 0;
}
*/
#include <stdio.h>

void test(int A[10])
{
	long sz = sizeof(A);
	printf("%lu\n", sz);
}

int main(void)
{
	int A[10] = {1, 3, 5};
	test(A);
	return 0;
}
