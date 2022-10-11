N = int(input())
X = list(map(int, input().split()))
V = list(map(int, input().split()))


def possible(t):
    l = 0
    r = 10**12
    for i in range(N):
        l = max(l, X[i]-(V[i]*t))
        r = min(r, X[i]+(V[i]*t))
    if (r-l) >= 0:
        return 1
    else:
        return 0


left = 0
right = 100000000000
for i in range(1, 101):
    t = (left+right)/2
    if possible(t):
        right = t
    else:
        left = t
print(right)
