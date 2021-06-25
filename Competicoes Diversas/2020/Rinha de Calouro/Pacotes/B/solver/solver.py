v = [int(i) for i in input().split()]

for i in range(int(input())):
    a, b = map(int, input().split())
    v[a-1], v[b-1] = v[b-1], v[a-1]

print(v.index(1) + 1)
