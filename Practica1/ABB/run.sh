a="abb_mejor"
b="abb_peor"
c="abb_promedio"

rm time_mejor.dat
rm time_peor.dat
rm time_promedio.dat
rm $a
rm $b
rm $c

g++ -std=c++11 -o $a $a.cpp
g++ -std=c++11 -o $b $b.cpp
g++ -std=c++11 -o $c $c.cpp

for i in `seq 0 1000 50000`
do
	./$a $i >> time_mejor.dat
done

for i in `seq 0 1000 50000`
do
	./$b $i >> time_peor.dat
done

for i in `seq 0 1000 50000`
do
	./$c $i >> time_promedio.dat
done
