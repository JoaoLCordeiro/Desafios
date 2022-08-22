#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> pedidos;

void imprime_vetor (){
	for (auto a : pedidos)
		cout << "{" << a.first << ", " << a.second << "} ";
	cout << endl << endl;
}

int main(){
	int l,r;
	cin >> l >> r;
	while (l != 0){
		pedidos.push_back(make_pair(l,r));
		cin >> l >> r;
	}

	for (auto a = pedidos.begin() ; a < pedidos.end() ; a++){
		imprime_vetor ();
		pedidos.erase(a);
	}
}