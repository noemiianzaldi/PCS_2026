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
    vector<double> tempi_merge;
    vector<double> tempi_quick;
    vector<double> tempi_quick_hybrid;

    for (int i=1; i<=100; i++){

        // creo una matrice 50xi
        vector<vector<double>> dati(50, vector<double>(i));

        //riempio la matrice in modo casuale, scorrendola riga per riga
        for(size_t k=0; k < 50; k++){
            rf.fill(dati[k], -500.0, 500.0);
        }

        //test bubble sort
        //riempio la matrice in modo casuale, scorrendola riga per riga
        for(size_t k = 0; k < 50; k++){
            rf.fill(dati[k], -500.0, 500.0);
        }
        //avvio il cronometro
        tc.tic();
        for (size_t k = 0; k<50; k++){
            bubble_sort(dati[k]);
        }
        //fermo il cronometro
        double t_bubble = tc.toc()/50;
        //inserisco il tempo registrato nel vettore corrispondente 
        tempi_bubble.push_back(t_bubble);


        //test insertion sort
        //riempio la matrice in modo casuale, scorrendola riga per riga
        for(size_t k = 0; k < 50; k++){
            rf.fill(dati[k], -500.0, 500.0);
        }
        //avvio il cronometro
        tc.tic();
        for (size_t k = 0; k<50; k++){
            insertion_sort(dati[k]);
        }
        //fermo il cronometro
        double t_insertion = tc.toc()/50;
        //inserisco il tempo registrato nel vettore corrispondente
        tempi_insertion.push_back(t_insertion);


        //test selection sort
        //riempio la matrice in modo casuale, scorrendola riga per riga
        for(size_t k = 0; k < 50; k++){
            rf.fill(dati[k], -500.0, 500.0);
        }
        //avvio il cronometro
        tc.tic();
        for (size_t k = 0; k<50; k++){
            selection_sort(dati[k]);
        }
        //fermo il cronometro
        double t_selection = tc.toc()/50;
        //inserisco il tempo registrato nel vettore corrispondente
        tempi_selection.push_back(t_selection);


        //test sort
        //riempio la matrice in modo casuale, scorrendola riga per riga
        for(size_t k = 0; k < 50; k++){
            rf.fill(dati[k], -500.0, 500.0);
        } 
        //avvio il cronometro
        tc.tic();
        for (size_t k = 0; k<50; k++){
            sort(dati[k].begin(), dati[k].end());
        }
        //fermo il cronometro
        double t_sort = tc.toc()/50;
        //inserisco il tempo registrato nel vettore corrispondente
        tempi_sort.push_back(t_sort);

        
        //test merge sort
        //riempio la matrice in modo casuale, scorrendola riga per riga
        for(size_t k = 0; k < 50; k++){
            rf.fill(dati[k], -500.0, 500.0);
        }
        //avvio il cronometro
        tc.tic();
        for (size_t k = 0; k<50; k++){
            merge_sort(dati[k], 0, dati[k].size()-1);
        }
        //fermo il cronometro
        double t_merge = tc.toc()/50;
        //inserisco il tempo registrato nel vettore corrispondente
        tempi_merge.push_back(t_merge);


        //test quick sort
        //riempio la matrice in modo casuale, scorrendola riga per riga
        for(size_t k = 0; k < 50; k++){
            rf.fill(dati[k], -500.0, 500.0);
        }
        //avvio il cronometro
        tc.tic();
        for (size_t k = 0; k<50; k++){
            quick_sort(dati[k], 0, dati[k].size()-1);
        }
        //fermo il cronometro
        double t_quick = tc.toc()/50;
        //inserisco il tempo registrato nel vettore corrispondente
        tempi_quick.push_back(t_quick);


        //test quick sort hybrid
        //riempio la matrice in modo casuale, scorrendola riga per riga
        for(size_t k = 0; k < 50; k++){
            rf.fill(dati[k], -500.0, 500.0);
        }
        //avvio il cronometro
        tc.tic();
        for (size_t k = 0; k<50; k++){
            quick_sort_hybrid(dati[k], 0, dati[k].size()-1);
        }
        //fermo il cronometro
        double t_quickhybrid = tc.toc()/50;
        //inserisco il tempo registrato nel vettore corrispondente
        tempi_quick_hybrid.push_back(t_quickhybrid);


    }
    cout << "Tempi del bubble sort: " << tempi_bubble << "\n";
    cout << "\n";
    cout << "Tempi dell'insertion sort: " << tempi_insertion << "\n";
    cout << "\n";
    cout << "Tempi del selection sort: " << tempi_selection << "\n";
    cout << "\n";
    cout << "Tempi del merge sort: " << tempi_merge << "\n";
    cout << "\n";
    cout << "Tempi del quick sort: " << tempi_quick << "\n";
    cout << "\n";
    cout << "Tempi del quick sort hybrid: " << tempi_quick_hybrid << "\n";
    cout << "\n";
    cout << "Tempi della funzione sort(): " << tempi_sort << "\n";

    return EXIT_SUCCESS;
}