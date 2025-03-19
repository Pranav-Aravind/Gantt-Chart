/*
 * main.c
 *
 *  Created on: 22 feb 2024
 *      Authors: Federica Fucetola - 23922982
 *               Pranav Aravind - 23205030
 */

//Including all the libraries we will need, included our own library gantt.h
#include <stdio.h>
#include <string.h>
#include "gantt.h"

/*
 * This struct is the base of each task
 * In the struct we can find the number, the name, the start and end month, the number of dependencies and the actual dependencies of said task
 */
struct task{
	int taskId;
	char taskName [40];
	int startMonth;
	int endMonth;
	int numOfDepend;
	int dependencies[10];
};


int main()
{
	//Variable that contains the choice of the user
	char choice[4];

	//Initial interface that is shown to the user
	printf("Welcome to the Gantt Generator\n\n");
	fflush(stdout);

	//The interface asks the user whether they would like to create a Gantt on their own or use the one we already prepared for them
	printf("Would you like to use the test sample or create your own Gantt from scratch?\n");
	fflush(stdout);
	printf("Type 'yes' to use the sample or 'no' to create your own Gantt: ");
	fflush(stdout);
	fgets(choice,4, stdin);

	/* According to the user choice some function are called:
	 * One function prints out a sample (ready to use) Gantt chart
	 * The other function let the user create their own Gantt chart from scratch
	 */
	if(strcmp(choice,"yes")==0)
		printGantt();
	else
		createGantt();

	//After the user has a gantt they can choose what to do next from a menu
	menuEditTest();

	//This function shows our group's signature ascii art
	asciiArt();


	printf("\nTHIS PROGRAM HAS ENDED\n");
	fflush(stdout);

	return 0;
}

