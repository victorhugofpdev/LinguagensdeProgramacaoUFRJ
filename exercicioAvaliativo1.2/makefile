CXX = g++
CXXFLAGS = -Wall -std=c++11

all: programa

programa: main.o
	$(CXX) $(CXXFLAGS) -o programa main.o

main.o: main.cpp treinador.h atleta.h
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f *.o programa
