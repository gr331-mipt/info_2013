/*
 * cpu.h
 *
 *  Created on: 15 нояб. 2013 г.
 *      Author: ALTAIR
 */

#ifndef CPU_H_
#define CPU_H_

#include "stack.h"

struct cpu;

typedef struct cpu CPU;

int CPU_run(char* file);

CPU* CPU_start();

int CPU_stop(CPU* cpu);

int CPU_load(CPU* cpu, char file[]);

int CPU_push(CPU* cpu, int Value);

int CPU_pop(CPU* cpu, Stack_Type* Value);

int CPU_add(CPU* cpu);

int CPU_mul(CPU* cpu);

int CPU_out(CPU* cpu);

void CPU_dump(CPU* cpu);

#endif /* CPU_H_ */
