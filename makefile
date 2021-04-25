FLAGS = -pedantic-errors -std=c++11

msp.o: msp.cpp msp.h
	g++ $(FLAGS) -c $<

msp_main.o: msp_main.cpp msp.h
	g++ $(FLAGS) -c $<

msp: msp.o msp_main.o
	g++ $(FLAGS) $^ -o $@

clean:
	rm -f *.o msp

.PHONY: clean
