m=int(input())
s=list(map(int,input().split()))
n=int(input())
dp=[[0 for i in range(n+1)] for j in range(m+1)]
for i in range(1,m+1):
    for j in range(1,n+1):
        if s[i-1]>j:
            dp[i][j]=dp[i-1][j]
        else:
            if dp[i-1][j]==0:
                dp[i][j]=1+dp[i][j-s[i-1]]
            else:
                dp[i][j]=min(dp[i-1][j],1+dp[i][j-s[i-1]])
print(dp[m][n])
