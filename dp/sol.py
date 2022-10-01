n,m=list(map(int,input().split()))
c=list(map(int,input().split()))
c.sort()
dp=[0]*(n+1)
dp[0]=1
dp[c[0]]=1
for i in range(2,n+1):
    dp[i]=dp[i-1]+1
print(dp)
