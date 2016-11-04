/*
 * main.c
 *
 *  Created on: 13 дек. 2013 г.
 *      Author: ALTAIR
 */

struct types {
	char chr;
	short sht;
	int itg;
	long lng;
	float flt;
	double dbl;
	long double ldb;
	char ptr;
};

struct types type_sizes() {
	struct types type;
	type.chr = sizeof(char);
	type.sht = sizeof(short);
	type.itg = sizeof(int);
	type.lng = sizeof(long);
	type.flt = sizeof(float);
	type.dbl = sizeof(double);
	type.ldb = sizeof(long double);
	type.ptr = sizeof(char*);
	return type;
}
