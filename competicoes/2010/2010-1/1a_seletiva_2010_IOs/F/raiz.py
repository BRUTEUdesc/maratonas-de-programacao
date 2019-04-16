from math import sqrt

def entradas(T):
	import numpy
	from numpy.random import rand, randint
	print T
	for i in range(T):
		a = randint(1,1001)
		n = a*rand()
		casas_decimais = randint(1,6)
		if casas_decimais == 1:
			print "%.1f" %n,
		elif casas_decimais == 2:
			print "%.2f" %n,
		elif casas_decimais == 3:
			print "%.3f" %n,
		elif casas_decimais == 4:
			print "%.4f" %n,
		elif casas_decimais == 5:
			print "%.5f" %n,

entradas(1000)


'''
def raiz(a):
	a = 1.*a
	x0 = a/2
	x  = 1./2 * (x0 + a/x0)
	i = 1
	print 'i=0 %.5f i=1 %.5f' %(x0, x),
	while abs(x-x0) > 0.001:
		x0 = x
		x  = 1./2 * (x0 + a/x0)
		i = i + 1
		print 'i=%d %.5f' %(i,x),
	return x,i
'''
#sqrt(1011.1903)
#x,i = raiz(5.487)


