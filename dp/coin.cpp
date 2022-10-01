#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,N;
    cin>>m>>N;  // number of  different denominations
    int Val[m];
    for (int i=0; i<m;i++)
        cin>>Val[i];
    int dp[m+1][N+1];
    for (int i=0; i<=m;i++){
        for (int j=0;j<=N;j++){
            if (i==0 ||  j==0)
                dp[i][j]==0;
            else if (Val[i-1]>j)   // 0 base indexing in val
               dp[i][j]=dp[i-1][j];
            else if (Val[i-1]<=j)
                dp[i][j]=1+dp[i][j-Val[i-1]];  // j-value[i-1]=remaining amount after taking coin
              }
    }
    cout<<dp[m][N]<<endl;
    return 0;

}