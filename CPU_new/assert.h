/*
 * assert.h
 *
 *  Created on: 03 февр. 2014 г.
 *      Author: ALTAIR
 */

#ifndef ASSERT_H_
#define ASSERT_H_

#include <stdio.h>
#include <stdlib.h>

#define ASSERT(cond) \
	if(!cond) { \
		printf("%s file: %s line: %d", #cond, __FILE__, __LINE__);\
		abort();\
	}

#endif /* ASSERT_H_ */
