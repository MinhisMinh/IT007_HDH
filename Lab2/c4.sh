#!/bin/bash

echo "Please provide the string input"
read s

found=false
for filename in *.txt; do
    if [ -f "$filename" ]; then
        if grep -q "$s" "$filename"; then
            echo "There is string matches in $filename"
            found=true
        fi
    fi
done

if [ "$found" == false ]; then
    echo "Cannot find any matches in .txt file"
fi

exit 0