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
      };
 
      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
}

bool ordenado = false;

pair<int, int> Moda(int arr[], int left, int right) {

	pair<int, int> moda;
	int *ho=new int[100001];
	int *he=new int[100001];
	int util_ho = 0, util_he = 0;
	int k = 0;

	moda.first = 0;
	moda.second = 0;

	if (!ordenado){
		quickSort(arr, left, right);
		ordenado = true;
	}

	do{
		ho[util_ho] = arr[k];
		++k;
		++util_ho;
	}while (arr[k] == arr[k-1]);

	while (util_he < (right - util_ho)){
		he[util_he] = arr[k];
		++k;
		++util_he;
	}

	if (util_ho > util_he && util_ho > 1){
		moda.first = ho[0];
		moda.second = util_ho;
	}
   else{
   	pair<int, int> m_he =  Moda(he, util_ho, util_he);
		if (m_he.second > moda.second){
			moda.first = m_he.first;
			moda.second = m_he.second;
		}
	}

	return moda;
}


int main(int argc, char * argv[]){

	if (argc!=2) {
		cout << endl << "Param Error" << endl << endl;
		return 0;
	}

	srand (time(NULL));

	int tam = atoi(argv[1]);
	int *v=new int[tam];       // Reserva de memoria
  for (int i=0; i<tam; i++)  // Recorrer vector
    v[i] = rand() % tam; 
	pair<int, int> modal;
	
	high_resolution_clock::time_point start, end;
	duration<double> tiempo_transcurrido; 

	start = high_resolution_clock::now();

	modal = Moda(v, 0, tam);

	end = high_resolution_clock::now();
	
	tiempo_transcurrido  = duration_cast<duration<double> >(end - start);

	cout << tam << "\t" << tiempo_transcurrido.count() << endl;
}
