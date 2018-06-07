CC=g++
CFLAGS=-std=c++11 -c
LFLAGS=-pthread
object= 1_1.o


default: program

%.o: %.cpp
	$(CC) $(CFLAGS) $^  -o $@

program: $(object) 
	$(CC) $(LFLAGS) $^ -o $@ 

.PHONY: clean

clean:
	rm -r *.o program
