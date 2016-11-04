#include <stdio.h>

int p(int n) {
	if( n <= 2)
		return 1;
	int res = 0;
	int i = 0;
	for(i = n; i >= n/2; i--) {
		res = p(i)*p(n - i) + 1;
	}
	return res;
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d", p(n));
	return 0;
}
