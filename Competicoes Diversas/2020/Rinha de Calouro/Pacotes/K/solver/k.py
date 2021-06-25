import math

casos = int(input())

for i in range(casos):
    num = int(input())

    for j in range(2, int(math.sqrt(num))+1):
        if num % j == 0:
            print("ei Kaqui, esse numero nao eh primo")
            break
    else:
        aux = int(math.log(num, 10)) + 1
        print(aux)
