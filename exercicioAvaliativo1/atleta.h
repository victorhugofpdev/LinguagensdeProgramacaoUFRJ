#ifndef ATLETA_H
#define ATLETA_H

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

    string getNome() const {
        return nome;
    }

    double mediaMovel(int N) const {
        int size = tempos.size();
        if (N > size) N = size;
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

#endif
