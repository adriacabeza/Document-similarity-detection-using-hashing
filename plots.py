import re
import matplotlib.pyplot as plt
import pandas as pd
import math

file = open("output.txt","r")
text = file.read()
kshingles = re.findall(r'using(.*)-shingles',text)
kshingles = list(map(float, kshingles))
values = re.findall(r'is (.*)',text)
values = list(map(float, values))
times = re.findall(r'Time (.*)',text)
times = list(map(float, times))
names = re.findall(r'between (.*) and (.*) using', text)

kshingles2 = list(map(lambda x : math.log(x,10), kshingles))
print(values)
print(kshingles)
d = {'K-shingles': kshingles, 'Similarity': values}
df = pd.DataFrame(data = d)
df.style
# ef.to_html("SimilarityKShingle.html")
print(df)

#aquí ja faig servir el kshingle amb log perquè es vegi bé la diferència
d = {'K-shingles(log)': kshingles2, 'Similarity': values}
df = pd.DataFrame(data = d)
df.plot.line()
plt.savefig('JaccardSimilarity_KShinglesSimilarity.svg')


e = {'Time': times, 'K-shingles': kshingles}
ef = pd.DataFrame(data = e)
ef.style
ef.style
# ef.to_html("TimeKShingle.html")
print(ef)

#aquí ja faig servir el kshingle amb log perquè es vegi bé la diferència
e = {'K-shingles(log)': kshingles2, 'Time': times }
ef = pd.DataFrame(data = e)
ef.plot.line()
plt.savefig('JaccardSimilarity_KShinglesTime.png')


