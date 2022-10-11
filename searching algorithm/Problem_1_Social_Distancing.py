N, M = list(map(int, input().split()))
grazing = []
for i in range(M):
    grazing.append(list(map(int, input().split())))
grazing.sort()


def distance(mid):
    # number of cows in grazing area placed atleast mid distance
    cows = 0
    # position of previous


l = 0
r = 1000000
while(l+1 < r):
    mid = (l+r)//2
    if distance(mid):
        l = mid
    else:
        r = mid
print(l)
