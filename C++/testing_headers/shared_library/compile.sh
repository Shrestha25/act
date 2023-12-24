g++ -fPIC -c ../func/*.cpp -I ../headers/ 
g++ -shared *.o -o libmaths.so
g++ ../src/Main.cpp -o ../executables/shared_main -I ../headers/ -L. -lmaths
LD_LIBRARY_PATH=. ./../executables/shared_main
