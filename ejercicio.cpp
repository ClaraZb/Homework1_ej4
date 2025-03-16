#include <iostream>
#include <string>
#include <chrono>

using namespace std;

/*
Elijo usar const char * porque es de mas bajo nivel que string, por lo que supongo que la 
ejecucion va a ser mas rapida.
Para testearlo, hice una funcion recursiva para cada tipo. Al ejecutarlas el tiempo de ejecucion
para string fue de 27472 nanosegundos, mientras que el de char* fue de 106 nanosegundos, que es mucho menor. 
Me quedo con esa funcion. 
*/

bool comparar(const char* palabra1, const char* palabra2){ 
    if (palabra1 != palabra2){ 
        return false;
    }
    if (*palabra1 == '\0' && *palabra2 == '\0'){
        return true;
    }
    return comparar(palabra1+1, palabra2+1);
}

//Mismo codigo que la funcion anterior pero se ejecuta en tiempo de compilacion
constexpr bool comparar2(const char* palabra1, const char* palabra2){ 
    if (palabra1 != palabra2){ 
        return false;
    }
    if (*palabra1 == '\0' && *palabra2 == '\0'){
        return true;
    }
    return comparar2(palabra1+1, palabra2+1);
}


int main(){
    const char *palabra1 = "El señor y la señora Dursley, que vivían en el número 4 de Privet Drive, estaban orgullosos.";
    const char *palabra2 = "El señor y la señora Dursley, que vivían en el número 5 de Privet Drive, estaban orgullosos.";
    
    auto startTime = chrono::high_resolution_clock::now();
    bool res = comparar(palabra1, palabra2);
    auto endTime = chrono::high_resolution_clock::now();
    auto elapsedTime = chrono::duration_cast<chrono::nanoseconds>(endTime-startTime);
    
    if (res == true) cout << "Los textos son iguales," << endl;
    else cout << "Los textos son diferentes" << endl;
   
    cout << "A comparar le tomo: " <<elapsedTime.count() << " nanosegundos" << endl;

    auto startTime2 = chrono::high_resolution_clock::now();
    comparar2(palabra1, palabra2);
    auto endTime2 = chrono::high_resolution_clock::now();
    auto elapsedTime2 = chrono::duration_cast<chrono::nanoseconds>(endTime2-startTime2);
    cout << "A comparar2 le tomo: " <<elapsedTime2.count() << " nanosegundos" << endl;

    return 0;
}

/*
El tiempo de ejecucion medido de comparar2 fue casi la mitad de la primer funcion comparar.
Esto es debido a que, al usar constexpr, la comparacion se hace al compilar el archivo, y no al ejecutarlo,
lo que hace que el tiempo de ejecucion sea mucho menor que antes. 
*/