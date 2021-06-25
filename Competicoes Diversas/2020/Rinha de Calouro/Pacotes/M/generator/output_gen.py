from math import ceil

for case_name in range(1, 1+int(input("Resolver quantos casos? ->"))):
    file_in = open('../input/' + str(case_name), 'r')
    file_out = open('../output/' + str(case_name), 'w')
    S, D = [int(i) for i in file_in.readline().split()]
    cont = [0 for i in range(S)]
    for d in range(D):
        t = [int(i) for i in file_in.readline().split()]
        for i in range(S):
            cont[i] += t[i]

    media = ceil(sum(cont) / D)
    pref = cont.index(max(cont))

    file_out.write(str(media) + '\n')
    file_out.write(str(pref + 1) + '\n')
