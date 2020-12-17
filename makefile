all: project3.out

project3.out: main.cpp avl.cpp 
	g++ -std=c++11 $^ -o $@

clean:
	rm -f *.out *.o