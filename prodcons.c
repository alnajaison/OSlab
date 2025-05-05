#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

int buffer[5];  // Shared buffer
int in = 0;       // Pointer to the next empty slot in the buffer
int out = 0;      // Pointer to the next full slot in the buffer

sem_t empty;  // Semaphore to count empty slots in the buffer
sem_t full;   // Semaphore to count full slots in the buffer
sem_t mutex;  // Semaphore for mutual exclusion

// Function for the producer thread
void* producer(void* param) {
    int item;
    while (1) {
        item = rand() % 100;  // Produce a random item
        sem_wait(&empty);      // Wait for an empty slot
        sem_wait(&mutex);      // Enter critical section

        buffer[in] = item;    // Produce item and store in buffer
        printf("Produced: %d at index %d\n", item, in);
        in = (in + 1) % 5;   // Update the 'in' pointer

        sem_post(&mutex);      // Exit critical section
        sem_post(&full);       // Signal that a new item has been produced

        sleep(1);  // Simulate time taken to produce an item
    }
}

// Function for the consumer thread
void* consumer(void* param) {
    int item;
    while (1) {
        sem_wait(&full);       // Wait for a full slot
        sem_wait(&mutex);      // Enter critical section

        item = buffer[out];    // Consume item from buffer
        printf("Consumed: %d from index %d\n", item, out);
        out = (out + 1) % 5; // Update the 'out' pointer

        sem_post(&mutex);      // Exit critical section
        sem_post(&empty);      // Signal that an empty slot is now available

        sleep(1);  // Simulate time taken to consume an item
    }
}

int main() {
    pthread_t prod, cons;

    // Initialize the semaphores
    sem_init(&empty, 0, 5);  // Initially, all slots are empty
    sem_init(&full, 0, 0);     // Initially, no slots are full
    sem_init(&mutex, 0, 1);    // Mutex starts as 1 (allowing access)

    // Create producer and consumer threads
    if (pthread_create(&prod, NULL, producer, NULL)) {
        printf("Error creating producer thread\n");
        exit(1);
    }
    if (pthread_create(&cons, NULL, consumer, NULL)) {
        printf("Error creating consumer thread\n");
        exit(1);
    }

    // Join the threads (in a real program, this would be done in a controlled way)
    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    // Destroy the semaphores (in a real program, do this after threads are done)
    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);

    return 0;
}
