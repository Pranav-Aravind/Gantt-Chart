/*
 * gantt.h
 *
 *  Created on: 22 feb 2024
 *      Author: Federica Fucetola - 23922982
 *              Pranav Aravind - 23205030
 */


// function that makes the user create a Gantt from scratch
void createGantt();

//function that displays either the sample gantt or the gantt that the user creates
void printGantt();

// function with the menu layout that will make the user choose what action they want to perform
void menuEditTest();

// function that allows the user to edit one task
void editTask();

// function that ask for the task the user wants to check the dependencies of
void testDependencies();

// function that prints the sequence of dependencies of a given task
void printDependentTasks(int taskId, int visitedTasks[]);

//function that checks for circular dependencies of a task
void checkIfCircular(int taskId, int dependentTaskId, int resetVisitedTasks[]);

//function that prints out the Ascii Art at the end of the program
void asciiArt();


