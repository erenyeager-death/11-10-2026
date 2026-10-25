#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    char a[7][10];
    for(int i=1;i<=6;i++){
        for(int j=1;j<=9;j++){
            cin>>a[i][j];
        }
    }
    auto solve=[](const vector<unordered_map<char,ll>>&cnt){
        ll min_c=1e18;
        for(char c0='A';c0<='Z';c0++){
            for(char c1='A';c1<='Z';c1++){
                if(c0==c1)continue;
                for(char c2='A';c2<='Z';c2++){
                    if(c2==c1)continue;
                    ll cost=(18-(cnt[0].count(c0)?cnt[0].at(c0):0))+
                              (18-(cnt[1].count(c1)?cnt[1].at(c1):0))+
                              (18-(cnt[2].count(c2)?cnt[2].at(c2):0));
                    min_c=min(min_c,cost);
                }
            }
        }
        return min_c;
    };
    vector<unordered_map<char,ll>>hor(3);
    for(int i=1;i<=2;i++)
        for(int j=1;j<=9;j++)
            hor[0][a[i][j]]++;
    for(int i=3;i<=4;i++)
        for(int j=1;j<=9;j++)
            hor[1][a[i][j]]++;
    for(int i=5;i<=6;i++)
        for(int j=1;j<=9;j++)
            hor[2][a[i][j]]++;
    vector<unordered_map<char,ll>>ver(3);
    for(int i=1;i<=6;i++){
        for(int j=1;j<=3;j++)
            ver[0][a[i][j]]++;
        for(int j=4;j<=6;j++)
            ver[1][a[i][j]]++;
        for(int j=7;j<=9;j++)
            ver[2][a[i][j]]++;
    }
    ll res=min(solve(hor),solve(ver));
    cout<<res<<"\n";
    return 0;
}
