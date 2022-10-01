n, t = list(map(int, input().split()))
k = list(map(int, input().split()))
k.sort()


def possible(m):
    totalprod = 0
    for i in k:
        totalprod = totalprod+(m//i)
    if totalprod >= t:
        return 1
    else:
        return 0


left = 0
right = int(1e19)
while(left+1 < right):
    mid = (left+right)//2
    if possible(mid):
        right = mid
    else:
        left = mid
print(right)
