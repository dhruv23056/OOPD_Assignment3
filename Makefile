target:
	g++ -c main.cpp
	g++ -o main main.o
	g++ -O3 -o optimize_file1 main.o 
	./main
