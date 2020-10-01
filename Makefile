CXX=g++

all: bitVector.o main.o
	$(CXX) -O0 -std=c++11 -ggdb -fno-elide-constructors -o main main.o bitVector.o

main.o: main.cpp
	$(CXX) -c -std=c++11 -ggdb -O0 -fno-elide-constructors -o main.o main.cpp 

bitVector.o: bitVector.cpp bitVector.h
	$(CXX) -c -std=c++11 -ggdb -O0 -fno-elide-constructors -o bitVector.o bitVector.cpp  


clean:
	rm -rf main.o bitVector.o main