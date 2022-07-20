#include <bits/stdc++.h>
using namespace std;

int filho_esq (int pai){
	return (pai*2 + 1);
}

int filho_dir (int pai){
	return ((pai+1)*2);
}

int pai (int filho){
	return ((filho-1)/2);
}

void add (int num, int indice, vector<int>& tree_interv, int comeco, int fim, int i_arvore){
	if (num == 0)
		tree_interv[i_arvore] = 0;
	else{
		if (tree_interv[i_arvore] != 0)
			if (num < 0)
				tree_interv[i_arvore] *= -1;
	}
	//se o tree_interv[i_arvore] for 0 nao faz nada

	if (comeco == fim)
		return;

	int meio = comeco + (fim - comeco)/2;
	if (indice <= meio)
		add (num, indice, tree_interv, comeco, meio, filho_esq(i_arvore));
	else
		add (num, indice, tree_interv, meio+1, fim, filho_dir(i_arvore));
}

void change (int num, int indice, vector<int>& tree_interv, int comeco, int fim, int i_arvore){
	//quando chega em uma folha, no intervalo único do elemento
	if (comeco == fim){
		if (num == 0)
			tree_interv[i_arvore] = 0;
		else if (num > 0)
			tree_interv[i_arvore] = 1;
		else
			tree_interv[i_arvore] = -1;

		return;
	}

	//para os galhos
	int meio = comeco + (fim - comeco)/2;

	//galho da esquerda
	if (indice <= meio)
		change (num, indice, tree_interv, comeco, meio, filho_esq(i_arvore));
	//galho da direita
	else
		change (num, indice, tree_interv, meio+1, fim, filho_dir(i_arvore));

	tree_interv[i_arvore] = tree_interv[filho_esq(i_arvore)] * tree_interv[filho_dir(i_arvore)];
	return;
}

int get (vector<int>& tree_interv, int i1, int i2, int comeco, int fim, int i_arv){
	//se chegou no intervalo requerido, devolve
	if ((comeco == i1) && (fim == i2))
		return (tree_interv[i_arv]);

	int meio = comeco + (fim - comeco)/2;

	//se o intervalo ta pra direita
	if (i1 > meio)
		return (get(tree_interv, i1, i2, meio+1, fim, filho_dir(i_arv)));
	//se o intervalo ta pra esquerda
	else if (i2 <= meio)
		return (get(tree_interv, i1, i2, comeco, meio, filho_esq(i_arv)));
	//quando dividimos o intervalo em duas buscas
	else
		return (get(tree_interv, i1, meio, comeco, meio, filho_esq(i_arv)) * get(tree_interv, meio+1, i2, meio+1, fim, filho_dir(i_arv)));

}

void imprime_arvore (vector<int>& tree_interv, int n_elementos, vector<int>& v_elementos){
	int elevado = 0;
	for (int i = 1 ; i < pow(2,(n_elementos-1)) ; i++){
		if (i == pow(2, elevado)){
			cout << endl;
			elevado++;
		}
		cout << tree_interv[i-1] << "	";
	}
	cout << endl << endl;

	for (int i = 0 ; i < n_elementos ; i++)
		cout << v_elementos[i] << "	";
	cout << endl << endl;
}

int main() {
	int n_elementos, n_consultas;
	cin >> n_elementos >> n_consultas;

	vector<int> v_elementos (n_elementos, 1);
	vector<int> tree_interv (4*n_elementos, 1);

	for (int i = 0 ; i < n_elementos ; i++){
		int num;
		cin >> num;
		v_elementos[i] = num;

		add (num, i, tree_interv, 0, n_elementos-1, 0);
	}

	for (int i = 0 ; i < n_consultas ; i++){
		//imprime_arvore (tree_interv, n_elementos, v_elementos);

		char opcode;
		cin >> opcode;

		if (opcode == 'A'){
			int indice, num;
			cin >> indice >> num;

			change (num, (indice-1), tree_interv, 0, n_elementos-1, 0);
			v_elementos[indice-1] = num;
		}
		else{
			int i1, i2;
			cin >> i1 >> i2;

			int resultado = get (tree_interv, i1-1, i2-1, 0, n_elementos-1, 0);

			if (resultado == 1)
				cout << '+';
			else if (resultado == -1)
				cout << '-';
			else if (resultado == 0)
				cout << '0';
			/*else
				cout << "ERRO";*/
		}
	}

	cout << endl;
}
