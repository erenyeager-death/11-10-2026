#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n,s;
    cin>>s>>n;
    vector<ll>a(n);
    for (int i=0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());
    vector<ll>dp(s+1,0);
    for (int i=0;i<n;i++){
        for (int j=s;j>=a[i];j--){
            dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
        }
    }
    cout<<dp[s];
    return 0;
}
