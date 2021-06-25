
cont = 0
for i in range(12):
    j = int(input())
    if (j%2==0):
        cont += j
    else:
        cont += j-1
print(cont)
