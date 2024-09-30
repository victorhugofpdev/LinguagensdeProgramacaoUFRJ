
#include "atleta.h"
#include <vector>
#include <algorithm>

using namespace std;


class Treinador {
private:
    vector<Atleta> atletas;

    static bool compararTempos(const Atleta& a, const Atleta& b) {
        return *min_element(a.getTempos().begin(), a.getTempos().end()) <
               *min_element(b.getTempos().begin(), b.getTempos().end());
    }

public:
    void exibirMelhoriaDesempenho(int N) const {
        const double LIMIAR_MELHORIA = 0.1; // 10%

        for (size_t i = 0; i < atletas.size(); ++i) {
            double mediaRecente = atletas[i].mediaMovel(N);
            double mediaAnterior = atletas[i].mediaMovel(N - 1); 

            double razao = (mediaAnterior - mediaRecente) / mediaAnterior;

            if (razao >= LIMIAR_MELHORIA) {
                cout << "Atleta: " << atletas[i].getNome() << " teve piora de desempenho." << endl;
            } else if (razao <= -LIMIAR_MELHORIA) {
                cout << "Atleta: " << atletas[i].getNome() << " teve melhora de desempenho." << endl;
            } else {
                cout << "Atleta: " << atletas[i].getNome() << " teve desempenho estável." << endl;
            }
        }
    }

    void adicionarAtleta(const Atleta& atleta) {
        atletas.push_back(atleta);
    }

    void mostrarMediasMoveis(int N) const {
        for (size_t i = 0; i < atletas.size(); ++i) {
            cout << "Atleta: " << atletas[i].getNome() << " - Media Movel: " << atletas[i].mediaMovel(N) << endl;
        }
    }

    void mostrarPrevisaoProximoTreino() const {
        for (size_t i = 0; i < atletas.size(); ++i) {
            cout << "Atleta: " << atletas[i].getNome() << " - Previsao do proximo tempo: " << atletas[i].preverProximoTempo() << endl;
        }
    }

    void ordenarPorMelhorTempo() {
        sort(atletas.begin(), atletas.end(), compararTempos);

        cout << "Atletas ordenados pelos melhores tempos:\n";
        for (size_t i = 0; i < atletas.size(); ++i) {
            cout << atletas[i].getNome() << endl;
        }
    }
    void mediaTemporada(){
        
    }
};