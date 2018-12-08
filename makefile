CC = g++
CFLAGS = -std=c++11

jacap: jaccardaprox.cc kshingles.o ModularHash.o
	$(CC) $(CFLAGS) -o jacap jaccardaprox.cc kshingles.o ModularHash.o
kshingles.o: kshingles.cc
	$(CC) $(CFLAGS) -c kshingles.cc
ModularHash.o: ModularHash.cc
	$(CC) $(CFLAGS) -c ModularHash.cc

clean:
	rm -f *.o jacap
