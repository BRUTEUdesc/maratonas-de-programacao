from random import randint as rand

cases = int(input("Gerar quantos casos? -> "))

for number in range(1, cases+1):
    file = open('../input/' + str(number), 'w')
    S, D = [rand(1,10), rand(1,10000)]
    file.write(str(S) + ' ' + str(D) + '\n')
    for i in range(S):
        file.write(str(rand(1, 100)) + ' ')
    file.close()