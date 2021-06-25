def entradas(T):
	import numpy
	from numpy.random import randint
	print T
	for i in range(T):
		k = randint(1,8)
		n = randint(1,41)
		print k,n
	
	
def fitomate(k,n):
	s = []
	for i in range(1,n+1):
		if i <= k:
			s.append(1)
		else:
			s.append(sum(s[i-k-1:i]))
	return s[-1]


#entradas(1000)

#print fitomate(3,7)
#print fitomate(7,20)

import sys
T = int(sys.stdin.readline())
for case in range(T):
    linha = sys.stdin.readline().split(' ')
    k = int(linha[0])
    n = int(linha[-1])
    print fitomate(k,n)
print
