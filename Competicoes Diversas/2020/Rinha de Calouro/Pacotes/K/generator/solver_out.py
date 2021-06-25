import math

for case_name in range(1, 1+int(input("Resolver quantos casos? -> "))):
    file_in = open('../input/' + str(case_name), 'r')
    file_out = open('../output/' + str(case_name), 'w')
    casos = int(file_in.readline())

    for i in range(casos):
        num = int(file_in.readline())

        for j in range(2, int(math.sqrt(num))+1):
            if num % j == 0:
                file_out.write("ei Kaqui, esse numero nao eh primo\n")
                break
        else:
            aux = int(math.log(num, 10)) + 1
            file_out.write(str(aux) + '\n')
