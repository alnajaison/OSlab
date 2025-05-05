#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function for FIFO Page Replacement
void fifo(int pages[], int n, int nf) {
    int frames[nf], front = 0, count = 0;
    for (int i = 0; i < nf; i++)
        frames[i] = -1;

    printf("FIFO Page Replacement:\n");
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < nf; j++) { //check if page in already in frame
            if (frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            frames[front] = pages[i];
            front = (front + 1) % nf;
            count++;
        }
        printf("Frames: ");
        for (int j = 0; j < nf; j++)
            printf("%d ", frames[j]);
        printf("\n");
    }
    printf("Total Page Faults: %d\n\n", count);
}

// Function for LRU Page Replacement
void lru(int pages[], int n, int nf) {
    int frames[nf], lastUsed[nf], count = 0;
    for (int i = 0; i < nf; i++) {
        frames[i] = -1;
        lastUsed[i] = -1;
    }

    printf("LRU Page Replacement:\n");
    for (int i = 0; i < n; i++) {
        int found = 0, lruIndex = -1, minUsed = n;
        for (int j = 0; j < nf; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                lastUsed[j] = i;
                break;
            }
        }
        if (!found) {
            for (int j = 0; j < nf; j++) {
                if (frames[j] == -1) {
                    lruIndex = j; 
                    break;
                }
                if (lastUsed[j] < minUsed) {
                    minUsed = lastUsed[j];
                    lruIndex = j;
                }
            }
            frames[lruIndex] = pages[i];
            lastUsed[lruIndex] = i;
            count++;
        }
        printf("Frames: ");
        for (int j = 0; j < nf; j++)
            printf("%d ", frames[j]);
        printf("\n");
    }
    printf("Total Page Faults: %d\n\n", count);
}

// Function for LFU Page Replacement
void lfu(int pages[], int n, int nf) {
    int frames[nf], frequency[nf], count = 0;
    for (int i = 0; i < nf; i++) {
        frames[i] = -1;
        frequency[i] = 0;
    }

    printf("LFU Page Replacement:\n");
    for (int i = 0; i < n; i++) {
        int found = 0, lfuIndex = -1, minFreq = n;
        for (int j = 0; j < nf; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                frequency[j]++;
                break;
            }
        }
        if (!found) {
            for (int j = 0; j < nf; j++) {
                if (frames[j] == -1) {
                    lfuIndex = j;
                    break;
                }
                if (frequency[j] < minFreq) {
                    minFreq = frequency[j];
                    lfuIndex = j; 
                }
            }
            frames[lfuIndex] = pages[i];
            frequency[lfuIndex] = 1;
            count++;
        }
        printf("Frames: ");
        for (int j = 0; j < nf; j++)
            printf("%d ", frames[j]);
        printf("\n");
    }
    printf("Total Page Faults: %d\n\n", count);
}

int main() {
    int nf, np;

    printf("Enter the number of frames: ");
    scanf("%d", &nf);

    printf("Enter the number of pages: ");
    scanf("%d", &np);

    int pages[np];

    printf("Enter the page references: \n");
    for (int i = 0; i < np; i++) {
        scanf("%d", &pages[i]);
    }

    fifo(pages, np, nf);
    lru(pages, np, nf);
    lfu(pages, np, nf);

    return 0;
}
