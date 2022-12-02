#!/bin/sh

# December 1, 2022
# Austin Leonardo

# create current day folder based off real date
DAY=$(date +%d)
FOLDER="day_$DAY"
# APP="$FOLDER/build/final_program"
# INPUTFILE="$FOLDER/build/input.txt"

# echo "Testing $APP using $INPUTFILE"

#rebuild app
echo "Rebuilding application..."
make -C $FOLDER

# test app
# echo $INPUTFILE
# ./$APP < $INPUTFILE