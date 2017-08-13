//classic one way cross problem. The rope can be crossed only at one direction (east or west) at the time.

#include <semaphore.h>
#include <math.h>
#include <iostream>
#include <pthread.h>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
using namespace std;

const int TIME = 3;
const int EAST = 2;
const int WEST =1;

sem_t rope;
sem_t cross;
sem_t line;
sem_t out_mutex;
int countEast =0;
int countWest =4;

void go(int baboon);

void *east(void*){
    bool crossed = false;
    int baboons;
    while (!crossed){
        sem_wait(&cross);
        ++countEast;
        baboons = countEast;
        if (countEast == 1)
            sem_wait(&rope);
        sem_post(&cross);
        go(baboons);
        sem_wait(&cross);
        --countEast;
        if (countEast == 0)
            sem_post(&rope);
        crossed = true;
    }
    sem_post(&cross);
    return 0;
}

void *west(void*){
    bool crossed = false;
    int baboons;
    while (!crossed){
        sem_wait(&cross);
        ++countWest;
        baboons = countWest;
        if (countWest == 1)
            sem_wait(&rope);
        sem_post(&cross);
        go(baboons);
        sem_wait(&cross);
        --countWest;
        if (countWest == 0)
            sem_post(&rope);
        crossed = true;
    }
    sem_post(&cross);
    return 0;
}

void go(int baboon){
    int direction;
    if (baboon < 4)
        direction = EAST;
    else{
        direction = WEST;
    }
    sem_wait(&out_mutex);
    if (direction== EAST){
        cout << " Baboon is crossing East" <<endl;
    }
    else if(direction== WEST){
        cout << " Baboon is crossing West" <<endl;
    }
    sem_post(&out_mutex);
    sleep(TIME);
}
int main(){
    sem_t *semaphore;
    sem_init(&rope, 0, 1);
    sem_init(&cross, 0, 1);
    sem_init(&out_mutex, 0, 1);
    int all_baboons = 20;
    pthread_t baboons[all_baboons];
    srand(time(NULL));
    for (int i = 0; i < all_baboons; ++i){
        sleep(1);
        int direction = (rand() % 2) + 1;
        if (direction == EAST){
            pthread_create(&baboons[i], NULL, east,(void*)i);
        }
        else if(direction == WEST){
            pthread_create(&baboons[i], NULL, west,(void*)i);
        }
    }
}
