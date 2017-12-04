all: bin/Ejercicio2

clean:
	echo "Limpieza archivos y biblioteca"
	rm obj/*

mrproper: clean
	rm bin/*

obj/Ejercicio2.o:	src/Ejercicio2.cpp
	g++ -std=c++11 -c -o obj/Ejercicio2.o -Iinclude src/Ejercicio2.cpp

bin/Ejercicio2:	obj/Ejercicio2.o
	g++ -std=c++11 -o bin/Ejercicio2 obj/Ejercicio2.o
