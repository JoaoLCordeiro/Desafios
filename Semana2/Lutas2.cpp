#include <bits/stdc++.h>
using namespace std;

int main() {
	int n_participantes;
	int n_vagas;

	cin >> n_participantes >> n_vagas;

	priority_queue<tuple<int,int,int,int,int>,
	vector<tuple<int,int,int,int,int>>,
	less<tuple<int,int,int,int,int>>> fila;

	for (int i = 0 ; i < n_participantes ; i++){
		string luta;
		int horas;
		char dois_ponto;
		int minutos;
		int anos;
		int classificacao;

		cin >> luta >> horas >> dois_ponto >> minutos >> anos >> classificacao;
		classificacao *= -1;

		tuple<int,int,int,int,int> tupla;

		if ((luta == "idjassu") || (luta == "galhofa") || (luta == "aipenkuit")){
			if (horas >= 13)
				tupla = make_tuple(1,1,anos,classificacao,i+1);				//primeiro elemento da tupla é 1 caso lute IGA, 0 caso contrário
			else															//segundo elemento da tupla é 1 caso lute a tarde ou noite, 0 caso contrário
				tupla = make_tuple(1,0,anos,classificacao,i+1);
		}
		else{
			if (horas >= 13)
				tupla = make_tuple(0,1,anos,classificacao,i+1);
			else
				tupla = make_tuple(0,0,anos,classificacao,i+1);
		}

		fila.push(tupla);
	}

	for (int i = 0 ; i < n_vagas ; i++){
		cout << get<4>(fila.top()) << "\n";
		fila.pop();
	}
}