#include <fstream>
#include <iosream>
using namespace std;

int main(void) {
	cout << "Inserisci il nome del file: \n";
	string nome_file;
	cin >> nome_file;
	ifstream ifs(nome_file);
	if ( ifs.is_open() {
		while( !ifs.eof() ) {
			string luogo;
			double t1, t2, t3, t4;
			while (ifs >> luogo >> t1 >> t2 >> t3 >> t4) {
				double media = (t1 + t2 + t3 +t4) / 4.0;
				cout << luogo << media << "\n";
			}
		}
	}
	return 0;
}