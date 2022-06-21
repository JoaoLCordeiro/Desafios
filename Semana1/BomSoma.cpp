#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int n;
	while (cin >> n){

		vector<ll> vetor (n, 0);

		for (int i=0 ; i<n ; i++)
			cin >> vetor[i];

		int n2 = n/2;
		ll aux;
		ll soma = 0;
		for (int i=0 ; i<n2 ; i++){
			cin >> aux;
			soma += abs(aux - (vetor[i] + vetor[vetor.size()-1-i]));
		}

		cout << soma << "\n";
	}
}
