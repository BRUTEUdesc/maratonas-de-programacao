from random import randint
from random import shuffle

casos = int(input("Gerar quantos casos? ->"))

for caso in range(1, casos+1):
    file = open('../input/' + str(caso), 'w')

    list = ['1', '0', '0', '0']
    shuffle(list)
    file.write(" ".join(list) + '\n')
    file.write(str(10**5) + '\n')
    for i in range(10**5):
        file.write(str(randint(1, 4)) + " " + str(randint(1, 4))  + '\n')
    file.close()

