#include <stdio.h>
#include <string.h>

#define MAX_TASKS 10

typedef struct {
    char description[50];
    int checked;
} Task;

void print_tasks(Task tasks[], int count) {
    printf("To-do list:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %c %s\n", i+1, tasks[i].checked ? 'X' : ' ', tasks[i].description);
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int count = 0;

    while (1) {
        printf("\nWhat would you like to do?\n\n");
        printf("(a)add task\n");
        printf("(b)delete task\n");
        printf("(c)check task\n");
        printf("(d)uncheck task\n");
        printf("(q)quit\n");

        char choice;
        scanf(" %c", &choice);

        if (choice == 'q') {
            break;
        } else if (choice == 'a') {
            if (count == MAX_TASKS) {
                printf("To-do list is full.\n");
                continue;
            }

            printf("Enter task description: ");
            char description[50];
            scanf(" %[^\n]", description);
            strcpy(tasks[count].description, description);
            tasks[count].checked = 0;
            count++;
        } else if (choice == 'b') {
            if (count == 0) {
                printf("To-do list is empty.\n");
                continue;
            }

            printf("Enter task number to delete: ");
            int num;
            scanf("%d", &num);

            if (num < 1 || num > count) {
                printf("Invalid task number.\n");
                continue;
            }

            for (int i = num - 1; i < count - 1; i++) {
                strcpy(tasks[i].description, tasks[i + 1].description);
                tasks[i].checked = tasks[i + 1].checked;
            }

            count--;
        } else if (choice == 'c') {
            if (count == 0) {
                printf("To-do list is empty.\n");
                continue;
            }

            printf("Enter task number to check: ");
            int num;
            scanf("%d", &num);

            if (num < 1 || num > count) {
                printf("Invalid task number.\n");
                continue;
            }

            tasks[num - 1].checked = 1;
        } else if (choice == 'd') {
            if (count == 0) {
                printf("To-do list is empty.\n");
                continue;
            }

            printf("Enter task number to uncheck: ");
            int num;
            scanf("%d", &num);

            if (num < 1 || num > count) {
                printf("Invalid task number.\n");
                continue;
            }

            tasks[num - 1].checked = 0;
        } else {
            printf("Invalid choice.\n");
        }

        print_tasks(tasks, count);
    }

    printf("Eklavya is great!\n");
    return 0;
}
