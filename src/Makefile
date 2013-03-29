CC = g++
CFlags = -Wall
Proj = ai

$(Proj): main.o MinMaxSearch.o Board.o
	$(CC) $^ -o $@

%.o : %.cc
	$(CC) -c $(CCFLAGS) $<

MinMaxSearch.o : Board.h
main.o : MinMaxSearch.h

clean:
	rm -f *.o
	rm -f *~ *% *# .#*

clean-all : clean
	rm -f encrypter