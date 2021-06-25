casos = int(input("Resolver quantos casos? ->"))
for caso in range(1, 1+casos):
	file_in = open('../input/' + str(caso), 'r')
	file_out = open('../output/' + str(caso), 'w')

	v = [int(i) for i in file_in.readline().split()]

	for i in range(int(file_in.readline())):
		a, b = map(int, file_in.readline().split())
		v[a-1], v[b-1] = v[b-1], v[a-1]

	file_out.write(str(v.index(1) + 1) + '\n')
