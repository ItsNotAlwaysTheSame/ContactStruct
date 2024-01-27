main: test.cpp  testsearch1.cpp testsearch1.h validation.cpp delete.cpp delete.h validation.h
	g++ test.cpp  testsearch1.cpp validation.cpp delete.cpp -o main

run: main
	./main