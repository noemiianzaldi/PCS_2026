#include <iostream>
using namespace std;

int main() {
    static const int N = 10;
    double arr[N] =  {4.6, 1.9, 1.03, 26.5, -3.7, 0, 21.70, 8.22, 16.21, 9.91};
    double temporanea = 0;
    bool scambiato = true;
    while (scambiato){
        scambiato = false;
        for (int i=0; i < N-1; i++){
            if (arr[i] > arr[i+1]){
                temporanea = arr[i]; //salvo in una variabile temporanea il valore nella posizione arr[i]
                arr[i] = arr[i+1]; // salvo arr[i] con il valore arr[i+1]
                arr[i+1] = temporanea; // salvo arr[i+1] con il valore salvato temporaneamente nella variabile 'temporanea' che corrisponde al valore che era in arr[i]; altrimenti sarebbe andato perso con il passsaggio precedente
                //quindi ho scambiato i due valori 
                scambiato = true; // alrimenti il while si fermerebbe 
            }
        }
    }
    for (int i=0; i < N; i++){
        cout << arr[i] << " ";
            }
    cout << "\n";
    return 0;
}