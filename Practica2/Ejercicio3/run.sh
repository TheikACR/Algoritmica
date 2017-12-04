a="Ejercicio3"

rm time.dat

for i in `seq 0 100 1000`
do
	./$a $i >> time.dat
done

