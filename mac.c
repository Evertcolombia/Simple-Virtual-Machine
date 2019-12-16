#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
 * pointer instructions for our program
 * or index for the arraye with the instrucrions of our program*/
int ip = 0;
bool running = true;
/*we need a stack pointer (sp) to show where 
 * we are in the stack array.*/
int sp = -1;

/*this array will be the stack*/
int stack[256];

/*Enumeration for the instrucctions of our program*/
typedef enum {
	PSH, /*Push n to the stack*/
	ADD, /*pops two values on top of the stack, add,them pushes*/
	POP, /*pops the value on the stack, will also print it for*/
	SET, /*sets register (eample = 'A' to 0)*/
	HLT  /*stop the program*/
} InstructonSet;

/*
 * test program as an array for a test*/
const int program[] = {
	PSH, 5,
	PSH, 6,
	ADD,
	POP,
	HLT
};

/*fetch function  to get the instructions 
 * we need*/
int fetch()
{
	return program[ip];
}

/*
 * Eval function will take the instruction to evaluate
 * and go through the switch case for each instruction
 * of the program
 */
void eval(int instr)
{
	switch (instr) {
		case HLT: {
			running = false;
			break;
		}
		case PSH: {
			sp++;
	      		stack[sp] = program[++ip];
			break;		
		}
		case POP: {
			/*store the value at the stack in 
		 	* val_popped THEN decrement the stack ptr*/
			int val_popped = stack[sp--];

			/*Print it out*/
			printf("popped %d\n", val_popped);
			break;
		}
	}
}

int main()
{
	int x;

	/*the program will keeps alive till the running being true*/
	while(running)
	{
		eval(fetch());
		ip++;
	}
}
