import math

a,b =[int(x) for x in input().split()]
mmc=4
v=[int(x) for x in input().split()]
for i in range(a):
    mmc=(mmc*v[i])//(math.gcd(mmc,v[i]))
res = 2020+mmc
minimo = 2020+b

while(res<minimo):
    res+=mmc
print(res)