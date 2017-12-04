#include "abb.h"
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

void Inorden(ABB<int> &ab_bus){
  ABB<int>::nodo n;
  int dat;

 for (n=ab_bus.begin();n!=ab_bus.end();++n){
	   dat = *n;
 }
}

int main(int argc, char * argv[]){
	high_resolution_clock::time_point start, end;
	duration<double> tiempo_transcurrido;

	int tam = atoi(argv[1]);
	ABB<int>ab_bus;
 
 for (int i=tam-1;i>=0;i--){
	   ab_bus.Insertar(i);
 }

start = high_resolution_clock::now();
 Inorden(ab_bus);
end = high_resolution_clock::now();
tiempo_transcurrido = duration_cast<duration<double> > (end - start);

cout << tam << "\t" << tiempo_transcurrido.count() << endl;
 
}
