#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<algorithm>
#include "timecounter.h"
#include "randfiller.h"
#include "sorts.hpp"

using namespace std;

// creo l'operatore di stampa per visulizzare correttamente i vettori
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

int main(){
    randfiller rf;
    timecounter tc;

    //creo dei vettori per ciascun sort dove inserirò ad ogni ciclo i tempi per ogni vettore
    vector<double> tempi_bubble;
    vector<double> tempi_selection;
    vector<double> tempi_insertion;
    vector<double> tempi_sort;

    for (int i=4; i<=8192; i*=2){
        vector<double> vec;
        vec.resize(i);


        //test bubble sort
        //riempio il vettore con un numero casuale tra -500 e 500
        rf.fill(vec,-500.0,500.0);
        //avvio il cronometro
        tc.tic();
        bubble_sort(vec);
        //fermo il cronometro
        double t_bubble = tc.toc();
        //inserisco il tempo registrato nel vettore corrispondente 
        tempi_bubble.push_back(t_bubble);


        //test insertion sort
        //riempio il vettore con un numero casuale tra -500 e 500
        rf.fill(vec,-500.0,500.0);
        //avvio il cronometro
        tc.tic();
        insertion_sort(vec);
        //fermo il cronometro
        double t_insertion = tc.toc();
        //inserisco il tempo registrato nel vettore corrispondente
        tempi_insertion.push_back(t_insertion);


        //test selection sort
        //riempio il vettore con un numero casuale tra -500 e 500
        rf.fill(vec,-500.0,500.0);
        //avvio il cronometro
        tc.tic();
        selection_sort(vec);
        //fermo il cronometro
        double t_selection = tc.toc();
        //inserisco il tempo registrato nel vettore corrispondente
        tempi_selection.push_back(t_selection);


        //test sort 
        //riempio il vettore con un numero casuale tra -500 e 500
        rf.fill(vec,-500.0,500.0);
        //avvio il cronometro
        tc.tic();
        sort(vec.begin(), vec.end());
        //fermo il cronometro
        double t_sort = tc.toc();
        //inserisco il tempo registrato nel vettore corrispondente
        tempi_sort.push_back(t_sort);

        cout << "dimensione vettore: " << i << " tempo bubble: " << t_bubble << " tempo insertion: " << t_insertion << " tempo sort: " << t_sort << "\n";
        cout << "\n";

    }
    cout << "Tempi del bubble sort: " << tempi_bubble << "\n";
    cout << "\n";
    cout << "Tempi dell'insertion sort: " << tempi_insertion << "\n";
    cout << "\n";
    cout << "Tempi del selection sort: " << tempi_selection << "\n";
    cout << "\n";
    cout << "Tempi della funzione sort(): " << tempi_sort << "\n";

    return EXIT_SUCCESS;
}