#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>

using namespace std;

//creo una classe per rappresentare un arco diretto in un grafo
class unidirected_edge{
private:
    int nodo1;
    int nodo2;
    void ordinamento_nodi(){
        if (nodo1>nodo2){
            swap(nodo1,nodo2);
        }
    }
public:
    //costruttore user-defined
    //inizializzo nodo1 e nodo2 con i valori specificati dall'utente
    unidirected_edge(const int& n1, const int& n2){ 
        nodo1 = n1;
        nodo2 = n2;
        ordinamento_nodi();
    }

    //metodi per ottenere i due nodi
    int from() const {
        return nodo1;
    }
    int to() const {
        return nodo2;
    }


    //operatore <
    bool operator < (const unidirected_edge& altro) const{
        if (nodo1 < altro.nodo1){
            return true;
        }
        if (nodo1 == altro.nodo1){
            if (nodo2 < altro.nodo2){
                return true;
            }
        }
        return false;
    }

    //operatore ==
    bool operator == (const unidirected_edge& altro) const{
        if (nodo1 == altro.nodo1 && nodo2 == altro.nodo2){
            return true;
        }
        else {
            return false;
        }
    }

};



//operatore << per la stampa di un arco
ostream& operator << (ostream& os, const unidirected_edge& arco){
    os << "(" << arco.from() << "," << arco.to() << ")";
    return os;
}



class unidirected_graph{
private:
    //creo dei cassetti per memorizzare i dati
    // set è una collezione ordinata che non ammette duplicati
    set<unidirected_edge> archi;

    //la chiave è int, cioè il numero di un nodo, che contiene tutti gli altri numeri dei nodi a cui è collegato set<int>
    map<int, set<int>> lista_adiacenza;

public:
    //costruttore di default 
    // uso default perchè così set e map si svuotano da soli (li sto inizializzando a "cassetti" vuoti)
    unidirected_graph() = default;

    //costruttore di copia
    unidirected_graph(const unidirected_graph& altro){
        this->archi = altro.archi;
        this->lista_adiacenza = altro.lista_adiacenza;
    }


    //metodo neighbours (restituisce i vicini di un nodo n)
    set<int> neighbours(int n) const{

        //verifico se il nodo n (preso come chiave nella mappa) esiste
        if(lista_adiacenza.contains(n)) {

            //prendo i nodi collegati al nodo chiave
            return lista_adiacenza.at(n);
        }
        else{
            //se il nodo non esiste restituisco il vuoto
            return{};
        }
    }



    //metodo add_edge (permette di aggiungere un arco al grafo)
    void add_edge(int n1, int n2){

        //creo l'arco
        unidirected_edge nuovo_arco(n1,n2);

        //lo aggiungo al set degli archi (il quale scarta in automatico i duplicati)
        archi.insert(nuovo_arco);

        //aggiorno la lista di adiacenza per entrambi i nodi
        lista_adiacenza[n1].insert(n2);
        lista_adiacenza[n2].insert(n1);
    }



    //metodo all_edges (restituisce tutti gli archi)
    const set<unidirected_edge>& all_edges() const {
        return archi;
    }



    //metodo all_nodes (restituisce tutti i nodi)
    set<int> all_nodes() const{
        set<int> nodi;

        //cicliamo sulla mappa delle adiacenze
        //[nodo, vicini] è la struttura della mappa
        //itero per ogni struttura della mappa
        for (auto const& [nodo, vicini] : lista_adiacenza){
            nodi.insert(nodo);
        }
        return nodi;
    }



    //metodo edge_number (dato un arco, ne restituisce la sua numerazione all'interno del grafo)
    int edge_number(const unidirected_edge& a) const{
        int posizione = 0;
        for (const auto& corrente : archi){
            if (corrente == a){
                return posizione;
            }
            posizione++;
        }
        //se l'arco non esiste
        return -1;
    }



    //metodo edge_at (dato un numero d'arco, restituisce il corrispondente oggetto arco all'interno del grafo)
    unidirected_edge edge_at(int index) const{

        //uso un iteratore per muovermi nel set fino all'indice cercato
        //posiziono l'iteratore sul primo elemento del set
        auto it = archi.begin();
        if (index < 0 || index >= (int)archi.size()){
            cerr << "Errore: la posizione " << index << " non è nei limiti \n";
            return unidirected_edge(-1,-1);
        }
        for (int i=0; i<index; ++i){
            ++it;
        }
        return *it;
    }




    //operatore - che permette di fare la differenza tra due grafi (G1-G2) e produce come risultato gli archi presenti in G1 ma non in G2
    unidirected_graph operator - (const unidirected_graph& altro) const{
        unidirected_graph risultato;

        //per ogni arco del grafo G1
        for (const auto& a: this->archi){
            bool trovato = false;

            //cerco lo stesso arco nel grafo G2
            for (const auto& b : altro.archi){
                if (a == b){
                    trovato = true;
                    //se lo trovo smetto di cercare 
                    break;
                }
            }
            //se non l'ho trovato lo aggiungo al risultato
            if (!trovato){
                risultato.add_edge(a.from(), a.to());
            }
        }
        return risultato;
    }
};
