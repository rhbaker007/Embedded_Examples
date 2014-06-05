/*
 * NAME: Ronald Baker & Michael Au
 * CLASS: CSE 321: Real-Time Embedded Systems
 * ASSIGNMENT: Schedule 
 * PURPOSE: Implemment Cyclic Periodic Task Schedule 
 */

#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <clock.h>
#include <shell.h>
#include <kernel.h>
#include <semaphore.h>
#define SLOTX 6
#define CYCLEX 4


/* The definitions for the function used in the code
 */
void t_1(void);
void t_2(void);
void t_3(void);
void burn(void);
void(*ttable[SLOTX][CYCLEX])(void); 
   
/* Integers defined 
 */
int slot = 0; 
int cycle = 0; 

/* 
 */
semaphore s_Burn; 

/* Task that need to be executed for the project. 
   The following functions include t_1, t_2, t_3, and burn.
 */
 
void t_1(){
 	fprintf(stdout,"Task 1 running\n");
  	sleep(1000);
}
void t_2(){
  	fprintf(stdout,"Task 2 running\n");
  	sleep(1000);
}
void t_3() {
 	fprintf(stdout,"Task 3 running\n");
  	sleep(1000);
}
void burn(void) {
	ulong present, future, wait, clocktime, now; 
	present = clocktime; 
	fprintf(stdout, "Burn.\n"); 
	sleep(1);
	future = clocktime;
	wait = (future - now); 
	wait = wait*1000; 
	fprintf(stdout, "Elasped time is: %dms.\n", wait);   
}

/* The scheduling from the given chart
*/

void (*ttable[SLOTX][CYCLEX])(void) = 
{
	{t_1, t_1, t_2, t_2},
	{t_3, t_3, t_3, t_3},
	{t_2, t_2, t_1, t_1},
	{t_3, t_3, t_3, t_3},
	{t_2, t_2, t_1, t_1},
	{t_2, t_2, burn, burn}
};
 
shellcmd xsh_schedule(int nargs, char *args[]) 
{
 
	while(1)
	{

/*This portion of the code will run through the timing diagram
 */
		for(slot = 0; slot<SLOTX; slot++)
		{
			for(cycle = 0; cycle<CYCLEX; cycle++)
			{
				ready(create((void*)(*ttable[SLOTX][CYCLEX]), INITSTK, INITPRIO,"schedule", 
				0), RESCHED_NO);
				sleep(1000); 
			}
			sleep(1000); 
		} 	
	}
	return 0; 
}
