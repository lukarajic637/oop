#include <iostream>

int funkcija(int x, int low, int high){
    if (x<low){
        return low;
    }
    else if(x>high){
        return high;
    }
    else{
        return x;
    }
}

double funkcija(double x, double low, double high){
    if (x<low){
        return low;
    }
    else if(x>high){
        return high;
    }
    else{
        return x;
    }
}

int main(){
    int a = 20;
    double b = 1.7;
    std::cout << funkcija(a,5,15) << std::endl;
    std::cout << funkcija(b,5.2,15.0) << std::endl;
    return 0;
}
