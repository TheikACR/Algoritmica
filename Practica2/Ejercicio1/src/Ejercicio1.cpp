#include <iostream>
#include <utility>
#include <vector>
#include <stdlib.h>
#include <chrono>

using namespace std;
using namespace std::chrono;



pair<int ,int> Max_Min(const vector<int> & v){

	pair<int, int> max_min;
	int tamanio = v.size();
	int mitad = v.size() / 2;

	if (tamanio == 1) {
		max_min.first = v[0];
		max_min.second = v[0];
	}else if (tamanio == 2) {
		if (v[0] < v[1]) {
			max_min.first = v[0];
			max_min.second = v[1];
		} else if (v[0] >= v[1]){
			max_min.first = v[1];
			max_min.second = v[0];			
		}
	}else if (tamanio > 2){
		vector<int> izq, dcha;
		pair<vector<int>, vector<int> > aux;

		for (int i = 0; i < mitad; ++i) {
			izq.push_back(v[i]);
		}

		for (int j = mitad; j < tamanio; ++j) {
			dcha.push_back(v[j]);
		}

		aux.first = izq;
		aux.second = dcha;

		pair<int, int> p_izq = Max_Min(aux.first);
		pair<int, int> p_dcha = Max_Min(aux.second);

		if (p_izq.first < p_dcha.first)
			max_min.first = p_izq.first;
		else if (p_izq.first >= p_dcha.first)
			max_min.first = p_dcha.first;

		if (p_izq.second < p_dcha.second)
			max_min.second = p_dcha.second;
		else if (p_izq.second >= p_dcha.second)
			max_min.second = p_izq.second;
	}

	return max_min;
}



int main(int argc, char * argv[]){

	if (argc!=2) {
		cout << endl << "Param Error" << endl << endl;
		return 0;
	}

	int tam = atoi(argv[1]);
	vector<int> v;
	pair<int, int> max_min;
	
	high_resolution_clock::time_point start, end;
	duration<double> tiempo_transcurrido; 
	

	for (int i = 0; i < tam; ++i)
		v.push_back(i);

	start = high_resolution_clock::now();

	max_min = Max_Min(v);

	end = high_resolution_clock::now();
	
	tiempo_transcurrido  = duration_cast<duration<double> >(end - start);

	cout << tam << "\t" << tiempo_transcurrido.count() << endl;
}
