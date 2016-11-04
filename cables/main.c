/*
 * main.c
 *
 *  Created on: 26 окт. 2013 г.
 *      Author: user
 */

int main(){
	int a[100][2];
	int n, k;
	scanf("%d %d", &n, &k);
	int i;
	long c;
	for(i = 0; i < n; i++){
		scanf("%d", &c);
		a[i][1] = c / k;
		a[i][2] = c % k;
	}
	return 0;
}
