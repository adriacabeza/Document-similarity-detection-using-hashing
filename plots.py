import csv
import matplotlib.pyplot as plt
from matplotlib.ticker import MaxNLocator
import pandas as pd
from collections import defaultdict
import math

print("Quin gràfic vols fer? OPCIONS: \n 0: Jaccard Similarity value with time \n 1: Jaccard Similarity with time and k-shingle \n 2: For each Hash Function the time for the approximation \n 3: Time of execution between Jaccard Similarity and the approximation\n ")
a = int(input())
if a == 0 :  #Plot severals Jaccard Similarity value with time
    JaccardSimilarity = defaultdict(list)
    with open("./output_data/lorem_out_sim.txt","r") as csv_fileTime:
        csv_reader = csv.reader(csv_fileTime, delimiter='\t')
        for row in csv_reader:
            for i in range(len(row)):
                JaccardSimilarity[i].append(float (row[i])) 

    plt.figure().gca().xaxis.set_major_locator(MaxNLocator(integer=True))
    plt.ylabel("Similarity")
    plt.xlabel("K-shingles")

    for i in range(1,len(JaccardSimilarity)):
        plt.plot(JaccardSimilarity[0],JaccardSimilarity[i],color='red',alpha=0.005)

    plt.savefig('JaccardSimilarityValueKshingles.pdf')
    plt.show()

elif a == 1 : 
    JaccardTime = defaultdict(list)
    with open("./output_data/lorem_out_time.txt","r") as csv_fileSimilarity:
        csv_reader = csv.reader(csv_fileSimilarity, delimiter='\t')
        for row in csv_reader:
            for i in range(len(row)):
                JaccardTime[i].append(float (row[i]))

    #Plot Jaccard Similarity with time and k-shingle
    TimeKshingle = plt.figure().gca()
    TimeKshingle.xaxis.set_major_locator(MaxNLocator(integer=True))
    plt.ylabel("Time (s)")
    plt.xlabel("K-shingles")

    for i in range(1,len(JaccardTime)):
        plt.plot(JaccardTime[0],JaccardTime[i],color='blue',alpha=0.05)

    plt.savefig('JaccardSimilarityTimeKshingles.pdf')
    plt.show()

elif a == 2: #Plot for each Hash Function the time for the approximation
    HashFunctionsJaccardAproxTime = defaultdict(list)
    with open("./output_data/lorem_hashfuncts_time.txt","r") as csv_fileSimilarity:
        csv_reader = csv.reader(csv_fileSimilarity, delimiter='\t')
        for row in csv_reader:
            for i in range(len(row)):
                HashFunctionsJaccardAproxTime[i].append(float (row[i]))

    plt.figure().gca().xaxis.set_major_locator(MaxNLocator(integer=True))
    plt.ylabel("Time (s)")
    plt.xlabel("K-shingles")

    colors = ['red','blue','green']
    labels = ['Modular','Multiplicative','Murmur']
    for (i,color,label) in zip(range(1,len(HashFunctionsJaccardAproxTime)), colors, labels):
        plt.plot(HashFunctionsJaccardAproxTime[0],HashFunctionsJaccardAproxTime[i],color=color,label=label, alpha=1)
        plt.legend()
        
    plt.savefig('HashFunctionsJaccardAproxTime.pdf')
    plt.show()

elif a == 3:  #Plot for the Time of execution between Jaccard Similarity and the approximation
    HashFunctionsJaccardAproxTime = defaultdict(list)
    with open("./output_data/lorem_jacc_vs_approx_time.txt","r") as csv_fileSimilarity:
        csv_reader = csv.reader(csv_fileSimilarity, delimiter='\t')
        for row in csv_reader:
            for i in range(len(row)):
                HashFunctionsJaccardAproxTime[i].append(float (row[i]))

    plt.figure().gca().xaxis.set_major_locator(MaxNLocator(integer=True))
    plt.ylabel("Time (s)")
    plt.xlabel("K-shingles")

    colors = ['red','blue']
    labels = ['Jaccard Similarity','Jaccard Approximation']
    for (i,color,label) in zip(range(1,len(HashFunctionsJaccardAproxTime)), colors, labels):
        plt.plot(HashFunctionsJaccardAproxTime[0],HashFunctionsJaccardAproxTime[i],color=color,label=label, alpha=1)
        plt.legend()
        
    plt.savefig('TimeBetweenJaccardSimandAprox2.pdf')
    plt.show()