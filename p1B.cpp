#include <iostream>
#include <unistd.h> 
#include <sys/wait.h>


int main() {
  
    for (int i = 0; i < 3; ++i) {
        pid_t pid = fork();

        if (pid == 0) {
           
            std::cout << "Proceso hijo #" << i + 1 << " (PID " << getpid() << ") creado." << std::endl;
           
            return 0;
        } else if (pid < 0) {
            std::cerr << "Error al crear el proceso hijo." << std::endl;
            return 1; 
        }
    }

   
    std::cout << "Proceso padre (PID " << getpid() << ") esperando a que los hijos terminen." << std::endl;

   
    for (int i = 0; i < 3; ++i) {
        wait(NULL);
    }

    std::cout << "Proceso padre (PID " << getpid() << ") ha esperado a que todos los hijos terminen." << std::endl;

    return 0;
}
