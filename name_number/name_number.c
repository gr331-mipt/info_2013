/*
 * name_number.c
 *
 *  Created on: 09 сент. 2014 г.
 *      Author: ALTAIR
 */

#include <stdio.h>

void sayName(int n) {
	switch (n) {
	case 0: printf("Zero");
		break;
	case 1: printf("One\n");
		break;
	case 2: printf("Two\n");
		break;
	case 3: printf("Three\n");
		break;
	case 4: printf("Four\n");
		break;
	case 5: printf("Five\n");
		break;
	case 6: printf("Six\n");
		break;
	case 7: printf("Seven\n");
		break;
	case 8: printf("Eight\n");
		break;
	case 9: printf("Nine\n");
		break;
	default: printf("It's not digit\n");
	}
}

int main() {
	int digit;
	scanf("%d", &digit);
	while(digit < 10) {
		sayName(digit);
		scanf("%d", &digit);
	}
	return 0;
}
