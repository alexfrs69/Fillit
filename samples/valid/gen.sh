#!/bin/sh

i=1

while [ $i != 27 ]
do
	echo "$i"
	.././generator.py $i > t$i.sample
	i=$(($i+1))
done
echo "Generated all valid samples."
