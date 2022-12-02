# Notes
~~Choosing Python for this problem because I forgor how to create MAKEFILES for C++ (needs to be local development as the input is a file)~~

never mind i'm doing it in C++, i found a make file [here](https://makefiletutorial.com/#makefile-cookbook)

## daily.sh
>_bash script that creates folder structure for each day_

might need to give it permission with following
```
chmod +x daily.sh
```

## work flow
1. Run `daily.sh`
2. Code in current day's `/src/main.cpp` file
3. Recompile code from project root with `test.sh` 
4. Run `final_program` in `/build` directory

## to do
- automate testing script (complete `testing.sh`)

## misc
- setup for this project took 2-3 hrs alone, but should pay off for other days