#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll trocas = 0;

void merge_sort (int comeco, int fim, vector<ll>& v_participantes){
	int delta = fim - comeco;

	if (delta == 1){
		return;
	}

	int meio = comeco + delta/2;

	merge_sort (comeco, meio, v_participantes);
	merge_sort (meio  , fim , v_participantes);

	vector<ll> aux (delta);

	int i = comeco;
	int j = meio;

	for (int k = 0 ; k < delta ; k++){
		if ((i < meio) && (j < fim)){
			if (v_participantes[i] < v_participantes[j]){
				aux[k] = v_participantes[i];
				i++;
			}
			else{
				aux[k] = v_participantes[j];
				j++;
				trocas += meio - i;
			}
		}
		else{
			if (i < meio){
				aux[k] = v_participantes[i];
				i++;
			}
			else{
				aux[k] = v_participantes[j];
				j++;
			}
		}
	}

	//copia do aux pro original
	copy (aux.begin(), aux.end(), v_participantes.begin()+comeco);
}

void imprime_vetor (vector<ll> vetor, int n){
	cout << endl;
	for (int i = 0 ; i < n ; i++)
		cout << vetor[i] << " ";
	cout << endl;
}

int main() {
	int n_participantes, n_pontuais;
	cin >> n_participantes >> n_pontuais;

	vector<ll> v_participantes;

	for (int i = 0 ; i < n_pontuais ; i++){
		int aux;
		cin >> aux;

		v_participantes.push_back(aux);
	}

	sort (v_participantes.begin(), v_participantes.end(), less<int>());

	//imprime_vetor (v_participantes, n_pontuais);

	for (int i = n_pontuais ; i < n_participantes ; i++){
		int aux;
		cin >> aux;

		v_participantes.push_back(aux);
	}

	merge_sort (0, n_participantes, v_participantes);

	//imprime_vetor (v_participantes, n_participantes);

	cout << trocas << endl;
}