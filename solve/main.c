//{=================================================================================
//! @file    solve.c
//! @date    2013-11-16 19:03
//! @author  Panov Vladimir <volodka.1995@gmail.com>
//!
//! Решение квадратного уравнения с честным разбором частных случаев.
//!
//! @par     Условие задачи
//!          Программа вводит 3 коэффициента квадратного уравнения. Надо вывести
//!          количество его корней (-1 в случае бесконечного их к-ва) и сами корни.
//}=================================================================================

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DEBUG
//--------------------------------------------------------------------------
#ifdef DEBUG
#define assert(cond) \
if (!(cond)) {\
    printf("All gone bad: %s, file: %s, line: %d\n", #cond, __FILE__, __LINE__);\
    abort();\
    }
#else
#define assert(cond)
#endif //DEBUG

#define DBL_EPSILON 1e-8
#define ONE_SOLUTION 1
#define TWO_SOLUTION 2
#define MANY_SOLUTIONS 3
#define NO_SOLUTION -1

#define IS_ZERO(x) (-DBL_EPSILON < x && x < DBL_EPSILON)
#define IS_BELOW_ZERO(x) (x < -DBL_EPSILON)

//{=================================================================================
//! LineSolve - solve a linear equation specified by its coefficients.
//!
//! @param      b   Equation b-coefficient X
//! @param      c   Equation c-coefficient free
//! @param[out] x   1st root of equation, if exist (if not, value will be unchanged)
//!
//! @return         Number of roots or zero if none, -1 if infinite number of roots
//!
//! @note           Calculation precision is considered to be DBL_EPSILON.
//}=================================================================================
int LineSolve( const double b, const double c, double* x) {
	assert(x != NULL);
	if( ! IS_ZERO(b)) {
		*x = -c / b;
		return ONE_SOLUTION;
	}
	else{
		if(! IS_ZERO(c)) {
			return NO_SOLUTION;
		}
		else {
			return MANY_SOLUTIONS;
		}
	}
}

//{=================================================================================
//! SquareSolve - solve a square equation specified by its coefficients.
//!
//! @param      a   Equation a-coefficient
//! @param      b   Equation b-coefficient
//! @param      c   Equation c-coefficient
//! @param[out] x1  1st root of equation, if exist (if not, value will be unchanged)
//! @param[out] x2  2nd root of equation, if exist (if not, value will be unchanged)
//!
//! @return         Number of roots or zero if none, -1 if infinite number of roots
//!
//! @note           Calculation precision is considered to be DBL_EPSILON.
//}=================================================================================
int SquareSolve( const double a, const double b, const double c, double* x1, double* x2) {
	assert(x1 != NULL);
	assert(x2 != NULL);
	assert(x1 != x2);
	double D = b * b - 4 * a * c;
	if( IS_BELOW_ZERO(D)) {
		return NO_SOLUTION;
	}
	else {
		if( IS_ZERO(D) ) {
			*x1 = -b / (2 * a);
			return ONE_SOLUTION;
		}
		else {
			*x1 = (-b + sqrt( D )) / (2 * a);
			*x2 = (-b - sqrt( D )) / (2 * a);
			return TWO_SOLUTION;
		}
	}
}

//{=================================================================================
//! read - Read number from string.
//!
//! @param[out]    *num	Number to read
//!
//! @note           Read strings while it isn't double.
//}=================================================================================
int read(double *num){
	assert(num != NULL);
	char s[100] = "";
	int Complite = 0;
	do{
		scanf("%s", s);
		Complite = sscanf(s, "%lf", num);
		if(Complite == 0)
			printf("\n#Input ERROR. Enter number!!!\n");
	}while(Complite == 0);
	return 0;
}

int main(int argc, char* argv[]) {
	double a = 0;
	double b = 0;
	double c = 0;
	double x1 = 0;
	double x2 = 0;
	int Solutions = 0;
	char ScanfComplite = 0;
	char TerminalScanf = 0;
	if( argc == 4) {
		ScanfComplite += sscanf(argv[1], "%lg", &a);
		ScanfComplite += sscanf(argv[2], "%lg", &b);
		ScanfComplite += sscanf(argv[3], "%lg", &c);
		if(ScanfComplite == 3)
			TerminalScanf = 1;
		else
			printf("# console input error\n");
	}
	if(! TerminalScanf){
		printf("# Input: \n");
		read( &a);
		read( &b);
		read( &c);
	}
	if( IS_ZERO(a) )
		Solutions = LineSolve( b, c, &x1);
	else
		Solutions = SquareSolve( a, b, c, &x1, &x2);
	if(Solutions == NO_SOLUTION)
		printf("\n#There is no solutions at all\n %d \n", NO_SOLUTION);
	else
		printf("\n# Solution number:\n %d \n", Solutions);
	switch( Solutions ){
		case ONE_SOLUTION:
			printf("# Value:\n %lf\n", x1);
			break;
		case TWO_SOLUTION:
			printf("# Value:\n %lf %lf\n", x1, x2);
			break;
	}
	return 0;
}
