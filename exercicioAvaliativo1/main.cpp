#include <iostream>
#include "treinador.h"

using namespace std;

void exibirMenu() {
    cout << endl;
    cout << "Menu:\n";
    cout << "1. Exibir média móvel dos últimos N treinos\n";
    cout << "2. Prever o tempo do próximo treino\n";
    cout << "3. Ordenar atletas pelo melhor tempo\n";
    cout << "4. Sair\n";
}

int main() {
    Treinador treinador;

    // Criando alguns atletas com tempos fictícios
    vector<double> tempos1;
    tempos1.push_back(10.9);
    tempos1.push_back(10.5);
    tempos1.push_back(10.6);
    tempos1.push_back(10.1);
    tempos1.push_back(10.2);

    vector<double> tempos2;
    tempos2.push_back(11.2);
    tempos2.push_back(10.8);
    tempos2.push_back(10.7);
    tempos2.push_back(10.9);
    tempos2.push_back(11.0);

    vector<double> tempos3;
    tempos3.push_back(10.0);
    tempos3.push_back(9.9);
    tempos3.push_back(10.2);
    tempos3.push_back(10.3);
    tempos3.push_back(10.1);

    treinador.adicionarAtleta(Atleta("Atleta 1", tempos1));
    treinador.adicionarAtleta(Atleta("Atleta 2", tempos2));
    treinador.adicionarAtleta(Atleta("Atleta 3", tempos3));

    int opcao, N;

    do {
        exibirMenu();
        cin >> opcao;

        switch(opcao) {
            case 1:
                cout << "Digite o valor de N para a média móvel: ";
                cin >> N;
                if (N>0 && N<=7)
                    treinador.mostrarMediasMoveis(N);
                else{
                    cout << endl;
                    cout << "Número invalido, por favor digite um valor entre 0 e 8 (exclusos 0 e 8)" << endl;
                    return main();
                }
                break;
            case 2:
                treinador.mostrarPrevisaoProximoTreino();
                break;
            case 3:
                treinador.ordenarPorMelhorTempo();
                break;
            case 4:
                cout << "Saindo...\n";
                break;
            default:
                cout << "Opção inválida!\n";
        }

    } while (opcao != 4);

    return 0;
}
