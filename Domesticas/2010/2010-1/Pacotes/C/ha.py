def entradas(T, N):
	import numpy
	from numpy.random import rand, randint
	print len(T)
	for i in range(len(T)):
		#print N[i],
		n = (N[i]*rand(T[i]) + 0.5).astype('int')
		for j in n:
			print j,
		print -1


#entradas([10,7], [5,10])
entradas([10,7,1000000,100], [5,255,1000,1000000000])


