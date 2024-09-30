#include <iostream>
#include "treinador.h"

using namespace std;

void exibirMenu() {
    cout << endl;
    cout << "Menu:\n";
    cout << "1. Exibir media dos últimos N treinos\n";
    cout << "2. Prever o tempo do próximo treino\n";
    cout << "3. Ordenar Media por temporada\n";
    cout << "4. Ordenar atletas pelo melhor tempo\n";
    cout << "5. Verificar se houve melhoria significativa\n";
    cout << "6. Sair\n";
}

int main() {
    Treinador treinador;

    vector<double> tempos1;
    tempos1.push_back(10.9);
    tempos1.push_back(10.5);
    tempos1.push_back(10.6);
    tempos1.push_back(10.1);
    tempos1.push_back(5.0);
    tempos1.push_back(10.9);
    tempos1.push_back(10.0);

    vector<double> tempos2;
    tempos2.push_back(11.2);
    tempos2.push_back(10.8);
    tempos2.push_back(10.7);
    tempos2.push_back(10.9);
    tempos2.push_back(23.0);
    tempos2.push_back(10.9);
    tempos2.push_back(15.0);

    vector<double> tempos3;
    tempos3.push_back(10.0);
    tempos3.push_back(9.9);
    tempos3.push_back(10.2);
    tempos3.push_back(10.3);
    tempos3.push_back(10.1);
    tempos3.push_back(10.9);
    tempos3.push_back(11.0);

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
                if (N>=3 && N<=7)
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
                treinador.mediaTemporada();
            case 4:
                treinador.ordenarPorMelhorTempo();
                break;
            case 6:
                cout << "Saindo...\n";
                break;
            case 5:
                cout << "Digite o valor de N para verificar a melhoria: ";
                cin >> N;
                treinador.exibirMelhoriaDesempenho(N);
                break;
            default:
                cout << "Opção inválida!\n";
        }

    } while (opcao != 5);

    return 0;
}
