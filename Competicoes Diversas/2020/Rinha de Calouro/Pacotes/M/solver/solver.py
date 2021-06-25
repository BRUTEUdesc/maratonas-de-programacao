from math import ceil

S, D = [int(i) for i in input().split()]
cont = [0 for i in range(S)]
for d in range(D):
    t = [int(i) for i in input().split()]
    for i in range(S):
        cont[i] += t[i]

media = ceil(sum(cont) / D)
pref = cont.index(max(cont))

print(str(media))
print(str(pref + 1))
