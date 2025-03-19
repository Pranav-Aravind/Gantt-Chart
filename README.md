# Gantt-Chart

Creates a customized Gantt Chart designed to help users plan and manage tasks efficiently. It allows users to create a structured timeline, visualize dependencies, and make edits as needed.

## Main Program (main.c):
- Defines the structure of tasks.
- Handles user interaction.
- Calls functions to create and manage the Gantt chart.

## Function Prototypes (gantt.h):
- Lists all functions used in the program, including those for creating, printing, and editing tasks.
- Includes dependency-checking functions to ensure tasks are correctly linked.

## Function Implementations (gantt.c):
- **createGantt**: Allows users to define up to 10 tasks with names, start and end months, and dependencies.
- **printGantt**: Displays the Gantt chart as a table with task details and a monthly timeline.
- **menuEditTest**: Provides an interactive menu for editing tasks and checking dependencies.
- **editTask**: Enables modifications to task details such as names, dates, and dependencies.
- **testDependencies** & **printDependentTasks**: Help users analyze and verify task dependencies.
- **checkIfCircular**: Detects circular dependencies to prevent errors in task planning.

## Key Features:
- **Task Creation & Editing**: Users can add and modify tasks, adjusting details as needed.
- **Dependency Management**: Ensures task relationships are structured properly and prevents circular dependencies.
- **Clear Visualization**: Displays tasks in a structured table format for easy tracking.
- **User-Friendly Navigation**: Provides an interactive menu to guide users through task management.

This project offers a practical and efficient way to organize tasks, track progress, and manage dependencies in a structured timeline.
