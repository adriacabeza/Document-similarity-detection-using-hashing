CC = g++
CFLAGS = -std=c++11

jacap: jaccardaprox.cc kshingles.o ModularHash.o
	$(CC) $(CFLAGS) -o jacap jaccardaprox.cc kshingles.o ModularHash.o
compjac: CompararDocumentsJaccard.cc jaccard.o kshingles.o
	$(CC) $(CFLAGS) -o compjac CompararDocumentsJaccard.cc jaccard.o kshingles.o

jocprovesambJaccard: jocprovesambJaccard.cc jaccard.o kshingles.o
	$(CC) $(CFLAGS) -o  jocprovesambJaccard jocprovesambJaccard.cc jaccard.o kshingles.o
ModularHash.o: ModularHash.cc
	$(CC) $(CFLAGS) -c ModularHash.cc
jaccard.o: jaccard.cc
	$(CC) $(CFLAGS) -c jaccard.cc
kshingles.o: kshingles.cc
	$(CC) $(CFLAGS) -c kshingles.cc
clean:
	rm -f *.o jacap compjac compjac  
