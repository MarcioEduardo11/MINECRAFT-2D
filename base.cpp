#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    srand (time(0));

    int linhas = 16;
    int colunas = 16;

    int gravetos = 0, pedras = 0, frutas = 0, animais = 0, arvores = 0;
    char resposta;

    char mapa [16] [16];

    for (int i =0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            int sorteio = rand() % 100;

            if (sorteio < 15){
                mapa [i] [j] = 'G';
            } else if (sorteio < 30) {
                mapa [i] [j] = 'P';
            }else if (sorteio <  40) {
                mapa [i] [j] = 'F';
            } else if (sorteio < 50) {
                mapa [i] [j] = 'A';
            } else if (sorteio < 65) {
                mapa [i] [j] = 'V';
            } else {
                mapa [i] [j] = '.';
            }
        }
    }

    int JogadorLinha = 8;
    int JogadorColuna = 8;
    mapa [JogadorLinha] [JogadorColuna] = '@';

    char movimento;
    bool jogando = true;

    int objetivo;

    cout << "Escolha seu objetivo:" <<endl;
    cout << "1. Luz e Calor (4 gravetos e 2 pedras)" << endl;
    cout << "2. Comida (1 fruta e 3 animais)" << endl;
    cout << "3. Construcao (8 pedras e 4 arvores)" << endl;
    cin >> objetivo;


    while (jogando) {

        cout << "INVENTÁRIO: ";
        cout << "Gravetos: " << gravetos << "";
        cout << "Pedras: " << pedras << " ";
        cout << "Frutas: " << frutas << " ";
        cout << "Animais: " << animais << " ";
        cout << "Árvores: " << arvores << endl;

        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                cout << mapa [i] [j] << " ";
            }
            cout << endl;
        }
    cout <<"\nMover (w=cima, s=baixo, a=esquerda, d=direita,): ";
    cin >> movimento;
    mapa[JogadorLinha] [JogadorColuna] = '.';
    if (movimento == 'w' && JogadorLinha > 0) {
        JogadorLinha--;
    } else if (movimento == 's' && JogadorLinha < linhas - 1) {
        JogadorLinha++;
    } else if (movimento == 'a' && JogadorColuna > 0) {
        JogadorColuna--;
    } else if (movimento == 'd' && JogadorColuna < colunas - 1) {
        JogadorColuna++;
    }
    char itemEncontrado = mapa[JogadorLinha] [JogadorColuna];

    if (itemEncontrado == 'G') cout << "Você encontrou um graveto! Coletar? (s/n)" << endl;
    else if (itemEncontrado == 'P') cout << "Você encontrou uma pedra! Coletar? (s/n)" << endl;
    else if (itemEncontrado == 'F') cout << "Você encontrou uma fruta! Coletar? (s/n)" << endl;
    else if (itemEncontrado == 'A') cout << "Você encontrou um animal! Coletar? (s/n)" << endl;
    else if (itemEncontrado == 'V') cout << "Você encontrou uma árvore! Coletar? (s/n)" << endl;
    cin >> resposta;

    if (resposta == 's') {
        if (itemEncontrado == 'G') gravetos++;
        if (itemEncontrado == 'P') pedras++;
        if (itemEncontrado == 'F') frutas++;
        if (itemEncontrado == 'A') animais++;
        if (itemEncontrado == 'V') arvores++;
    }
    mapa[JogadorLinha] [JogadorColuna] = '@';

    if (objetivo == 1 && gravetos >= 4 && pedras >= 2) {
        jogando = false;
    }else if (objetivo == 2 && frutas >= 1 && animais >= 3) {
        jogando = false;
    } else if (objetivo == 3 && pedras >= 8 && arvores >= 4) {
        jogando = false;
    }
}
    cout << "Parabens! Voce alcancou seu objetivo!" << endl;

    for (int i =0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cout << mapa [i] [j] << " ";
        }
        cout << endl;
    }

    return 0;
}