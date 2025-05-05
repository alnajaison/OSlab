#include <stdio.h>
#include <stdlib.h>

// FCFS Disk Scheduling
void FCFS(int req[], int n, int head) {
    int seek_time = 0;
    printf("\nFCFS Disk Scheduling:\n");
    printf("Sequence: %d ", head);
    for (int i = 0; i < n; i++) {
        seek_time += abs(head - req[i]);
        head = req[i];
        printf("-> %d ", head);
    } printf("\nTotal Seek Time: %d\n", seek_time);  }
    
    
// SCAN Disk Scheduling
void SCAN(int req[], int n, int head, int dsize) {
    int seek_time = 0;
    int dir = 1; // 1 means moving towards higher values
    printf("\nSCAN Disk Scheduling:\n");
    printf("Sequence: %d ", head);
    
    // Sorting the requests
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (req[j] > req[j + 1]) {
                int temp = req[j];
                req[j] = req[j + 1];
                req[j + 1] = temp;
            }
        }
    }    
    int idx;
    for (idx = 0; idx < n; idx++) {
        if (req[idx] >= head) break;
    }    
    for (int i = idx; i < n; i++) {
        seek_time += abs(head-req[i]);
        head = req[i];
        printf("-> %d ", head);
    }
    // Move to end of disk
    if (head != dsize - 1) {
        seek_time += abs(head-(dsize - 1));
        head = dsize - 1;
        printf("-> %d ", head);
    }
    // Moving back to lower values
    for (int i = idx - 1; i >= 0; i--) {
        seek_time += abs(head-req[i]);
        head = req[i];
        printf("-> %d ", head);
    }
    printf("\nTotal Seek Time: %d\n", seek_time);
}


// C-SCAN Disk Scheduling
void C_SCAN(int req[], int n, int head, int dsize) {
    int seek_time = 0;
    printf("\nC-SCAN Disk Scheduling:\n");
    printf("Sequence: %d ", head);    
    // Sorting requests
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (req[j] > req[j + 1]) {
                int temp = req[j];
                req[j] = req[j + 1];
                req[j + 1] = temp;
            }
        }
    }  int idx;
    for (idx = 0; idx < n; idx++) {
        if (req[idx] >= head) break;
    }    
    for (int i = idx; i < n; i++) {
        seek_time += abs(head-req[i]);
        head = req[i];
        printf("-> %d ", head);
    }    
    if (head != dsize - 1) {
        seek_time += abs(head-(dsize - 1));
        head = dsize - 1;
        printf("-> %d ", head);
    }
    seek_time += abs(head-0);
    head = 0;
    printf("-> %d ", head);    
    for (int i = 0; i < idx; i++) {
        seek_time += abs(head-req[i]);
        head = req[i];
        printf("-> %d ", head);
    }  printf("\nTotal Seek Time: %d\n", seek_time);
}


int main() {
    int n, head, dsize;
    printf("Enter number of disk requests: ");
    scanf("%d", &n);    
    int req[n];
    printf("Enter the requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &req[i]);
    }  printf("Enter initial head position: ");
    scanf("%d", &head);   
    printf("Enter total disk size: ");
    scanf("%d", &dsize);    
    FCFS(req, n, head);
    SCAN(req, n, head, dsize);
    C_SCAN(req, n, head, dsize);
    return 0;  
 }
