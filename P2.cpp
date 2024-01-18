#include <iostream>
#include <thread>

int contador = 10;  


void incrementarContador() {
    for (int i = 0; i < 1000000; ++i) {
        ++contador;
    }
}


void decrementarContador() {
    for (int i = 0; i < 1000000; ++i) {
        --contador;
    }
}

int main() {
   
    std::thread hiloIncrementar(incrementarContador);
    std::thread hiloDecrementar(decrementarContador);

    hiloIncrementar.join();
    hiloDecrementar.join();

    
    std::cout << "El resultado final del contador es: " << contador << std::endl;

    return 0;
}
