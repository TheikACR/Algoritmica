#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void Seleccion(int a[], int n){
	for (int i = 0; i < n - 1; ++i){
		int pmin = i;
		for (int j = i + 1; j < n; ++j){
			if (a[pmin] > a[j])
				j = pmin;
		}
		swap(a[i], a[pmin]);
	}
}

void sintaxis()
{
  cerr << "Sintaxis:" << endl;
  cerr << "  TAM: Tamaño del vector (>0)" << endl;
  cerr << "  VMAX: Valor máximo (>0)" << endl;
  cerr << "Se genera un vector de tamaño TAM con elementos aleatorios en [0,VMAX[" << endl;
  exit(EXIT_FAILURE);
}

int main(int argc, char * argv[])
{
  // Lectura de parámetros
  if (argc!=3)
    sintaxis();
  int tam=atoi(argv[1]);     // Tamaño del vector
  int vmax=atoi(argv[2]);    // Valor máximo
  if (vmax<=0)
    sintaxis();
  
  // Generación del vector
  int *v=new int[tam];       // Reserva de memoria
  for (int i=0; i<tam/2; i++)  // Recorrer vector
    v[i] = i;    // Generar aleatorio [0,vmax[
  for (int i=tam-1; i>=(tam+1)/2; i--)  // Recorrer vector
    v[i] = i;
  
 high_resolution_clock::time_point start,//punto de inicio
                                  end; //punto de fin
 duration<double> tiempo_transcurrido;  //objeto para medir la duracion de end 						   // y start
  
 start = high_resolution_clock::now(); //iniciamos el punto de inicio
 
  Seleccion(v,tam); // de esta forma forzamos el peor caso
  
 end = high_resolution_clock::now(); //anotamos el punto de de fin 
 //el tiempo transcurrido es
 tiempo_transcurrido  = duration_cast<duration<double> >(end - start);

  // Mostramos resultados
  cout << tam << "\t" <<tiempo_transcurrido.count() << endl;
  
  delete [] v;     // Liberamos memoria dinámica
}
