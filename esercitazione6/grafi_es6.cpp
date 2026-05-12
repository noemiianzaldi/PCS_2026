#include <iostream>
#include "grafi.hpp"

using namespace std;

int main(){
    unidirected_edge a0(7,5);
    unidirected_edge a1(5,3);
    unidirected_edge a2(2,9);
    unidirected_edge a3(9,2);
    unidirected_edge a4(4,9);
    unidirected_edge a5(4,5);
    unidirected_edge a6(3,8);
    unidirected_edge a7(8,2);
    unidirected_edge a8(3,2);
    unidirected_edge a9(7,3);

    set<unidirected_edge> set_di_test;
    set_di_test.insert(a0);
    set_di_test.insert(a1);
    set_di_test.insert(a2);
    set_di_test.insert(a3);
    set_di_test.insert(a4);
    set_di_test.insert(a5);
    set_di_test.insert(a6);
    set_di_test.insert(a7);
    set_di_test.insert(a8);
    set_di_test.insert(a9);

    cout << "l'arco (7,5) viene rappresentato nel seguente modo: " << a0 << "\n";
    
    //verifico che l'arco a1 (5,3) è minore sia dell'arco a6 (3,8) sia dell'arco a4 (4,9) ma non dell'arco a3 (2,9)
    if (a1 < a6){
        cout << a1 << " < " << a6 << "\n";
    }
    if (a1 < a4){
        cout << a1 << " < " << a4 << "\n";
    }
    if (a1 < a3){
        cout << a1 << " < " << a3 << "\n";
    }
    else{
        cout << a1 << " > " << a3 << "\n";
    }

    cout << "\n";

    //verifico che i due archi (2,9) e (9,2) sono uguali
    if (a2==a3){
        cout << a2 << " = " << a3 << "\n";
    }

    cout << "\n";

    //creo il grafo inserendo gli archi definiti sopra
    unidirected_graph g;
    for (const auto& arco : set_di_test) {
        g.add_edge(arco.from(), arco.to());
    }

    //archi e nodi presenti nel grafo g
    const auto archi = g.all_edges();
    int numero = archi.size();
    auto nodes = g.all_nodes();

    //nodi adiacenti al nodo 3 e al nodo 8
    auto nodivicini_3 = g.neighbours(3);
    auto nodivicini_8 = g.neighbours(8);

    //posizione dell'arco a7 e dell'arco a0
    auto posizione = g.edge_number(a7);
    auto poss = g.edge_number(a0);

    //arco alla posizione 5 
    auto arco = g.edge_at(5);

    // aggiungo al grafo degli archi
    g.add_edge(7,4);
    g.add_edge(8,4);
    g.add_edge(2,6);
    g.add_edge(6,3);

    //archi e nodi presenti nel grafo g aggiornato
    const auto edges = g.all_edges();
    int num = edges.size();
    auto nodes_new = g.all_nodes();

    //nodi adiacenti al nodo 3 e al nodo 8 nel grafo aggiornato
    auto nodivicini_3_new = g.neighbours(3);
    auto nodivicini_8_new = g.neighbours(8);

    //posizione dell'arco a7 e dell'arco a0 nel grafo aggiornato
    auto p = g.edge_number(a7);
    auto pos = g.edge_number(a0);

    //arco alla posizione 5 nel grafo aggiornato
    auto arcoo = g.edge_at(5);

    //visualizzo in ordine gli archi presenti nel grafo iniziale
    cout << "Gli archi presenti nel grafo g iniziale sono: \n";
    for (const auto& a: archi){
        cout << a << "\n";
    }

    cout << "\n";

    //verifico che siano stati aggiunti correttamente ristampando tutti gli archi
    cout << "Gli archi presenti nel grafo dopo averne aggiunti alcuni sono: \n";
    for (const auto& a: edges){
        cout << a << "\n";
    }

    cout << "\n";

    cout << "il numero totale ora di archi è: " << num <<", mentre prima era: " << numero << "\n";

    cout << "\n";

    //viuslizzo i nodi nel grafo g
    cout << "I nodi presenti nel grafo iniziale sono: " << nodes.size() << " cioè: \n";
    for (int nodo : nodes){
        cout << nodo << "\n";
    }
    cout << "Invece i nodi presenti nel grafo aggiornato sono: " << nodes_new.size() << " cioè: \n";
    for (int nodo : nodes_new){
        cout << nodo << "\n";
    }

    cout << "\n";

    //visulizzo i nodi adiacenti al nodo 3 prima e dopo l'aggiornamento del grafo
    cout << "I nodi adiacenti al nodo 3 nel grafo iniziale sono: \n";
    for (int vicino : nodivicini_3){
        cout << vicino << "\n";
    }
    cout << "Mentre i nodi adiacenti al nodo 3 dopo l'aggiornamneto sono: \n";
    for (int vicino : nodivicini_3_new){
        cout << vicino << "\n";
    }

    cout << "\n";

    //visulizzo i nodi adiacenti al nodo 8 prima e dopo l'aggiornamento del grafo
    cout << "I nodi adiacenti al nodo 8 nel grafo iniziale sono: \n";
    for (int vicino : nodivicini_8){
        cout << vicino << "\n";
    }
    cout << "Mentre i nodi adiacenti al nodo 8 dopo l'aggiornamneto sono: \n";
    for (int vicino : nodivicini_8_new){
        cout << vicino << "\n";
    }

    cout << "\n";

    //dato un arco, visualizzo la sua posizione
    cout << "L'arco " << a7 << " nel grafo iniziale si trovava nella posizione numero: " << posizione + 1 << "\n";
    cout << "Dopo l'aggiornamento del grafo, l'arco " << a7 << " si trova nella posizione numero: " << p +1 << "\n";

    cout << "\n";

    cout << "L'arco " << a0 << " nel grafo iniziale si trovava nella posizione numero: " << poss + 1 << "\n";
    cout << "Dopo l'aggiornamento del grafo, l'arco " << a0 << " si trova nella posizione numero: " << pos +1 << "\n";

    cout << "\n";

    //dato una posizione di un arco, visualizzo l'arco corretto
    cout << "Nel grafo iniziale l'arco nella posizione 6 era: " << arco << "\n";
    cout << "Mentre dopo l'aggiornamneto, l'arco nella posizione 6 è il seguente: " << arcoo << "\n";

    cout << "\n";

    //verifico che data una posizione non valida, venga gestito correttamente l'errore
    auto ar = g.edge_at(20);
    

    cout << "\n";
    
    //creo un altro grafo
    unidirected_graph g2;
    g2.add_edge(2,6);
    g2.add_edge(8,6);
    g2.add_edge(2,9);
    g2.add_edge(2,4);
    g2.add_edge(5,3);
    g2.add_edge(8,7);
    g2.add_edge(1,6);
    g2.add_edge(3,6);

    auto diff = g-g2;
    //visualizzo gli archi differenti dal grafo g al grafo g2
    cout << "Dati i seguenti grafi: \n";
    cout << "grafo g: \n";
    for (const auto& a: edges){
        cout << a << "\n";
    }
    cout << "grafo g2: \n";
    const auto ed = g2.all_edges();
    for (const auto& a: ed){
        cout << a << "\n";
    }
    cout << "\n";
    cout << "g-g2 contiene i seguenti archi: \n";
    for (const auto& a: diff.all_edges()){
        cout << a << "\n";
    }
    return 0;
}