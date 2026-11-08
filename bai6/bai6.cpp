#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
ll a[4][4];
bool vis[4][4];
pll par[4][4];
pll last;
const ll dx[]={0,0,-1,1};
const ll dy[]={-1,1,0,0};

bool check(ll x, ll y){
    return(0<=x && x<3 && 0<=y && y<3);
}

void dijkstra(ll x, ll y){
   queue<pll>q;
   q.push({x,y});
   vis[x][y]=true;
   while (!q.empty()){
        ll cx=q.front().first;
        ll cy=q.front().second;
        q.pop();
        ll mx=-1;
        pair<ll,ll> ch={-1,-1};
        for (int i=0;i<4;i++){
            ll u=cx+dx[i];
            ll v=cy+dy[i];
            if (check(u,v)&&!vis[u][v]){
                if (a[u][v]>mx){
                    mx=a[u][v];
                    ch={u,v};
                }
            }
        }
        if (ch.first!=-1){
            vis[ch.first][ch.second]=true;
            par[ch.first][ch.second]={cx,cy};
            last=ch;
            q.push(ch);
        }
   }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t;
    cin>>t;
    while (t--){
        pair<ll,ll>st;
        memset(vis,false,sizeof(vis));
        memset(par,0,sizeof(par));
        for (int i=0;i<3;i++){
            for (int j=0;j<3;j++){
                cin>>a[i][j];
                //a[i][j] khac nhau hoan toan
                if (a[i][j]==9){
                    st={i,j};
                }
            }
        }
        last=st;
        dijkstra(st.first,st.second);
        vector<ll>pa;
        pll tmp=last;
        while (tmp!=st){
            pa.push_back(a[tmp.first][tmp.second]);
            pll x=par[tmp.first][tmp.second];
            tmp=x;
        }
        reverse(pa.begin(),pa.end());
        for (ll it:pa){
            cout<<it;
        }
        cout<<"\n";
    }
    return 0;
}
