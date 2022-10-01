#include <bits/stdc++.h>
using namespace std;
int main(){    
    int n,m;
    cin>>n>>m;
    int cost[n][m];
    for (int i=0;i<n;i++){
        for(int j=0 ;j<m;j++)
            cin>>cost[i][j];
    }
    int mincost[n+1][m+1];
    for (int i =1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (i==0)
                mincost[i][0]=mincost[i-1][0]+cost[i-1][0];
            else if (j==0)
                mincost[0][j]=mincost[0][j-1]+cost[0][j-1];

            else
                mincost[i][j]= min(min(mincost[i][j-1],mincost[i-1][j]),mincost[i-1][j-1])
                +cost[i-1][j-1];


            }         
    }
    for (int i=0;i<=n;i++){
        for (int j=0;i<=m;j++)
            cout<<mincost[i][j]<<endl;
    }

    return 0;
}