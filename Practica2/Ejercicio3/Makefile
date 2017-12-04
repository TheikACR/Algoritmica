all: bin/Ejercicio3

clean:
	echo "Limpieza archivos y biblioteca"
	rm obj/*

mrproper: clean
	rm bin/*

obj/Ejercicio3.o:	src/Ejercicio3.cpp
	g++ -std=c++11 -c -o obj/Ejercicio3.o -Iinclude src/Ejercicio3.cpp

bin/Ejercicio3:	obj/Ejercicio3.o
	g++ -std=c++11 -o bin/Ejercicio3 obj/Ejercicio3.o
