#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    int lis[n];
    for(int i=0;i<n;i++)
        lis[i]=1;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    for (int i=0 ;i<n;i++){
        for (int j=0;j<i;j++){
            if (a[j]<=a[i])
                lis[i]=max(lis[i],1+lis[j]);
                        }
    }
    int x=0;
    for (int i=0;i<n;i++){
        x=max(x,lis[i]);
    }
    cout<<x<<endl;
 
    return 0;

}