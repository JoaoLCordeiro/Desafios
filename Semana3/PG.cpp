#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll acha_razao (vector<ll> v_termos){
	ll razao1 = v_termos[1]/v_termos[0];
	ll razao2 = v_termos[2]/v_termos[1];
	ll razao3 = v_termos[3]/v_termos[2];

	if ((razao1 == razao2) || (razao1 == razao3))
		return razao1;
	else
		return razao2;
}

int main() {
    int n_termos;
    cin >> n_termos;

    vector<ll> v_termos;

    for (int i = 0 ; i < n_termos ; i++){
        ll aux;
        cin >> aux;

        v_termos.push_back(aux);
    }

	//if (v_termos[0] > v_termos[1]){		//sequencia decrescente
		sort(v_termos.begin(), v_termos.end(), less<ll>());
	//}

	ll razao = acha_razao (v_termos);

	for (int i = 0 ; i < n_termos-1 ; i++){
		if (v_termos[i+1] != v_termos[i] * razao){
			cout << v_termos[i] * razao << "\n";		//achou o termo faltante dentro da progressao
			return(0);
		}
	}

	//o termo está fora da progressao dada

	if ((razao != 1) && (v_termos[0] % razao == 0)){
		cout << v_termos[0] / razao << "\n";
	}

	cout << v_termos[n_termos-1] * razao << "\n";
}