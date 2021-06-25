from random import randint as rand

cases = int(input("Gerar quantos casos? ->"))

for case_name in range(1, cases+1):
    file = open('../input/' + str(case_name), 'w')
    S, D = [1000, 1000]
    file.write(str(S) + ' ' + str(D) + '\n')
    for i in range(D):
        file.write(' '.join([str(rand(0, 100)) for j in range(S)]) + '\n')
    file.close()
