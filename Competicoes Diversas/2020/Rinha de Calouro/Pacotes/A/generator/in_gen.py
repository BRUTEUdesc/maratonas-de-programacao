from random import randint

for case_name in range(1,101):
    file = open('../input/' + str(case_name), 'w')
    for i in range(12):
        file.write(str(randint(1,1000000000))+"\n")
    file.close()