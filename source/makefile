CC = g++
CFLAGS = -std=c++11

default: permutacions jocProvesJaccSim jocProvesJaccSimLsh jocProvesHashTimes mainDriver

permutacions: permutacions.cc
	$(CC) $(CFLAGS) -o permutacions permutacions.cc
jocProvesJaccSim: jocProvesJaccSim.cc jaccardaprox.o kshingles.o ModularHash.o MultiplicativeHash.o MurmurHash3.o jaccard.o
	$(CC) $(CFLAGS) -o jocProvesJaccSim jocProvesJaccSim.cc jaccard.o jaccardaprox.o kshingles.o ModularHash.o MultiplicativeHash.o MurmurHash3.o
jovProvesJaccard: jocProvesJaccard.cc jaccardaprox.o kshingles.o ModularHash.o MultiplicativeHash.o MurmurHash3.o jaccard.o
	$(CC) $(CFLAGS) -o jocProvesJaccard jocProvesJaccard.cc jaccard.o jaccardaprox.o kshingles.o ModularHash.o MultiplicativeHash.o MurmurHash3.o
jocProvesJaccSimLsh: jocProvesJaccSimLsh.cc jaccardaprox.o kshingles.o ModularHash.o MultiplicativeHash.o MurmurHash3.o jaccard.o
	$(CC) $(CFLAGS) -o jocProvesJaccSimLsh jocProvesJaccSimLsh.cc jaccard.o jaccardaprox.o kshingles.o ModularHash.o MultiplicativeHash.o MurmurHash3.o
jocProvesHashTimes: jocProvesHashTimes.cc jaccardaprox.o kshingles.o ModularHash.o MultiplicativeHash.o MurmurHash3.o jaccard.o
	$(CC) $(CFLAGS) -o jocProvesHashTimes jocProvesHashTimes.cc jaccard.o jaccardaprox.o kshingles.o ModularHash.o MultiplicativeHash.o MurmurHash3.o
mainDriver: mainDriver.cc jaccardaprox.o kshingles.o ModularHash.o MultiplicativeHash.o MurmurHash3.o jaccard.o
	$(CC) $(CFLAGS) -o mainDriver mainDriver.cc jaccard.o jaccardaprox.o kshingles.o ModularHash.o MultiplicativeHash.o MurmurHash3.o
ModularHash.o: ModularHash.cc
	$(CC) $(CFLAGS) -c ModularHash.cc
MultiplicativeHash.o: MultiplicativeHash.cc
	$(CC) $(CFLAGS) -c MultiplicativeHash.cc
MurmurHash3.o: MurmurHash3.cc
	$(CC) $(CFLAGS) -c MurmurHash3.cc
jaccardaprox.o: jaccardaprox.cc
	$(CC) $(CFLAGS) -c jaccardaprox.cc
jaccard.o: jaccard.cc
	$(CC) $(CFLAGS) -c jaccard.cc
kshingles.o: kshingles.cc
	$(CC) $(CFLAGS) -c kshingles.cc
clean:
	rm -f *.o permutacions jocProvesJaccSim jocProvesJaccSimLsh jocProvesHashTimes mainDriver
