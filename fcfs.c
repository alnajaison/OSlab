#include <stdio.h>

struct Process {
    int pid, at, bt, ct,wt, tt;
};

void sortByArrival(struct Process p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].at > p[j].at) {
                struct Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter arrival time and burst time for process %d: ", p[i].pid);
        scanf("%d %d", &p[i].at, &p[i].bt);
    }

    sortByArrival(p, n);

    //calculating ct, tt and wt
    int currentTime = 0;   //keeps track of the CPU's current time
    for (int i = 0; i < n; i++) {
        if (currentTime < p[i].at)
            currentTime = p[i].at;

        p[i].ct = currentTime + p[i].bt;
        p[i].tt = p[i].ct - p[i].at;
        p[i].wt = p[i].tt - p[i].bt;

        currentTime = p[i].ct;
    }

    // Table Header
    printf("\nPID\tAT\tBT\tCT\tTT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tt, p[i].wt);
    }

    // Gantt Chart
    printf("\nGantt Chart:\n ");
    for (int i = 0; i < n; i++) {
        printf("  P%d  |", p[i].pid);
    }
    printf("\n ");
    for (int i = 0; i < n; i++) {
        printf("-------");
    }
    printf("\n");

    int startTime = 0;
    if (p[0].at > 0) 
	    startTime = p[0].at;
    printf("%d", startTime);
    for (int i = 0; i < n; i++) {
        if (startTime < p[i].at)
            startTime = p[i].at;

        startTime += p[i].bt;
        printf("      %d", startTime);
    }

    printf("\n");

    return 0;
}
