a="orden_burbuja_mejor"
b="orden_burbuja_peor"
c="orden_burbuja_promedio"

rm time_mejor.dat
#rm time_peor.dat
#rm time_promedio.dat
rm $a
#rm $b
#rm $c

g++ -std=c++11 -o $a $a.cpp
#g++ -std=c++11 -o $b $b.cpp
#g++ -std=c++11 -o $c $c.cpp

for i in `seq 0 1000 100000`
do
	./$a $i 1000 >> time_mejor.dat
done

#for i in `seq 0 1000 100000`
#do
#	./$b $i 1000 >> time_peor.dat
#done

#for i in `seq 0 1000 100000`
#do
#	./$c $i 1000 >> time_promedio.dat
#done
