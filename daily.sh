#!/bin/sh

# December 1, 2022
# Austin Leonardo

# create current day folder based off real date
DAY=$(date +%d)
FOLDER="day_"$DAY

# create source files
mkdir -p $FOLDER/{build,src}
echo "Created directory $FOLDER/"

# copy makefile + boiler plate c++/input files
cp Makefile $FOLDER
cp template_files/main.cpp "$FOLDER/src"
cp template_files/input.txt "$FOLDER/src"
cp template_files/notes.md "$FOLDER/src"

for i in {main.cpp,input.txt,notes.md}
do 
    # originally created empty files, copied from template files instead
    # touch "$FOLDER/src/$i"
    echo " Created source file $FOLDER/src/$i"
done

echo "Good luck on Day $DAY of Advent of Code!"