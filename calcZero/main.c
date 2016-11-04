/*
 * main.c
 *
 *  Created on: 22 нояб. 2013 г.
 *      Author: ALTAIR
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define abs(a) ((a) < 0 ? -(a) : (a) )
#define ASSERT_OK(cond) \
		if(!(cond) && !UNCORRECT) { \
			printf("# ERROR EXPRESSION");\
			UNCORRECT = 1;\
		}

#define ASSERT_OK_MESSAGE(cond, message) \
		if(!(cond) && !UNCORRECT) { \
			printf("#%s", message);\
			UNCORRECT = 1;\
		}

char *S;
int UNCORRECT = 0;

double GetG();

double GetE();

double GetT();

double GetP();

double GetPow();

double GetRadical();

double GetN();

int main() {
	char s[1025];
	scanf("%s", s);
	S = s;
	double Answer = GetG();
	if(!UNCORRECT)
		printf("%lf", Answer);
	return 0;
}

double GetG() {
	//printf("\n#GetG()");
	double Val = GetE();
	if(*S == '\0')
		return Val;
	printf("# Error expression!!!\n");
	return 0;
}

double GetE() {
	//printf("\n#GetE()");
	double Val = GetT();
	while(*S == '+' || *S == '-') {
		char operator = *S;
		S++;
		double Val2 = GetT();
		ASSERT_OK(*S != *(S-1));
		switch( operator ) {
			case '+' : Val += Val2;
				break;
			case '-' : Val -= Val2;
				break;
		}
	}
	return Val;
}

double GetT() {
	//printf("\n#GetT()");
	double Val = GetPow();
	while(*S == '*' || *S == '/') {
		char operator = *S;
		S++;
		double Val2 = GetPow();
		ASSERT_OK(*S != *(S-1));
		switch( operator ) {
			case '*' : Val *= Val2;
				break;
			case '/' :
				ASSERT_OK_MESSAGE(Val2 != 0, "Devision by Zero");
				Val /= Val2;
				break;
		}
	}
	return Val;
}

double GetPow() {
	//printf("\n#GetPow()");
	double Val = GetRadical();
	while(*S == '^') {
		S++;
		double power = GetRadical();
		ASSERT_OK(*S != *(S-1));
		Val = pow(Val, power);
	}
	return Val;
}

double GetRadical() {
	double Val = GetP();
	if(*S == '#') {
		S++;
		double Val2 = GetP();
		ASSERT_OK(*S != *(S-1));
		if(Val != 0) {
			int sign = 1;
			if(Val2 < 0)
				sign = -1;
			Val = sign * pow(abs(Val2),(double) 1/Val);
		}
		else
			Val = sqrt(Val2);
	}
	return Val;
}

double GetP() {
	//printf("\n#GetP()");
	double Val;
	if(*S == '(') {
		S++;
		Val = GetE();
		if(*S == ')')
			S++;
	}
	else
		Val = GetN();
	return Val;
}

double GetN() {
	double Val = 0;
	int point_position = -1;
	while(('0' <= *S && *S <= '9') || *S == '.') {
		if(*S == '.') {
			if(point_position != -1)
				break;
			point_position = 0;
		}
		else {
			if(point_position != -1)
				point_position++;
			Val = Val * 10 + (*S - '0');
		}
		S++;
	}
	if(point_position != -1)
		Val *= pow(0.1 , point_position);
	return Val;
}
