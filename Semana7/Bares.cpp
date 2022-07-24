#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> v_bares;

int main() {
	int n_bares;
	ll max_garrafas;

	cin >> n_bares >> max_garrafas;

	for (int k = 0 ; k < n_bares ; k++){
		int aux;
		cin >> aux;

		v_bares.push_back(aux);
	}

	int i = 0;
	int j = 1;
	ll soma_local = v_bares[0];
	ll maior_s_l = v_bares[0];

	/*for (int k = 0 ; k < n_bares ; k++)
		cout << v_bares[k] << "	";
	cout << endl;*/

	while (j < n_bares){
		while ((soma_local + v_bares[j] > max_garrafas) && (i < j-1)){
			soma_local -= v_bares[i++];
			if ((soma_local > maior_s_l) && (soma_local <= max_garrafas))
				maior_s_l = soma_local;
		}

		if (soma_local < max_garrafas){
			soma_local += v_bares[j++];
			if ((soma_local > maior_s_l) && (soma_local <= max_garrafas))
				maior_s_l = soma_local;
		}

		if (maior_s_l == max_garrafas)
			break;
	}

	cout << maior_s_l << endl;
}