#include <iostream>
using namespace std;

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
    const char *palabra1 = "Hola";
    const char *palabra2 = "Chau";
    bool res = comparar(palabra1, palabra2);
    cout << res << endl;
    return 0;
}