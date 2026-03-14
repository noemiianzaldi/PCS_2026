#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char *argv[]) {
	if (argc >= 2){ 
		string name_file = argv[1]; // il nome del file è scritto come secondo paramentro dall'utente
		ifstream file_input(name_file); // apro il file in modalità lettura
		if (file_input.is_open()){ // verifico se il file è stato aperto correttamente
			string città;
			double t1, t2, t3, t4; 
			for (int i=0; i<3; i++){ 
				if (file_input >> città >> t1 >> t2 >> t3 >> t4){
				double media = (t1+t2+t3+t4)/4.0; //calcolo la media dei 4 numeri letti per ogni città
				cout << città << " " << media << "\n"; //stampo il nome della città con la sua
				}
			}
		}
		else {
			cerr << "Errore: Il nome del file non esiste o non può essere aperto correttamente. \n";
			return 1;
		}
	}
	else {
		cerr << "Errore: Il file non è stato dichiarato come paramentro. \n";
		return 1;
	}
	return 0;
}	