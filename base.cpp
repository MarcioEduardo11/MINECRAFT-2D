#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int LINHAS = 12;
const int COLUNAS = 21;

char mundo[LINHAS][COLUNAS];

int playerX = 0;
int playerY = 0;

void gerarMapa() {

    for(int y = 0; y < LINHAS; y++) {

        for(int x = 0; x < COLUNAS; x++) {

            int r = rand() % 100;

            if(r < 15)
                mundo[y][x] = 'G';

            else if(r < 30)
                mundo[y][x] = 'P';

            else if(r < 40)
                mundo[y][x] = 'F';

            else if(r < 50)
                mundo[y][x] = 'A';

            else if(r < 65)
                mundo[y][x] = 'T';

            else
                mundo[y][x] = '.';
        }
    }

    mundo[playerY][playerX] = 'X';
}

void mostrarMapa() {

    for(int y = 0; y < LINHAS; y++) {

        for(int x = 0; x < COLUNAS; x++) {

            cout << mundo[y][x] << " ";
        }

        cout << endl;
    }
}

int main() {
    int playerX = 0;
      int playerY = 0;

    srand(time(0));

    gerarMapa();

    char comando;

    while(true) {

        system("cls");

        mostrarMapa();

        cin >> comando;

        mundo[playerY][playerX] = '.';

        if(comando == 'w' && playerY > 0)
            playerY--;

        if(comando == 's' && playerY < LINHAS - 1)
            playerY++;

        if(comando == 'a' && playerX > 0)
            playerX--;

        if(comando == 'd' && playerX < COLUNAS - 1)
            playerX++;

        mundo[playerY][playerX] = 'X';
    }

    return 0;
}