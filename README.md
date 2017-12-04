# Algoritmica

## Práctica 1
Calcular la eficiencia teórica, empírica y realizar el ajuste de los algoritmos:
- Inserción, Selección y Burbuja
- ABB (árbol binario de búsqueda) y APO (árbol parcialmente ordenado)
- Fuerza bruta (permutaciones de 1 a n)
- Mergesort

La carpeta Practica1 icluye para cada uno de los algoritmos:
- Código fuente
- Imágenes de la eficiencia en una gráfica
- Un fichero run.sh para probar la eficiencia
- ficheros.dat con los resultados de las pruebas
- PDFs con el proceso guiado

## Práctica 2
Implementar distintos algoritmos Divide y Vencerás y calcular sus eficiencias. El programa contiene el código fuente, y los run.sh para probarlos.

### Ejercicio 1
Máximo y Mínimo: Dado un conjunto de enteros diseñar un algoritmo  DyV para encontrar el máximo y el mínimo. Para ello implementar un programa que genere un vector con un determinado número de enteros y obtener el máximo y mínimo de este conjunto. Para ello debéis implementar la función: pair<int ,int> Max_Min(const vector<int> & v); Obtener la eficiencia teórica y empírica del algoritmo.

### Ejercicio 2  
Moda de un conjunto de enteros Dado un conjunto de enteros diseñar un algoritmo DyV para encontrar el elemento moda del conjunto. El elemento moda es aquel que aparece con más frecuencia.Obtener la eficiencia teórica y empírica del algoritmo.
- IDEA.- Definido un elemento pivote, dividir el conjunto en tres  conjuntos:
- 1. Conjuntos de elementos menores y diferentes al pivote. Este conjunto se almacena en Heteregoneos.
- 2. Conjuntos de elementos igual al pivote. Este conjunto se almacena en Homogeneos
- 3. Conjunto de elementos mayores y diferentes al pivote. Este conjunto se almacena en Heteregoneos.

Con estas definiciones los pasos a seguir son:
- 1. Sea He el conjunto en heterogeneos de mayor cardinalidad (el conjunto más grande).
- 2. Sea Ho el conjunto de homogeneos de mayor cardinalidad (el conjunto más grande) 
- 3. Si Ho tiene más elementos que He entonces hemos terminado y la moda es el elemento que aparece en Ho.
- 4. En otro caso volver a dividir según 1-3 He.

### Ejercicio 3
Tornillos con sus tuercas. Se dispone de un conjunto de n tornillos de diferente tamaño y sus correspondientes n tuercas, de forma que cada tornillo encaja perfectamente con una y sólo una tuerca. Dado un tornillo y una tuerca, uno es capaz de determinar si el tornillo es menor que la tuerca, mayor, o encaja exactamente. Sin embargo, no hay forma de comparar dos tornillos o dos tuercas entre ellos para decidir un orden. Se desea ordenar los dos conjuntos de forma que los elementos que ocupan la misma posición en los dos conjuntos emparejen entre sí.
- IDEA: Se procederá mediante un algoritmo Divide y Vencerás de la siguiente forma. Representaremos los conjuntos de tuercas y tornillos mediante dos vectores de tamaño n que contienen las tuercas (tamaños) y los tornillos (tamaños). El algoritmo comienza escogiendo un tornillo aleatoriamente, este será el pivote para dividir los tuercas en tres conjuntos: S1 será el conjunto de tuercas que tienen un tamaño menor al tornillo ; S2: el conjunto  de tuercas que tienen igual tamaño igual al tornillo; y S3 el conjunto de tuercas que tienen tamaño mayor que la del tornillo. A continuación usando la tuerca que encaja perfectamente con el tornillo elegido, realizamos una partición similar en el conjunto de los tornillos dividiéndolo en tres conjuntos (aquellos tornillos menores que la tuerca, el tornillo elegido inicialmente que encaja con la tuerca y los tornillos mayores que la tuerca). El algoritmo, de forma recursiva, aplica el mismo procedimiento a cada uno de los dos grupos que se han formado, es decir, el de los tornillos y tuercas menores que el par encontrado, y el de los mayores. Obtener la eficiencia teórica y empírica del algoritmo.
- Programa Tornillos Este programa obtiene el emparejamiento de tornillos y tuercas. Un ejemplo de llamada a este programa desde la línea de órdenes: prompt% tornillos 1000
Los parámetros de entrada son los siguientes:
- 1. El número de tuercas y tornillos que debe generar aleatoriamente.
El programa deberá generar aleatoriamente 1000 tornillos, a continuación con estos tamaños de tornillos debe generar una permutación (ordenar de forma aleatoria) para obtener el conjunto de tuercas, también 1000.
