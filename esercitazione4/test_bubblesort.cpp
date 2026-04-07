#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include "sorts.hpp"
#include "randfiller.h"

using namespace std;

// creo l'operatore << per visulizzare correttamente i vettori
template <typename T>
ostream& 
operator << (ostream& os, const vector<T>& vec){
    os << "[";
    for (size_t i=0; i<vec.size(); i++){
        if (i!=vec.size()-1){
            os << vec[i] << ", ";
        }
        else{
           os << vec[i] << "]";
        }
    }
    return os;
}



//creo una funzione che mi restituisce un singolo valore casuale  tra minimo e massimo
size_t random_number(randfiller& rf, int minimo, int massimo){
    vector<int> v;
    //attribuisco al vettore dimensione 1
    v.resize(1);
    //riempio il vettore con un numero casuale tra il minimo e il massimo
    rf.fill(v, minimo, massimo);
    //restituisco solo il valore (che per l'appunto si trova alla posizione v[0])
    return v[0];
}



int main(){
    const int num_test = 100;
    randfiller rf;
    cout << "Avvio 100 test casuali su vettori di interi...\n";
    //riempio i miei vettori con INTERI casuali
    for (int i=0; i<num_test; i++){
        vector<int> vec;
        //chiamo la funzione che ho creato, che mi restituisce un singolo valore, per dare una dimensione casuale al vettore
        size_t N = random_number(rf,1,1000);
        vec.resize(N);
        //riempio il vettore con numeri casuali tra -1000 e 1000
        rf.fill(vec,-1000,1000);
        bubble_sort(vec);
        if (!is_sorted(vec)){
            cerr << "ERRORE: test fallito al ciclo " << i << " per un vettore di dimensione" << N << "\n";
            return EXIT_FAILURE;
        }
    }
    cout << "Tutti i 100 test passati con successo!" << "\n";
    cout << "\n";

    //test su stringhe
    cout << "Avvio test su stringhe...\n";
    vector<string> vec_str = {"fratello", "università", "cane", "palestra", "matematica", "nonna", "hello world", "concerto", "zeta", "gelato"};
    cout << "Stringa originale: " << vec_str << "\n";
    bubble_sort(vec_str);
    if (!is_sorted(vec_str)){
        cerr << "ERRORE: Il test sulle stringhe è fallito \n";
        return EXIT_FAILURE;
    }
    else{
        cout << "Stringa ordinata: " << vec_str << "\n";
        cout << "Test passato con successo!" << "\n";        
    }
    return EXIT_SUCCESS;
}