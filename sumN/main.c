/*
 * main.c
 *
 *  Created on: 08 нояб. 2013 г.
 *      Author: ALTAIR
 */

int sumN (unsigned n, ...) {
	int* pN = &n;
	int sum = 0;
	unsigned i;
	for(i = 1; i <= n; i++) {
		sum += *(pN + i);
	}
	return sum;
}

/*int main() {
	printf("%d", sumN(2, 23, -7));
	return 0;
}
*/
