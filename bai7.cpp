#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,a[16][16],res=1e18;
vector<ll>p;

bool chk(){
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            if(abs(p[i]-p[j])==j-i)return 0;
        }
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j)cin>>a[i][j];
    }
    p.resize(n);
    for(int i=0;i<n;++i)p[i]=i+1;
    do{
        if(chk()){
            ll cur=0;
            for(int i=0;i<n;++i)cur+=a[i][p[i]-1];
            res=min(res,cur);
        }
    }while(next_permutation(p.begin(),p.end()));
    cout<<res;
    return 0;
}
