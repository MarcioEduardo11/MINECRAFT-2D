#include <iostream>
using namespace std;

int main() {
    int linhas = 16;
    int colunas = 16;

    char mapa [16] [16];

    for (int i =0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            mapa [i] [j] = '.';
        }
    }


    for (int i =0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cout << mapa [i] [j] << " ";
        }
        cout << endl;
    }

    return 0;
}