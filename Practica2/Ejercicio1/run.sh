a="Ejercicio1"

rm time.dat

for i in `seq 0 1000 100000`
do
	./$a $i >> time.dat
done

