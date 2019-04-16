#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;

vector<int> labirinto[30];
int theseu, minotauro, k, k_atual;

void leitura(char inicio)
{
	int n = inicio - 65;
	char c;
	cin >> c;
	//cout << "inicio " << inicio << "separador " << c << endl;
	cin >> c;
	while(c != ';' && c != '.'){
		labirinto[n].push_back(c-65);
		cin >> c;
	}
	if(c == ';'){
		cin >> c;
		leitura(c);
		return;
	}else if(c == '.'){
		return;
	}else{
		cout << "deu pau " << c << endl;
		return;
	}
}


int caminha()
{
	int pos = -1;
	vector<int>::iterator it;
	//cout << "vai procurar por " << minotauro << endl;
	for(it = labirinto[minotauro].begin(); it != labirinto[minotauro].end(); it++){
		if((*it) != theseu){
			pos = (*it);
			break;
		}
	}
	return pos;
}


void remove()
{
	for(int i=0; i<26; i++){
		vector<int>::iterator it;
		for(it = labirinto[i].begin(); it != labirinto[i].end(); it++){
			if((*it) == theseu){
				//cout << "Encotrou" << *it << " em " << i << endl;
				labirinto[i].erase(it);
				break;
			}
		}
	}
}

void calcula()
{
	/*for(int i=0; i<30; i++){
		vector<int>::iterator it;
		cout << (char)(i+65) << ":";
		for(it=labirinto[i].begin(); it!=labirinto[i].end(); it++)
			cout << (char)((*it)+65);
		cout << endl;
	}*/
	while(1){
		int proximo = caminha();
		if(proximo != -1){
			//cout << "caminhou para " << proximo << endl;
			theseu = minotauro;
			minotauro = proximo;
		}else{
			cout << "/" << (char)(minotauro+65) << endl;
			return;
		}
		k_atual++;
		if(k_atual == k){
			cout << (char)(theseu+65) << " ";
			remove();
			k_atual = 0;
		}
	}
}

int main()
{
	char c;
	
	while(1){
		for(int i=0; i < 30; i++)
			labirinto[i].clear();
		cin >> c;
		if(c == '#')
			break;
		else
			leitura(c);
		//cin >> c; // espaço
		cin >> c;
		minotauro = c-65;
		//cout << "minotauro " << minotauro << endl;
		//cin >> c; // espaço
		cin >> c;
		theseu = c-65;
		//cout << "theseu " << theseu << endl;
		//cin >> c; // espaço
		cin >> k;
		//cout << "k " << k << endl;
		k_atual = 0;
		calcula();
	}
}
