#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n,k;
    cin>>n>>k;
    vector<int>divs;
    for(int i=k;i>=2;i--){
        if(k%i==0)divs.push_back(i);
    }
    vector<bool>dp(n+1,false);
    vector<int>from(n+1,-1);
    dp[0]=true;
    for(int i=0;i<=n;i++){
        if(!dp[i])continue;
        for(int d:divs){
            if(i+d<=n&&!dp[i+d]){
                dp[i+d]=true;
                from[i+d]=d;
            }
        }
    }
    if(!dp[n]){
        cout<<0<<"\n";
        return 0;
    }
    map<int,int,greater<int>>counts;
    int curr=n;
    while(curr>0){
        int d=from[curr];
        counts[d]++;
        curr-=d;
    }
    for(auto&p:counts){
        cout<<p.first<<" "<<p.second<<"\n";
    }
    return 0;
}
