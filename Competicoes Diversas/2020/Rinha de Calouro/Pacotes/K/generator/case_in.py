from random import randint as rand

cases = int(input("Gerar quantos casos? -> "))

for number in range(4, 1+cases):
    file = open('../input/' + str(number), 'w')
    S = rand(1,80)
    # S = 200
    file.write(str(S) + '\n')
    for i in range(S):
        file.write(str(rand(2, 1e12)) + '\n')
        # file.write(str(1000000000000) + '\n')
    file.close()
