#include "apo.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

int main(int argc, char * argv[]){
high_resolution_clock::time_point start, end;
	duration<double> tiempo_transcurrido;
int tam = atoi(argv[1]);
APO<int>ap_int;
	
for (int i=tam-1;i>0;i--){
	   ap_int.insertar(i);
 }
	
start = high_resolution_clock::now();
	  cout<</*"APO introducido:"<<*/ap_int;

end = high_resolution_clock::now();
tiempo_transcurrido = duration_cast<duration<double> > (end - start);

cout << tam << "\t" << tiempo_transcurrido.count() << endl;
}
