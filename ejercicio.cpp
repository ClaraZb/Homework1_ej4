#include <iostream>
using namespace std;

//intentar con string y comparar el tiempo
bool comparar(const char* palabra1, const char* palabra2){
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
    bool res = comparar(palabra1, palabra2);
    cout << res << endl;
    return 0;
}