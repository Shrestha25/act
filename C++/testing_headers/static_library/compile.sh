g++  -c ../func/*.cpp -I ../headers/ 
ar rcs libmaths.a *.o
g++ ../src/Main.cpp -o ../executables/static_main -I ../headers/ -L. -lmaths
./../executables/static_main
