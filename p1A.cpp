#include <iostream>
#include <unistd.h> 
#include <sys/wait.h>

int valor = 10; 

int main() {
    
    for (int i = 0; i < 10; ++i) {
        pid_t pid = fork(); 

        if (pid == 0) {
            
            valor -= 1; 
            std::cout << "Proceso hijo: Valor = " << valor << std::endl;
            break; 
        } else if (pid > 0) {
           
            valor += 1; 
            std::cout << "Proceso padre: Valor = " << valor << std::endl;
            wait(NULL); 
        } else {
          std::cerr << "Error al crear el proceso hijo." << std::endl;
            return 1;
        }
    }

    
    std::cout << "Resultado final: Valor = " << valor <<std::endl;

    return 0;
}
