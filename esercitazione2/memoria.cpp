# include <iostream>

int main(){
    double ad[4] = {0.0, 1.1, 2.2, 3.3}; //in memoria viene salvato all'indirizzo 0x16b9572b0
    float af[8] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7}; //in memoria viene salvato all'indirizzo 0x16b957290
    int ai[3] = {0, 1, 2}; //in memoria viene salvato all'indirizzo 0x16b957280

    int x = 1;
    float y = 1.1;

    (&y)[1] = 0; // &y prende l'indirizzo di y; [1] si traduce come: vai all'indirizzo di y + (i(=1) * (dimensione del tipo)) ma a quell'indirizzo c'è x che diventa = 0

   
    std::cout << x << "\n";
    std::cout << &x << "\n";; // stampa l'indirizzo di x
    std::cout << &y << "\n"; // stampa l'indirizzo di y
    
    return 0;   
}