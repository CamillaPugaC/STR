#include <iostream>
#include <thread>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int contador = 10;  


void incrementarContador() {
    wait(sem);
    for (int i = 0; i < 1000000; ++i) {
        ++contador;
    std::cout << contador << std::endl;

    }
     signal(sem);
}


void decrementarContador() {
    for (int i = 0; i < 1000000; ++i) {
        --contador;
    std::cout << contador << std::endl;

    }
}

int main() {
   
    std::thread hiloIncrementar(incrementarContador);
    std::thread hiloDecrementar(decrementarContador);

    hiloIncrementar.join();
    hiloDecrementar.join();

    

    return 0;
}
