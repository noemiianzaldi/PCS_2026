#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

//creo algoritmo per il bubble sort
template<typename T>
void bubble_sort(std::vector<T>& vec){
    int N = size(vec);
    if (N<2){
        return;
    }
    for (int i=0; i<=N-2; i++){
        for (int j=N-1; j>=i+1; j--){
            if (vec.at(j)<vec.at(j-1)){
                std::swap(vec.at(j), vec.at(j-1));
            }    
        }
    }
}

//creo algoritmo per il selection sort
template<typename T>
void selection_sort(std::vector<T>& vec){ 
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
            std::swap(vec.at(i), vec.at(min_index));
        }    
    }
}

//creo algoritmo per l'insertion sort
template<typename T>
void insertion_sort(std::vector<T>& vec){
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
bool is_sorted(const std::vector<T>& vec){
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
