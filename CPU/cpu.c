/*
 * cpu.c
 *
 *  Created on: 15 нояб. 2013 г.
 *      Author: ALTAIR
 */

#include "cpu.h"
#include <string.h>
#include <time.h>
#include "list.h"
#include "stack.h"

#define ASSERT_CPU_OK(cpu) \
	if(cpu == NULL) {\
		printf("CPU error! line:%d", __LINE__);\
		abort();\
	}

#define REG_AX 0

#define COM_PUSH 1
#define COM_ADD  2
#define COM_MUL  3
#define COM_OUT  4
#define COM_JUMP 5

struct cpu {
	List* Commands;
	int reg[1];
	/*
	 * [0] - ax
	 */
	stack* Numbers;
};

int CPU_run(char file[]) {
	dump_printf("/**********************************CPU START******************************\\");
	printf("# CPU is started...\n");
	CPU* cpu = CPU_start();
	CPU_dump(cpu);
	printf("# CPU is running...\n");
	CPU_load(cpu, file);
	//list_dump(cpu->Commands, 1);
	CPU_dump(cpu);
	CPU_stop(cpu);
	printf("# CPU is stopped.");
	return 0;
}

CPU* CPU_start() {
	CPU* cpu = (CPU*) calloc(1, sizeof(cpu));
	cpu->Commands = NULL;
	cpu->reg[REG_AX] = 0xBAD;
	cpu->Numbers = NULL;//Stack_Initialize();
	return cpu;
}

int CPU_stop(CPU* cpu) {
	ASSERT_CPU_OK(cpu);
	dump_printf("#stop");
	Stack_Destroy((cpu->Numbers));
	dump_printf("#Numbers deleted\n");
	list_destroy(&(cpu->Commands));
	dump_printf("#Commands deleted\n");
	//free(cpu);
	dump_printf("#CPU deleted\n");
	printf("#time : %d\n",(int) clock());
	return 0;
}

int CPU_load(CPU* cpu, char file[]) {
	ASSERT_CPU_OK(cpu);
	printf("file: %s", file);
	FILE* file_in = fopen(file, "r");
	//ASSERT(file_in != NULL);
	if(file_in != NULL) {
		char command[10];
		char str_com[10];
		char num_str[sizeof(Stack_Type)];
		while(fgets(command, sizeof(command), file_in)) {
			sscanf(command, " %s", str_com);
			if(str_com[0] == ':') {
				printf("#ToJUMP");
				List_type jump;
				sscanf(&str_com[1], "%d", &jump);
				list_add_jump(&(cpu->Commands), jump);
			}
			if(!strcmp(str_com, "push")) {
				if(sscanf(&command[strlen(str_com)], " %s", num_str)){
					printf("#PUSH");
					list_push(&(cpu->Commands), strtod(num_str, NULL));
					//CPU_push(cpu,strtod(num_str, NULL));
				}
			}
			if(!strcmp(str_com, "add")) {
				printf("#ADD");
				//CPU_add(cpu);
				list_add_command(&(cpu->Commands), COM_ADD);
			}
			if(!strcmp(str_com, "mul")) {
				printf("#MUL");
				//CPU_mul(cpu);
				list_add_command(&(cpu->Commands), COM_MUL);
			}
			if(!strcmp(str_com, "out")) {
				printf("#OUT");
				//CPU_out(cpu);
				list_add_command(&(cpu->Commands), COM_OUT);
			}
			if(!strcmp(str_com, "jb")) {
				printf("#JB");
				List_type jump;
				if(sscanf(&command[strlen(str_com)], " %d", &jump))
				list_add(&(cpu->Commands), COM_JUMP, jump, COMMAND);
			}
		}
		fclose(file_in);
	}
	else {
		perror("CPU_load");
		return -1;
	}
	ASSERT_CPU_OK(cpu);
	return 0;
}

int CPU_push(CPU* cpu, int Value) {
	ASSERT_CPU_OK(cpu);
	Stack_Push(&cpu->Numbers, Value);
	return 0;
}

int CPU_pop(CPU* cpu, Stack_Type *Value) {
	ASSERT_CPU_OK(cpu);
	return Stack_Pop(&(cpu->Numbers), Value);
}

int CPU_add(CPU* cpu) {
	ASSERT_CPU_OK(cpu);
	Stack_Type a, b;
	int pop_complite = 0;
	pop_complite += CPU_pop(cpu, &a);
	pop_complite += CPU_pop(cpu, &b);
	if(pop_complite == 2) {
		CPU_push(cpu, a + b);
	}
	return pop_complite;
}

int CPU_mul(CPU* cpu) {
	ASSERT_CPU_OK(cpu);
	Stack_Type a, b;
	int pop_complite = 0;
	pop_complite += CPU_pop(cpu, &a);
	pop_complite += CPU_pop(cpu, &b);
	if(pop_complite == 2) {
		CPU_push(cpu, a * b);
	}
	return pop_complite;
}

int CPU_out(CPU* cpu) {
	ASSERT_CPU_OK(cpu);
	Stack_Type Value;
	CPU_pop(cpu, &Value);
	CPU_push(cpu, Value);
	printf("# OUT: \n%lf\n", Value);
	return 1;
}

void CPU_dump(CPU* cpu) {
	dump_printf("#CPU commands :\n");
	list_dump(cpu->Commands, 1);
	dump_printf("#CPU memory :\n");
	Stack_Dump(cpu->Numbers);
	dump_printf("#CPU reg :\n");
	printf("REG_AX : %d", cpu->reg[REG_AX]);
}
