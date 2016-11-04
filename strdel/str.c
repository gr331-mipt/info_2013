/*
 * str.c
 *
 *  Created on: 13 дек. 2013 г.
 *      Author: ALTAIR
 */

#include <stdlib.h>
#include <string.h>

void strdel(char *s, unsigned int idx, unsigned int count) {
	if(s != NULL && count > 0) {
		unsigned i;
		for(i = 0; i < idx && s[i] != '\0'; i++)
			;
		int len = strlen(s) - count;
		if(i == idx) {
			for( ; i <= len && len > 0; i++)
				s[i] = s[i + count];
			s[i] = '\0';
		}
	}
}
