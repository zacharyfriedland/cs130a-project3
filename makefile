all: project3.out

project3.out: project3.o avl.o 
	g++ -std=c++11 $^ -o $@

clean:
	rm -f *.out *.o