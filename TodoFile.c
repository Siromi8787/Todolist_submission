#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 10
#define MAX_LENGTH 100

struct Task {
    char description[MAX_LENGTH];
    int completed;
};

struct Task tasks[MAX_TASKS];
int taskCount = 0;

void addTask(char* description) {
    if (taskCount < MAX_TASKS) {
        strcpy(tasks[taskCount].description, description);
        tasks[taskCount].completed = 0;
        taskCount++;
        printf("Task added successfully!\n");
    } else {
        printf("Task list is full!\n");
    }
}

void displayTasks() {
    printf("ToDo List:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. %s - %s\n", i+1, tasks[i].description, tasks[i].completed ? "Completed" : "Not Completed");
    }
}

int main() {
    char input[MAX_LENGTH];
    int choice;

    while (1) {
        printf("1. Add Task\n");
        printf("2. Display Tasks\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter task description: ");
                scanf("%s", input);
                addTask(input);
                break;
            case 2:
                displayTasks();
                break;
            case 3:
                printf("Exiting ToDo List App.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}