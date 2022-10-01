#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,W;
    cin>>N>>W;
    vector<int> wt(N);
    vector<int> val(N);
    for (int i=0; i<N; i++)
        cin>>wt[i];
    for (int i=0; i<N; i++)
        cin>>val[i];

    int dp[N+1][W+1];
    for (int i=0; i<=N; i++){
        for (int j=0; j<=W; j++){
            if (i==0 || j==0)
                dp[i][j]=0;
            else if (wt[i-1]<=j)
                dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);
            else
                dp[i][j]=dp[i-1][j];
        }

    }
    cout<<dp[N][W]<<endl;



    return 0;
}