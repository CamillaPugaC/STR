#include <iostream>
#include <unistd.h> // Para fork()

int main() {
    // Crear tres procesos hijos
    for (int i = 0; i < 3; ++i) {
        pid_t pid = fork();

        if (pid == 0) {
            // Proceso hijo
            std::cout << "Proceso hijo #" << i + 1 << " (PID " << getpid() << ") creado." << std::endl;
            // El proceso hijo puede realizar tareas adicionales aquí
            return 0; // Terminar el proceso hijo
        } else if (pid < 0) {
            std::cerr << "Error al crear el proceso hijo." << std::endl;
            return 1; // Salir con error si la creación del proceso hijo falla
        }
    }

    // Proceso padre
    std::cout << "Proceso padre (PID " << getpid() << ") esperando a que los hijos terminen." << std::endl;

    // Esperar a que los procesos hijos terminen
    for (int i = 0; i < 3; ++i) {
        wait(NULL);
    }

    std::cout << "Proceso padre (PID " << getpid() << ") ha esperado a que todos los hijos terminen." << std::endl;

    return 0;
}
