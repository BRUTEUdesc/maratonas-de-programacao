from numpy import *

def mat2vet(B):
    a = B.shape[0]/2
    b = B.shape[1]/2
    V = []
    for i,j in ndindex(B.shape):
        if B[i,j] > 0:
            V.append((a-i, b-j))
    return V

def erosao(A, B):
    V = mat2vet(B)
    C = ones(A.shape, 'int')
    for i,j in ndindex(A.shape):
        for v in V:
            x = i - v[0]
            y = j - v[1]
            if x >= 0 and x < A.shape[0] and y >=0 and y < A.shape[1]:
                if A[x,y] == 0:
                    C[i,j] = 0
                    break
    return C

def dist(f):
	b = array([[0,1,0],[1,1,1],[0,1,0]])
	aux = erosao(f,b)
	g = f + aux
	while not array_equal(f,aux):
		f = aux + 0
		aux = erosao(f,b)
		g = g + aux
	return g
	
def print_matriz(f):
	txt = ''
	for i in range(f.shape[0]):
		for j in range(f.shape[1]):
			txt = txt + `f[i,j]`
		txt = txt + '\n'
	print txt[:-1]

def print_coord_maximos(f):
	maximo = max(ravel(f))
	print maximo,
	aux = f == maximo
	x, y = nonzero(aux)
	for i in range(len(x)):
		print "(%d,%d)" %(x[i],y[i]),
	print

def gera_entradas_saidas(op):
	if op == "entradas":
		print 4
	
	f = zeros((7,10),'int'); f[1:-1,2:-1] = 1; f[:,4:8]=1; f[2:5,1::]=1; f[-1,-2]=1; f[-2,-1]=1
	if op == "entradas":
		print f.shape[0], f.shape[1]
		print_matriz(f)
	if op == "saidas":
		fdist = dist(f)
		#print_matriz(fdist)
		print_coord_maximos(fdist)
	
	f = zeros((5,7),'int'); f[1:-1,0:-2] = 1;
	if op == "entradas":
		print f.shape[0], f.shape[1]
		print_matriz(f)
	if op == "saidas":
		fdist = dist(f)
		#print_matriz(fdist)
		print_coord_maximos(fdist)
		
	x,y = indices((11,15))
	f = (x-5)**2 + (y-7)**2 <= 6**2
	f = 1*f
	if op == "entradas":
		print f.shape[0], f.shape[1]
		print_matriz(f)
	if op == "saidas":
		fdist = dist(f)
		#print_matriz(fdist)
		print_coord_maximos(fdist)
	
	from ia636 import iaread
	f = iaread('gull.pgm')
	f = 1*(f>127)
	if op == "entradas":
		print f.shape[0], f.shape[1]
		print_matriz(f)
	if op == "saidas":
		fdist = dist(f)
		#print_matriz(fdist)
		print_coord_maximos(fdist)
	
	
#gera_entradas_saidas('entradas')
#gera_entradas_saidas('saidas')


f = zeros((5,7),'int'); f[1:-1,0:-2] = 1; f[:,1:4]=1
print_matriz(f)
print
fdist = dist(f)
print_matriz(fdist)
print
print_coord_maximos(fdist)
