/*
 * gantt.c
 *
 *  Created on: 22 feb 2024
 *      Authors: Federica Fucetola - 23922982
 *               Pranav Aravind - 23205030
 */

//Including all the libraries we will need, included our own library gantt.h
#include <stdio.h>
#include <string.h>
#include "gantt.h"

//Global variables and arrays that store the information that are in the struct to make the code cleaner and easier to write
int globalGanttStartMonths[10] = {1,2,2,3,4,4,4,5,10,11};
int globalGanttEndMonths[10]= {2,2,3,4,5,6,10,6,11,12};
int globalNumOfDependencies[10]={0,1,1,1,0,2,1,1,1,2};
int globalDependencies[10][10]={{0},{1},{1},{1},{0},{2,3},{4},{5},{6},{8,9}};
char globalTasksNames[10][40]={"Develop_project_plan","Hire_team_members","Market_research","Design_prototype","Finalize_budget","Organize_team_meetings","Develop_product","Secure_funding","Make_a_marketing_strategy","Launch_product"};
int numOfTasks=10;


/*
 * This struct is the base of each task
 * In the struct we can find the number, the name, the start and end month,
 * the number of dependencies and the actual dependencies of said task
 */
struct task{
	int taskId;
	char taskName[40];
	int startMonth;
	int endMonth;
	int numOfDepend;
	int dependencies[10];
};




/*
 * This function allow the user to create their own Gantt chart from scratch.
 * The method will ask to insert all the relevant information to fill out a table at the end of the function
 * The task inserted by the user will be printed at the end of the user's input
 * */
void createGantt()
{
	struct task newTask;
	printf("You're creating your Gantt from scratch\n");
	fflush(stdout);

	//The console asks how many tasks does the user want and asks infinitely until the answer is a number 0-10
	do{
		printf("How many task do you want to add? (max 10)\n");
		fflush(stdout);
		scanf("%d",&numOfTasks);
	}while(numOfTasks>10);

	/* In this for loop the console asks the user to input a name, a start and end month and the dependencies
	 * for 'number of tasks just entered' times*/
	for(int i=0;i<numOfTasks;i++)
	{
		printf("\nPlease enter the name of Task %d\n",i+1);
		fflush(stdout);

		scanf("%s",&newTask.taskName);
		fflush(stdout);
		strcpy(globalTasksNames[i],newTask.taskName);

		newTask.taskId=i+1;

		printf("\nEnter start month (1-12)\n");
		fflush(stdout);
		scanf("%d",&newTask.startMonth);
		globalGanttStartMonths[i]=newTask.startMonth;

		printf("\nEnter end month (1-12)\n");
		fflush(stdout);
		scanf("%d",&newTask.endMonth);
		globalGanttEndMonths[i]=newTask.endMonth;

		printf("\nHow many dependencies does this task have?\n");
		fflush(stdout);
		scanf("%d",&newTask.numOfDepend);
		globalNumOfDependencies[i]=newTask.numOfDepend;

		//This for loop allows the user to input the tasks which the current task is dependent to, for 'number of dependencies' times
		for(int j=0;j<newTask.numOfDepend;j++)
		{
			printf("\nEnter dependent task\n");
			fflush(stdout);
			scanf("%d",&newTask.dependencies[j]);
			globalDependencies[i][j]=newTask.dependencies[j];
		}

	}
	//At the end of the input this function will print a gantt chart with all the tasks that the user just inserted
	printGantt();
}




/*
 * This function prints out a table with all the task distributed on a one year time (from jan to dec)
 * Each task has a duration (the least you can input is one month) that is shown by filling the squares
 * of the months for which the task will last. After that there's a column that shows the dependencies of the task.
 * The task can be independent or it could rely on 1+ other tasks */
void printGantt()
{
	const char *str_months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	char *XXX = "XXX";
	char *null = "";
	char *header_dependencies = "Dependencies";


	for(int i = 0; i < 178; i++)
	{
		printf("_");
		fflush(stdout);
	}

	printf("\n%-25s", null);
	fflush(stdout);

	for(int i = 0; i < 12; i++)
	{
		printf("|%-10s", str_months[i]);
		fflush(stdout);
	}

	printf("|%-20s\n", header_dependencies);
	fflush(stdout);

	for(int i = 0; i < numOfTasks; i++)
	{
		for(int j = 0; j < 178; j++)
		{
			printf("-");
			fflush(stdout);
		}

		printf("\n%-25s",globalTasksNames[i]);
		fflush(stdout);

		for(int k = 0; k < 12 - (globalGanttEndMonths[i] - globalGanttStartMonths[i]); k++)
		{
			if(globalGanttStartMonths[i] == k + 1)
			{
				for(int m = 0; m < (globalGanttEndMonths[i] - globalGanttStartMonths[i] + 1); m++)
				{
					printf("|%-10s", XXX);
					fflush(stdout);
				}
			}
			else
			{
				printf("|%-10s", null);
				fflush(stdout);
			}
		}

		printf("|");
		fflush(stdout);
		for(int n=0;n<globalNumOfDependencies[i];n++)
		{
			printf("%d ", globalDependencies[i][n]);
			fflush(stdout);
		}
		printf("\n");
		fflush(stdout);
	}

	for(int i = 0; i < 178; i++)
	{
		printf("-");
		fflush(stdout);
	}

	fflush(stdout);
}




/*
 * This void function displays a menu with some choices that the user can make.
 * The user can decide to edit a task, check dependencies of a task or exit the menu.
 * After the user choose an option, the menu will redirect the program to the chosen function.
 * After the function is executed it will come back to the menu and ask for another input
 * until the user inputs 0 to exit the menu */
void menuEditTest()
{
	//Variable that will contain the user's choice
	int choice;
	//This while loop will show the menu until the user's choice is not 0
	do{
		printf("\n\n****\t\tCHOOSE AN OPTION\t\t****\n");
		fflush(stdout);
		printf("\t1. Edit a task\t\n");
		fflush(stdout);
		printf("\t2. Test dependencies \t\t\n");
		fflush(stdout);
		printf("****\t0. EXIT\t\t\t\t\t****\n");
		fflush(stdout);

		//This while loop will ask the user to insert a choice until the number of said choice is valid
		do{
			printf("\nInsert the number of your choice\n");
			fflush(stdout);
			scanf("%d",&choice);

		}while(choice>2);

		/*
		 * Depending on the choice of the user either a specific task will be edited or will be checked for circular dependency
		 * or else the program will exit the menu and will show the ascii art before terminating the whole program
		 */
		switch(choice)
		{
			case 1: editTask();
					break;
			case 2: testDependencies();
					break;
		}

	}while(choice!=0);

}




//This method allows the user to edit a task of their choice, either from the sample gantt or the one that they created themselves
void editTask()
{
	char editTask[40];
	printf("\nPlease enter the name of the task you wish to modify\n");
	fflush(stdout);
	scanf("%s",&editTask);

	for(int i=0; i<10;i++)
	{
		if(!(strcmp(editTask,globalTasksNames[i])))
		{
			printf("\nPlease enter the new name of the task or the old one (if you do not wish to change it)\n");
			fflush(stdout);
			scanf("%s",&globalTasksNames[i]);

			printf("\nEnter start month (1-12)\n");
			fflush(stdout);
			scanf("%d",&globalGanttStartMonths[i]);

			printf("\nEnter end month (1-12)\n");
			fflush(stdout);
			scanf("%d",&globalGanttEndMonths[i]);

			printf("\nHow many dependencies does this task have?\n");
			fflush(stdout);
			scanf("%d",&globalNumOfDependencies[i]);

			for(int j=0;j<globalNumOfDependencies[i];j++)
			{
				printf("\nEnter dependent task\n");
				fflush(stdout);
				scanf("%d",&globalDependencies[i][j]);
			}
		}
	}
	//Printing the results of the editing
	printGantt();
}



int taskId=0;
int visitedTasks[10]={0};
int resetVisitedTasks[10] = {0};
int checkTaskId;
int checkDependentTaskId;
int circular;



/*
 * This function checks whether a dependency set is circular or not
 * It checks the dependencies "tree" backwards: from the task which all the other depends on to the one inserted
 * This happens one "branch" at time*/
void checkIfCircular(int taskId, int dependentTaskId, int resetVisitedTasks[])
{
	taskId = checkTaskId;
	dependentTaskId = checkDependentTaskId;

    resetVisitedTasks[taskId] = 1;
    resetVisitedTasks[dependentTaskId] = 1;

   	//Iterating for the number of tasks we have
    for(int i = 0; i < numOfTasks; i++)
   	{
   		//Iterating for the number of dependencies that the task we want has
    	for(int j = 0; j < globalNumOfDependencies[taskId];j++)
   		{

    		if(globalDependencies[i][j] == taskId + 1)
   			{
   				taskId = i;
   			}

   			//else if the dependency of the task (numOfTasks - 1) in the position (globalNumOfDependencies[taskId] - 1) is not equal to the number (id) of the task it will continue
    		else if(globalDependencies[numOfTasks - 1][globalNumOfDependencies[taskId] - 1] != taskId + 1)
   			{
   				continue;
   			}

			//If the reset arrays of the dependent task has not been visited yet, there will be a recursive call to check its circularity
    		if(resetVisitedTasks[taskId] == 0)
			{
				checkIfCircular(taskId, dependentTaskId, resetVisitedTasks);
			}
    		//Else it will set the check variable "circular" to 1
			else
			{
				circular = 1;
			}
		}
	}

    //If the check var is 1 there's a circular dependency in the list of dependencies, if not then there isn't
	if(circular == 1)
	{
		printf("Circular dependency found\n\n");
	}

	else
	{
		printf("No circular dependency found\n\n");
	}

}




/*
 * This method prints the sequence of dependencies of a certain task and then calls the function to check if it's circular
 * This function prints the dependencies from the task inserted to the "root" task (where all the dependencies of inserted task start from)
 * This happens one "branch" at time
 */
void printDependentTasks(int taskId, int visitedTasks[])
{
	printf("%d -> ", taskId + 1);
	visitedTasks[taskId] = 1;

	//Iterating for the number of dependencies of a certain task (contained in globalNumOfDependencies[taskId])
	for(int i = 0; i < globalNumOfDependencies[taskId];i++)
	{
		//Going from current task to the one that it's dependent on (for example task 9 is dependent on task 6, so the dependentTaskId is set to 6)
		int dependentTaskId = globalDependencies[taskId][i]-1;

		//Calling recursively this same function to print the other tasks dependencies
		if(visitedTasks[dependentTaskId] == 0)
		{
			printDependentTasks(dependentTaskId, visitedTasks);
		}

		else
		{
			//Calling the function to check the circularity of a dependency
			printf("(!!!!!!!!!! warning potential circular dependency !!!!!!!!!!) \n");
			checkIfCircular(taskId, dependentTaskId, resetVisitedTasks);
		}
	}
}




//This function check the dependencies of a task, based on the name of said tasks
void testDependencies()
{
	int numOfTasks = 10;
	char checkDependencies[40];

	//Console asks the user to enter the name of the task they want to check
	printf("\nEnter the task name to check for circular dependencies\n");
	fflush(stdout);
	scanf("%s", &checkDependencies);

	//Checking if a task with a name equal to the one inserted exists (in the array with the tasks names). If it exists we take its index
	for(int i = 0; i < numOfTasks; i++)
	{
		if(!strcmp(checkDependencies,globalTasksNames[i]))
		{
			taskId = i;
			break;
		}
	}
	//Calling the function that will print the sequence of dependencies and check if it's circular
	printDependentTasks(taskId,visitedTasks);

}

