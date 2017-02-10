from time import time
from random import randint
from collections import OrderedDict

players = list("ABCDEFGH")
d = OrderedDict()

start = time()
print len(players)

for i in xrange(8):
    raw_input() 
    p = players.pop(randint(0,7-i))  #(0,7) #len(players) will change while looping
    end = time() 
    print i+1, p, end - start,  #will change line
    d[p] = (i+1, end-start)

print	#change line by defult
print '.' * 20
for k in d:
	print k, d[k]

