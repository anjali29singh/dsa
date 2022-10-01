#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;  
    cin>>n;
    string s;
    cin>>s;
    string a="";
    for (int i=n-1;i>=0;i--)
        a=a+s[i];
    cout<<a<<endl;
    int dp[n+1][n+1];
    for (int i=0;i<=n;i++){
        for (int j=0; j<=n;j++){
            if (i==0 || j==0)
                dp[i][j]=0;
            else if (s[i-1]==a[i-1])
                dp[i][j]=dp[i-1][j-1] +2;
            else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }
    cout<<dp[n][n];

    return 0;
}