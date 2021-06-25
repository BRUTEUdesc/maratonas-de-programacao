
for case_name in range(1, 101):
    file_in = open('../input/' + str(case_name), 'r')
    file_out = open('../output/' + str(case_name), 'w')

    cont = 0
    for i in range(12):
        x = int(file_in.readline())
        if x%2==0:
            cont += x
        else:
            cont += x-1
    file_out.write(str(cont)+"\n")
    file_in.close()
    file_out.close()