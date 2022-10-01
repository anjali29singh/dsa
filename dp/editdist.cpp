# include<bits/stdc++.h>
using namespace std;

int main(){
    string s1 , s2;
    cin>>s1>>s2;
    int m,n;
    m=s1.length();
    n=s2.length();
    int  dp[n+1][m+1];
    for (int i=0 ;i<=n; i++){
        for (int j=0;j<=m;j++){
            if (i==0)
                dp[i][j]=j;
            else if  (j==0)
                dp[i][j]=i;
            else if (s1[j-1]==s2[i-1]) // 0 base indexing of string
                dp[i][j]=dp[i-1][j-1];   
            else
                    dp[i][j]=1+min(min(dp[i-1][j-1],dp[i][j-1]),dp[i-1][j]);

        }
    }
    cout<<dp[n][m]<<endl;

    return 0;


}