#include <bits/stdc++.h>
using namespace std;
using matrizint = vector<vector<int>>;

const int MAXLINHAS = log2(1123456789) + 1;

void monta_matriz (matrizint &m, int n){
	for (int linha = 1 ; linha <= MAXLINHAS ; linha++)
		for (int coluna = 1 ; coluna <= n ; coluna++){
			//cout << "vai escrever na m[" << linha << "," << coluna << "] o m[" << linha-1 << "," <<  m[linha-1][coluna] << "]" << endl;
			m[linha][coluna] = m[linha-1][m[linha-1][coluna]];
		}
}

int viaja (matrizint &m, int origem, int viagens){
	int planeta = origem;
	for (int i = MAXLINHAS ; i >= 0 ; i--)
		if (viagens & (1 << i)){
			//cout << "viajou do planeta " << planeta << " pro " << m[i][planeta] << " pulando n log 2 = " << i << " passos" << endl;
			planeta = m[i][planeta];
		}

	return planeta;
}

int main() {
	int n_planetas, n_consultas;
	cin >> n_planetas >> n_consultas;

	matrizint matriz_tp (MAXLINHAS+1, vector<int> (n_planetas+1));

	for (int planeta = 1 ; planeta <= n_planetas ; planeta++){
		int destino;
		cin >> destino;

		matriz_tp[0][planeta] = destino;
	}

	monta_matriz(matriz_tp, n_planetas);
	
	for (int consulta = 1 ; consulta <= n_consultas ; consulta++){
		int origem, viagens;
		cin >> origem >> viagens;

		int destino = viaja (matriz_tp, origem, viagens);
		cout << destino << endl;
	}
}