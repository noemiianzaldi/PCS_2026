#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>
#include <optional>

using namespace std;

//creo algoritmo per il bubble sort
template<typename T>
void bubble_sort(vector<T>& vec){
    int N = size(vec);
    if (N<2){
        return;
    }
    for (int i=0; i<=N-2; i++){
        for (int j=N-1; j>=i+1; j--){
            if (vec.at(j)<vec.at(j-1)){
                swap(vec.at(j), vec.at(j-1));
            }    
        }
    }
}





//creo algoritmo per il selection sort
template<typename T>
void selection_sort(vector<T>& vec){ 
    int N = size(vec);
        if (N<2){
            return;
        }
    for (int i=0; i<=N-2; i++){
        int min_index = i;
        for (int j=i+1; j<=N-1; j++){
            if (vec.at(j)<vec.at(min_index)){
                min_index = j;
            }
        }
        if (min_index != i){
            swap(vec.at(i), vec.at(min_index));
        }    
    }
}





//creo algoritmo per l'insertion sort
template<typename T>
void insertion_sort(vector<T>& vec){
    int N = size(vec);
    if (N<2){
        return;
    }
    for (int i=1; i<=N-1; i++){
        T value = vec.at(i);
        int j = i-1;
        while (j>=0 && vec.at(j)>value){
            vec.at(j+1) = vec.at(j);
            j=j-1; 
        }
        vec.at(j+1)=value;
    }
}




//creo algoritmo con la funzione sort()
template<typename T>
bool is_sorted(const vector<T>& vec){
    int N = size(vec);
    if (N<2){
        return true;
    }
    for (int i=0; i<N-1; i++){
        if (vec.at(i)>vec.at(i+1)){
            return false;
        }
    }
    return true;
}





//creo algoritmo per il merge
template<typename T>
void merge(vector<T>& vec, size_t sx, size_t centro, size_t dx){

    //calcolo la dimensione dei due sottovettori
    int n1 = centro - sx + 1;
    int n2 = dx-centro;

    //creo i vettori temporanei (nello pseudocodice c'era il +1 ma era legato alle sentinelle dell'infinito, 
    //che abbiamo tolto, perchè nel momento in cui vengono trattate le stringhe si sarebbe generato errore)
    vector<T> S(n1);
    vector<T> D(n2);

    //copio i dati nei vettori temporanei
    // il vettore sx lo riempio con gli elementi da sx a centro
    for(int i=0; i<n1; i++){
        S[i]=vec[sx+i];
    }

    // il vettore dx lo riempio con gli elementi da centro+1 a dx
    for(int j=0; j<n2; j++){
        D[j]=vec[centro+1+j];
    }  

    // i e j sono gli indici per i vettori rispettivamente sx e dx  
    int i = 0;
    int j = 0;

    // k indice per il vettore unito
    int k = sx;

    //ciclo while per confrontare gli elementi fino a quando uno dei due vettori finisce
    while(i<n1 && j<n2){
        if (S[i] <= D[j]){
            vec[k] = S[i];
            i++;
        }
        else{
            vec[k] = D[j];
            j++;
        }
        k++;
    }

    //ciclo while che copia gli eventuali elementi rimanenti in S (se presenti)
    while(i<n1){
        vec[k] = S[i];
        i++;
        k++;
    }
    //ciclo while che copia gli eventuali elementi rimanenti in D (se presenti)
    while(j<n2){
        vec[k] = D[j];
        j++;
        k++;
    }         
}

//creo algoritmo per il mergesort
template<typename T>
void merge_sort(vector<T>& vec, size_t sx, size_t dx){
    if(sx<dx){
        size_t centro = (sx+dx)/2; 
        merge_sort(vec, sx, centro);
        merge_sort(vec, centro+1, dx);
        merge(vec, sx, centro, dx);
    }
}




//creo algoritmo per la funzione partition
template<typename T>
int partition(vector<T>& vec, int sx, int dx){

    //pivot
    T x = vec[dx];
    int i = sx-1;
    for(int j=sx; j<dx; j++){
        if (vec[j]<=x){
            i++;
            swap(vec[i],vec[j]);
        }
    }
    swap(vec[i+1],vec[dx]);

    //restituisco il rango
    return i+1;
}

//creo algoritmo per il quicksort
template<typename T>
void quick_sort(vector<T>& vec, int sx, int dx){
    if (sx<dx){
        int q = partition(vec, sx, dx);
        quick_sort(vec, sx, q-1);
        quick_sort(vec, q+1, dx);
    }
}




//creo algoritmo per l'intervallo dato dall'insertion sort
template<typename T>
void insertion_sort_range(vector<T>& vec, int sx, int dx){
    if (dx-sx <= 0){
        return;
    }
    for(int i=sx+1; i<=dx; i++){
        T value = vec[i];
        int j = i-1;
        while (j >= sx && vec[j]>=value){
            vec[j+1] = vec[j];
            j = j-1;
        }
        vec[j+1] = value;
    }
}

//creo algoritmo per il quicksort ibrido
template<typename T>
void quick_sort_hybrid(vector<T>& vec, int sx, int dx){

    //inserisco la soglia oltre il quale l'insertion sort è peggio del quick sort
    const int limite = 12;

    if (dx-sx+1 < limite){
        insertion_sort_range(vec, sx, dx);
    }
    else{
        if (sx<dx){
            int q = partition(vec, sx, dx);
            quick_sort_hybrid(vec, sx, q-1);
            quick_sort_hybrid(vec, q+1, dx);
        }
    }
}