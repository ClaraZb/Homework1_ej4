#include <iostream>
#include <string>
#include <chrono>

using namespace std;

bool comparar(string palabra1, string palabra2){ //pasar como nuevo parametro i
    if(palabra1.substr(0, 1) != palabra2.substr(0, 1)){
        return false;
    }
    if (size(palabra1) == 1 && size(palabra2) == 1){
        return true;
    }
    return comparar(palabra1.substr(1, size(palabra1)), palabra2.substr(1, size(palabra2)));
}

bool comparar(const char* palabra1, const char* palabra2){ //poner constexpr?
    if (palabra1 != palabra2){ 
        return false;
    }
    if (*palabra1 == '\0' && *palabra2 == '\0'){
        return true;
    }
    return comparar(palabra1+1, palabra2+1);
}

int main(){
    const char *palabra1 = "El señor y la señora Dursley, que vivían en el número 4 de Privet Drive, estaban orgullosos.";
    const char *palabra2 = "El señor y la señora Dursley, que vivían en el número 5 de Privet Drive, estaban orgullosos.";
    
    auto startTime = chrono::high_resolution_clock::now();
    comparar(palabra1, palabra2);
    auto endTime = chrono::high_resolution_clock::now();
    auto elapsedTime = chrono::duration_cast<chrono::nanoseconds>(endTime-startTime);
    cout << "A comparar le tomo: " <<elapsedTime.count() << "nanosegundos" << endl;
    

    //string palabraA = "El señor y la señora Dursley, que vivían en el número 4 de Privet Drive, estaban orgullosos.";
    //string palabraB = "El señor y la señora Dursley, que vivían en el número 5 de Privet Drive, estaban orgullosos.";
    //
    //auto startTime = chrono::high_resolution_clock::now();
    //comparar(palabraA, palabraB);
    //auto endTime = chrono::high_resolution_clock::now();
    //auto elapsedTime = chrono::duration_cast<chrono::nanoseconds>(endTime-startTime);
    //cout << "A comparar le tomo: " <<elapsedTime.count() << "nanosegundos" << endl;

    return 0;
}