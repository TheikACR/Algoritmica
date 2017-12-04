#include <iostream>
#include <queue>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>   
#include <chrono>

using namespace std;
using namespace std::chrono;


void quickSort(int arr[], int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];
 
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      }
 
      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
}

int binarySearch(const vector<int> v, int inicio, int fin, int x){
	if (v.begin() <= v.end()){
		int mitad = v.size()/2;
		if(v[mitad]==x) return mitad;
		else{
			if (x > v[mitad]) return binarySearch(v, mitad+1, v.size()-1, x);
			else return binarySearch(v, inicio, mitad-1, x);
		}
	}else return -1;
}

vector<int> TT(vector<int> tuercas, vector<int> tornillos){
	vector<int> tornillos_tuercas;

	for (int i = 0; i < tuercas.size(); ++i){
		int a = binarySearch(tornillos, 0, tornillos.size(), tuercas.at(i));
		tornillos.push_back(a);
	}
	return tornillos_tuercas;
}

int main(int argc, char * argv[]){

	if (argc!=2) {
		cout << endl << "Param Error" << endl << endl;
		return 0;
	}

	srand (time(NULL));

	int tam = atoi(argv[1]);
	vector<int> tuercas, tornillos;
  for (int i=0; i<tam; i++){
    tuercas.push_back(i); 
	 tornillos.push_back(tam - i);
  }

	vector<int> torn_tue;

	high_resolution_clock::time_point start, end;
	duration<double> tiempo_transcurrido; 

	start = high_resolution_clock::now();

	torn_tue = TT(tuercas, tornillos);

	end = high_resolution_clock::now();
	
	tiempo_transcurrido  = duration_cast<duration<double> >(end - start);

	cout << tam << "\t" << tiempo_transcurrido.count() << endl;
}
