from random import randint as rand
import math

for case_name in range(1, 1+int(input("Resolver quantos casos? -> "))):
    file_in = open('../input/' + str(case_name), 'r')
    file_out = open('../output/' + str(case_name), 'w')
    a, b = [int(i) for i in file_in.readline().split()]
    v = [int(j) for j in file_in.readline().split()]
    mmc=4
    for i in range(a):
        mmc=(mmc*v[i])//(math.gcd(mmc,v[i]))
    res = 2020+mmc
    minimo = 2020+b

    while(res<minimo):
        res+=mmc
    file_out.write(str(res) + '\n')