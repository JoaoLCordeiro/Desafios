#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll acha_lucro (int n_paes,int  n_hamburguer,int  n_filet,int  preco_h,int  preco_f){
	n_paes = n_paes/2;		//quantia de sanduiche fazíveis de acordo com os paes
	if (preco_h > preco_f){
		if (n_paes > n_hamburguer){
			n_paes -= n_hamburguer;
			if (n_paes > n_filet)
				return ((ll)(n_hamburguer*preco_h + n_filet*preco_f));
			else
				return ((ll)(n_hamburguer*preco_h + n_paes*preco_f));
		}
		else
			return ((ll) n_paes * preco_h);
	}
	else{
		if (n_paes > n_filet){
			n_paes -= n_filet;
			if (n_paes > n_hamburguer)
				return ((ll)(n_filet*preco_f + n_hamburguer*preco_h));
			else
				return ((ll)(n_filet*preco_f + n_paes*preco_h));
		}
		else
			return ((ll) n_paes * preco_f);
	}
}

int main(){
	int n;
	cin >> n;

	for (int i = 0 ; i < n ; i++){
		int n_paes, n_hamburguer, n_filet, preco_h, preco_f;

		cin >> n_paes >> n_hamburguer >> n_filet >> preco_h >> preco_f;

		cout << acha_lucro (n_paes, n_hamburguer, n_filet, preco_h, preco_f) << "\n";
	}
}