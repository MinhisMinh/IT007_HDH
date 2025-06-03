#!/bin/sh

echo "Please provide your name"
read name

echo "Please provide your student ID:"
read ID

while [ "$ID" != "23520930" ]
do
    echo "Unrecognized ID. Please type again"
    read ID
done

echo "Hi $name (Student ID: $ID)"
exit 0