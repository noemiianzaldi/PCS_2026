#include <iostream>
using namespace std;

int main(int argc, const char *argv[]){
    cout << "numero di paramentri: " << argc << "\n";
    for (int i=0; i<argc; i++){
        cout << "Paramentro" << i << "=" << argv[i] << "\n";
    }
    return 0;
}