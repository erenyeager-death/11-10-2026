#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n,k;
    cin>>n>>k;
    while (true) {
        ll m=k%n;
        if(m==0)m=n;
        if(m==n) {
            cout<<m<<"\n";
            return 0;
        }
        k=m+n;
        n=m;
    }
    return 0;
}
