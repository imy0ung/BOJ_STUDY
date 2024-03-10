#Python.py

n = int(input())
time = []

for i in range(n) :
    start, finish = map(int,input().split())
    time.append([start,finish])
time = sorted(time, key = lambda a : a[0])
time = sorted(time, key = lambda a : a[1])

last = 0
cnt = 0

for i,j in time :
    if i >= last :
        cnt += 1
        last = j
print(cnt)