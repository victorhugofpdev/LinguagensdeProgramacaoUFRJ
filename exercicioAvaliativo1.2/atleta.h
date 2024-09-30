

#include <iostream>
#include <vector>
#include <numeric> // para std::accumulate
#include <algorithm> // para std::min_element

using namespace std;

class Atleta {
private:
    string nome;
    vector<double> tempos;

public:
    Atleta(string nome, const vector<double>& tempos) : nome(nome), tempos(tempos) {}

    double calculaMediaPorTemporada() const {
        if (tempos.empty()) {
            cerr << "Nenhum tempo registrado para este atleta." << endl;
            return 0.0;
        }
        
        double soma = accumulate(tempos.begin(), tempos.end(), 0.0);
        double media = soma / tempos.size();
        return media;
    }
    string getNome() const {
        return nome;
    }

    double mediaMovel(int N) const {
        if (N < 3 || N > 7 || N == 5) {
            cerr << "Erro: N deve ser entre 3 e 7, exceto 5." << endl;
            return -1; // Retorno de erro
        }
        
        int size = tempos.size();
        if (N > size) {
            cerr << "Erro: Não há suficientes tempos registrados para calcular a média móvel com N=" << N << "." << endl;
            return -1;
        }
        
        double soma = accumulate(tempos.end() - N, tempos.end(), 0.0);
        return soma / N;
    }

    void mostraTempos() const {
        for (size_t i = 0; i < tempos.size(); ++i) {
            cout << tempos[i] << " ";
        }
        cout << endl;
    }

    void adicionaTempo(double tempo) {
        tempos.push_back(tempo);
    }

    double preverProximoTempo() const {
        int n = tempos.size();
        if (n < 2) return tempos.back();

        double sum_x = 0, sum_y = 0, sum_xy = 0, sum_xx = 0;
        for (int i = 0; i < n; ++i) {
            sum_x += i;
            sum_y += tempos[i];
            sum_xy += i * tempos[i];
            sum_xx += i * i;
        }

        double slope = (n * sum_xy - sum_x * sum_y) / (n * sum_xx - sum_x * sum_x);
        double intercept = (sum_y - slope * sum_x) / n;

        return slope * n + intercept;
    }

    const vector<double>& getTempos() const {
        return tempos;
    }
};

