a="Ejercicio2"

rm time.dat

for i in `seq 0 100 4000`
do
	./$a $i >> time.dat
done

