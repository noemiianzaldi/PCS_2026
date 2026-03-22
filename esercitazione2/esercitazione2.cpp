#include <iostream>
#include <cmath>

int main(){
    static const int N = 10;
    double arr[N] =  {4.6, 1.9, 1.03, 26.5, -3.7, 0, 21.70, 8.22, 16.21, 9.91};
    double minimo = arr[0];
    double massimo = arr[0];
    double somma = 0;
    for (int i=0; i < N-1; i++){
        minimo = std::min(arr[i], minimo);
        massimo = std::max(arr[i], massimo);
        somma = somma + arr[i];
    }
    double media = somma/N;
    double var = 0;
    for (int i=0; i < N; i++){
        var += (arr[i] - media)*(arr[i] - media);
    }
    double ds = std::sqrt((var/N));
std::cout << "Il minimo è:" << " " << minimo << "\n";
std::cout << "Il massimo è:" << " " << massimo << "\n";
std::cout << "La media è:" << " " << media << "\n";
std::cout << "La deviazione standard è:" << " " << ds << "\n";
return 0;
}