#include <stdio.h>
#include <string.h>

#define MAX 100

struct Patient {
    char name[20];
    int priority;
};

struct Patient queue[MAX];
int count = 0;


void addPatient(char name[], int priority) {
    if (count == MAX) {
        printf("Queue is full!\n");
        return;
    }

    strcpy(queue[count].name, name);
    queue[count].priority = priority;
    count++;

    printf("Patient %s added with priority %d\n", name, priority);
}

void treatNext() {
    if (count == 0) {
        printf("No patients waiting.\n");
        return;
    }

    int minIndex = 0;

    for (int i = 1; i < count; i++) {
        if (queue[i].priority < queue[minIndex].priority) {
            minIndex = i;
        }
    }

    printf("Treating patient: %s (Priority %d)\n",
           queue[minIndex].name,
           queue[minIndex].priority);

    
    for (int i = minIndex; i < count - 1; i++) {
        queue[i] = queue[i + 1];
    }

    count--;
}

int main() {

    addPatient("P1", 3);
    addPatient("P2", 1);
    addPatient("P3", 2);
    addPatient("P4", 1);
    addPatient("P5", 3);
    addPatient("P6", 2);

    printf("\nTreatment Order:\n");

    while (count > 0) {
        treatNext();
    }

    return 0;
}