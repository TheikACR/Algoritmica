all: bin/Ejercicio1

clean:
	echo "Limpieza archivos y biblioteca"
	rm obj/*

mrproper: clean
	rm bin/*

obj/Ejercicio1.o:	src/Ejercicio1.cpp
	g++ -std=c++11 -c -o obj/Ejercicio1.o -Iinclude src/Ejercicio1.cpp

bin/Ejercicio1:	obj/Ejercicio1.o
	g++ -std=c++11 -o bin/Ejercicio1 obj/Ejercicio1.o
