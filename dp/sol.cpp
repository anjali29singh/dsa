#include <bits/stdc++.h>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    int s[m];
    for (int i=0;i<m;i++)
        cin>>s[i];
    int long long dp[m+1][n+1];
     dp[0][0]=1;
    for (int i=0;i<=m;i++){
        for (int j=0;j<=n;j++){
             if (j==0)
                dp[i][j]=1;
            else if (i==0)
                dp[i][j]=0;
            else if (s[i-1]>j) 
                dp[i][j]=dp[i-1][j];
            else   
                dp[i][j]=dp[i-1][j]+dp[i][j-s[i-1]];
        }
    }
    cout<<dp[m][n]<<endl;
    return 0;
}