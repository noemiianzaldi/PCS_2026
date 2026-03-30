#include <iostream>
#include <concepts>

template <typename I>
requires std::integral<I>
class rational{
private:
    I numeratore_;
    I denominatore_;
    // creo la funzione di semplificazione
    void semplificazione() {
            if (denominatore_ == 0){
                return;
            }
            I a = numeratore_;
            I b = denominatore_;
            if (a<0){
                a = -a;
            }
            if (b<0){
                b = -b;
            }
            while (b != 0){
                I resto = a % b;
                a = b;
                b = resto;
            }
            I comune_divisore = a;
            // semplifichiamo la frazione con il MCD trovato
            if (comune_divisore != 0) {
                numeratore_ = numeratore_ / comune_divisore;
                denominatore_ = denominatore_ / comune_divisore;
            }
            if (denominatore_ < 0){
                numeratore_ = -numeratore_;
                denominatore_ = - denominatore_;
            }
        }
public: 
    // costruttore di default
    rational() { //inizializzo opportunatamente numeratore e denominatore
        numeratore_ = 0;
        denominatore_ = 1; 
    }
    // costruttore user-defined
    rational(const I& n, const I& d=1){ //inizializzo numeratore e denominatore con i valori specificati dall'utente
        if (d==0) { // il programma non esce con un errore ma gestisce i vari casi
            denominatore_ = 0;
            if (n==0) {
                numeratore_ = 0;
                return; // rappresenta 0/0: NaN (not a numer)
            }
            else {
                if (n>0){
                    numeratore_ = 1; // rappresenta n/0: +infinito
                }
                else {
                    numeratore_ = -1; // rappresenta -n/0: -infinito
                }
            }
        }
        else {
            // caso standard: semplifichiamo la frazione
            numeratore_ = n;
            denominatore_ = d;
            semplificazione();
            }
        }
    //metodi per ottenere numeratore e denominatore
    I num() const{
        return numeratore_;
    }
    I den() const{
        return denominatore_;
    }


//operazioni
//moltiplicazione *=
rational& operator *= (const rational& secondo_numero){
    numeratore_ *= secondo_numero.num(); //lo moltiplico per il denominatore del secondo numero
    denominatore_ *= secondo_numero.den(); //lo moltiplico per il numeratore del secondo numero
    semplificazione();
    return *this;
}

//divisione /=
rational& operator /= (const rational& secondo_numero){
    numeratore_ *= secondo_numero.den();
    denominatore_ *= secondo_numero.num();
    semplificazione();
    return *this;
}

//addizione +=
rational& operator += (const rational& secondo_numero){
    numeratore_ = (numeratore_ * secondo_numero.den()) + (secondo_numero.num()*denominatore_);
    denominatore_ *= secondo_numero.den();
    semplificazione();
    return *this;
}

//sottrazione -=
rational& operator -= (const rational& secondo_numero){
    numeratore_ = (numeratore_ * secondo_numero.den()) - (secondo_numero.num()*denominatore_);
    denominatore_ *= secondo_numero.den();
    semplificazione();
    return *this;
}

//addizione +
rational operator + (const rational& secondo_numero) const{
    rational risultato = *this; //copio il numero attuale
    risultato += secondo_numero;
    return risultato; //restituisco il risultato 
}

// sottrazione -
rational operator - (const rational& secondo_numero) const{
    rational risultato = *this; //copio il numero attuale
    risultato -= secondo_numero;
    return risultato; //restituisco il risultato 
}

//moltiplicazione *
rational operator * (const rational& secondo_numero) const{
    rational risultato = *this; //copio il numero attuale
    risultato *= secondo_numero;
    return risultato; //restituisco il risultato 
}

//divisione /
rational operator / (const rational& secondo_numero) const{
    rational risultato = *this; //copio il numero attuale
    risultato /= secondo_numero;
    return risultato; //restituisco il risultato 
}
};


// operatore << per la stampa di un oggettto della classe rational
template <typename I>
std::ostream& 
operator << (std::ostream& os, const rational<I>& r){
    if (r.den() == 0){
        if (r.num() == 0){
            os << "NaN";
        }
        else{
            if (r.num() > 0) {
                os << "+Inf";
            }
            else{
                os << "-Inf";
            }            
        } 
    } 
    else { //se il denominatore è 1 allora il numero è un intero
        if (r.den() == 1){ 
            os << r.num();
        }
        else{
            os << r.num() << "/" << r.den();
        }
    }    
    return os;
}


