CC = g++
CFLAGS = -std=c++11

jacap: jaccardaprox.cc kshingles.o
	$(CC) $(CFLAGS) -o jacap jaccardaprox.cc kshingles.o
kshingles.o: kshingles.cc
	$(CC) $(CFLAGS) -c kshingles.cc

clean:
	rm -f *.o jacap
