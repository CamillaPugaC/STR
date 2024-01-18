#include <iostream>
#include <unistd.h> // Para fork()
#include <sys/wait.h> // Para wait()

int valor = 10; // Variable global inicializada a 10

int main() {
    // Repetir el proceso 10 veces
    for (int i = 0; i < 10; ++i) {
        pid_t pid = fork(); // Crear un nuevo proceso

        if (pid == 0) {
            // Proceso hijo
            valor -= 1; // Decrementar la variable global en el proceso hijo
            std::cout << "Proceso hijo: Valor = " << valor << std::endl;
            break; // Salir del ciclo en el proceso hijo
        } else if (pid > 0) {
            // Proceso padre
            valor += 1; // Incrementar la variable global en el proceso padre
            std::cout << "Proceso padre: Valor = " << valor << std::endl;
            wait(NULL); // Esperar a que el proceso hijo termine
        } else {
            std::cerr << "Error al crear el proceso hijo." << std::endl;
            return 1;
        }
    }

    // Imprimir el resultado final después de 10 iteraciones
    std::cout << "Resultado final: Valor = " << valor << std::endl;

    return 0;
}
