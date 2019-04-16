from numpy import *
from adpil import adread, adshow
from time  import time


def iarec(f, S):
    faux = 1*f
    g = 0*f
    while len(S):
        P = S.pop()
        x, y = P[0], P[1]
        if 0 <= x < faux.shape[0] and 0 <= y < faux.shape[1]:
            if faux[x,y]:
                faux[x,y], g[x,y] = 0, 1
                S.append((x+1, y  ))
                S.append((x-1, y  ))
                S.append((x  , y+1))
                S.append((x  , y-1))
    return g
    
def buraco(f):
	frame = zeros(f.shape)
	frame[0,:] = 1; frame[-1,:] = 1
	frame[:,0] = 1; frame[:,-1] = 1
	seed = transpose(nonzero(frame)).tolist()
	g = 1 - iarec(1-f, seed)
	return g
	
def print_matriz(f):
	f = f.astype('int')
	txt = ''
	for i in range(f.shape[0]):
		for j in range(f.shape[1]):
			txt = txt + `f[i,j]`
		txt = txt + '\n'
	print txt[:-1]

def print_quant_uns(f):
	u = sum(ravel(f) == 1)
	print "%d" %(u)

def gera_entradas_saidas(op):
	if op == "entradas":
		print 4
	
	f = array([	[1,1,1,1,1,1,0,0,0,0],
			[0,0,1,1,0,0,1,0,0,0],
			[0,0,1,0,0,0,0,1,0,0],
			[0,0,0,1,1,1,1,1,0,0],
			[1,1,0,0,0,0,0,0,0,0],
			[1,0,1,1,1,0,0,1,1,1],
			[1,1,1,1,0,0,0,1,0,0]], 'int')
	if op == "entradas":
		print f.shape[0], f.shape[1]
		print_matriz(f)
	if op == "saidas":
		fburaco = buraco(f)
		#print_matriz(fburaco)
		print_quant_uns(fburaco)
		
	f = adread('test1.pbm')
	if op == "entradas":
		print f.shape[0], f.shape[1]
		print_matriz(f)
	if op == "saidas":
		fburaco = buraco(f)
		#print_matriz(fburaco)
		print_quant_uns(fburaco)

	f = adread('test2.pbm')
	if op == "entradas":
		print f.shape[0], f.shape[1]
		print_matriz(f)
	if op == "saidas":
		fburaco = buraco(f)
		#print_matriz(fburaco)
		print_quant_uns(fburaco)
	
	f = adread('gull.pgm')
	f = 1*(f>127)
	if op == "entradas":
		print f.shape[0], f.shape[1]
		print_matriz(f)
	if op == "saidas":
		fburaco = buraco(f)
		#print_matriz(fburaco)
		print_quant_uns(fburaco)
	
	
#gera_entradas_saidas('entradas')
gera_entradas_saidas('saidas')


'''
f = array([[0,0,1,1,1,1],
	   [0,1,1,0,0,1],
	   [0,1,0,0,1,0],
	   [0,1,1,1,0,0]] )
g = buraco(f)
print_matriz(f)
print
print_matriz(g)
print_quant_uns(g)
'''

'''
print
print

f = array([	[1,1,1,1,1,1,0,0,0,0],
			[0,0,1,1,0,0,1,0,0,0],
			[0,0,1,0,0,0,0,1,0,0],
			[0,0,0,1,1,1,1,1,0,0],
			[1,1,0,0,0,0,0,0,0,0],
			[1,0,1,1,1,0,0,1,1,1],
			[1,1,1,1,0,0,0,1,0,0]], 'int')
g = buraco(f)
print f
print
print g
'''


'''
#f = adread('test2.pbm')
f = adread('gull.pgm'); f = 1*(f>127)
t0 = time(); fburaco = buraco(f); print time()-t0
adshow(255*f,id=1)
adshow(255*fburaco,id=2)
'''

#raw_input()

