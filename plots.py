import csv
import matplotlib.pyplot as plt
from matplotlib.ticker import MaxNLocator
import pandas as pd
from collections import defaultdict
import math
# import re

columns = defaultdict(list)
with open("./output_data/lorem_out_sim.txt","r") as csv_fileTime:
    csv_reader = csv.reader(csv_fileTime, delimiter='\t')
    for row in csv_reader:
        for i in range(len(row)):
            columns[i].append(float (row[i]))

print(columns)

columns2 = defaultdict(list)
with open("./output_data/lorem_out_time.txt","r") as csv_fileSimilarity:
    csv_reader = csv.reader(csv_fileSimilarity, delimiter='\t')
    for row in csv_reader:
        for i in range(len(row)):
            columns2[i].append(float (row[i]))

print(columns2)

#plt.axis([columns[0][0],columns[0[-1],[columns[1]]]])
ax = plt.figure().gca()
ax.xaxis.set_major_locator(MaxNLocator(integer=True))
plt.ylabel("Time")
plt.xlabel("K-shingles")

for i in range(1,len(columns)):
    plt.plot(columns2[0],columns2[i],color='blue',alpha=0.05)

plt.show()
# kshingles2 = list(map(lambda x : math.log(x,10), kshingles))
# print(values)
# print(kshingles)
# d = {'K-shingles': kshingles, 'Similarity': values}
# df = pd.DataFrame(data = d)
# df.style
# # ef.to_html("SimilarityKShingle.html")
# print(df)

# #aquí ja faig servir el kshingle amb log perquè es vegi bé la diferència
# d = {'K-shingles(log)': kshingles2, 'Similarity': values}
# df = pd.DataFrame(data = d)
# df.plot.line()
# plt.savefig('JaccardSimilarity_KShinglesSimilarity.svg')


# e = {'Time': times, 'K-shingles': kshingles}
# ef = pd.DataFrame(data = e)
# ef.style
# ef.style
# # ef.to_html("TimeKShingle.html")
# print(ef)

# #aquí ja faig servir el kshingle amb log perquè es vegi bé la diferència
# e = {'K-shingles(log)': kshingles2, 'Time': times }
# ef = pd.DataFrame(data = e)
# ef.plot.line()
# plt.savefig('JaccardSimilarity_KShinglesTime.png')




# kshingles = re.findall(r'using(.*)-shingles',text)
# kshingles = list(map(float, kshingles))
# values = re.findall(r'is (.*)',text)
# values = list(map(float, values))
# times = re.findall(r'Time (.*)',text)
# times = list(map(float, times))
# names = re.findall(r'between (.*) and (.*) using', text)