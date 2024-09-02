#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // para a função std::max

using namespace std;

class Veiculo {
private:
    string nome;
    vector<int> resultados; // Armazena as posições alcançadas nas competições

public:
    Veiculo(string nome, vector<int> resultados) : nome(nome), resultados(resultados) {}

    string getNome() const {
        return nome;
    }

    int getMelhorResultado() const {
        // Retorna o melhor (menor) resultado alcançado
        return *min_element(resultados.begin(), resultados.end());
    }

    int getPontuacaoTotal() const {
        int pontuacaoTotal = 0;
        for (int resultado : resultados) {
            int pontos = max(10 - (resultado - 1), 0);
            pontuacaoTotal += pontos;
        }
        return pontuacaoTotal;
    }
};

class Tabela {
private:
    vector<Veiculo> veiculos;

public:
    void adicionarVeiculo(const Veiculo& veiculo) {
        veiculos.push_back(veiculo);
    }

    void imprimirMelhorResultado(const string& nomeVeiculo) const {
        for (const Veiculo& veiculo : veiculos) {
            if (veiculo.getNome() == nomeVeiculo) {
                cout << "Melhor resultado do veículo " << nomeVeiculo << ": "
                     << veiculo.getMelhorResultado() << endl;
                cout << "Pontuação total: " << veiculo.getPontuacaoTotal() << endl;
                return;
            }
        }
        cout << "Veículo " << nomeVeiculo << " não encontrado na tabela." << endl;
    }
};

int main() {
    // Criando alguns veículos com resultados simulados
    Veiculo veiculo1("CarroA", {1, 2, 3, 1, 4});
    Veiculo veiculo2("CarroB", {2, 3, 4, 2, 5});
    Veiculo veiculo3("CarroC", {3, 4, 5, 3, 6});

    // Criando a tabela e adicionando os veículos
    Tabela tabela;
    tabela.adicionarVeiculo(veiculo1);
    tabela.adicionarVeiculo(veiculo2);
    tabela.adicionarVeiculo(veiculo3);

    // Imprimindo os melhores resultados e pontuações
    tabela.imprimirMelhorResultado("CarroA");
    tabela.imprimirMelhorResultado("CarroB");
    tabela.imprimirMelhorResultado("CarroC");

    return 0;
}