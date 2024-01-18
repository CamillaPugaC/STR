#include <iostream>
#include <cmath>

unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    unsigned long long fact = 1;
    for (int i = 2; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}

int main() {
    double x;
    int iteraciones;

   
    std::cout << "Ingrese el valor de x: ";
    std::cin >> x;
    std::cout << "Ingrese el numero de iteraciones: ";
    std::cin >> iteraciones;

    double resultado = 1.0; 
    double valorReal = std::exp(x); 

    for (int n = 1; n <= iteraciones; ++n) {
        double termino = std::pow(x, n) / factorial(n);
        resultado += termino;
    }

    
    double errorRelativo = std::abs((valorReal - resultado) / valorReal) * 100.0;

  
    std::cout << "Resultado aproximado: " << resultado << std::endl;
    std::cout << "Valor real: " << valorReal << std::endl;
    std::cout << "Error relativo (%): " << errorRelativo << "%" << std::endl;

    return 0;
}
