#!/bin/sh

echo "Please provide the input n (10 or bigger):"
read n

while [ "$n" -lt 10 ]
do
    echo "The input must be 10 or higher!!!"
    read n
done

i=1
sum=0
while [ "$i" -le "$n" ]
do
    sum=$((sum + i))
    i=$((i + 1))
done

echo "The sum from 1 to $n is: $sum"
exit 0