#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod=1e9+9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t;
    cin>>t;
    while (t--){
        ll a,n;
        cin>>a>>n;
        ll res=1;
        while (n>0){
            if (n%2==1){
                res*=a;
            }
            a*=a;
            n/=2;
        }
        cout<<res<<"\n";
    }
    return 0;
}

