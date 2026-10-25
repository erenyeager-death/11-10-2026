#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a[10][10];
bool vis[10][10];
pair<ll,ll> path[10][10];

const ll dx[]={0,0,-1,1};
const ll dy[]={-1,1,0,0};

bool check(ll x, ll y){
    return (0<=x && x<3 && 0<=y && y<3);
}

void bfs(ll x, ll y){
    queue<pair<ll,ll>>q;
    q.push({x,y});
    vis[x][y]=true;
    while (!q.empty()){
        ll cx=q.front().first;
        ll cy=q.front().second;
        q.pop();
        
        vector<pair<ll,pair<ll,ll>>>val;
        for (int i=0;i<4;i++){
            ll u=cx+dx[i];
            ll v=cy+dy[i];
            if (check(u,v)&&!vis[u][v]){
                val.push_back({a[u][v],{u,v}});
            }
        }       
        
        // Prevent segmentation fault if no unvisited neighbors exist
        if (!val.empty()){
            sort(val.begin(),val.end());
            reverse(val.begin(),val.end());
            ll xd=val[0].second.first;
            ll yd=val[0].second.second;
            
            path[cx][cy]={xd,yd}; // Store forward path for your main loop
            vis[xd][yd]=true;
            q.push({xd,yd});     // Push to queue so traversal continues
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
        memset(vis,false,sizeof(vis));
        memset(path,0,sizeof(path));
        pair<ll,ll>st;
        for (int i=0;i<3;i++){
            for (int j=0;j<3;j++){
                cin>>a[i][j];
                if (a[i][j]==9)st={i,j};
            }
        }
        bfs(st.first,st.second);
        
        ll cnt=1;
        pair<ll,ll>cur=st;
        while (cnt<=9){
            cnt++;
            cout<<a[cur.first][cur.second];
            cur=path[cur.first][cur.second];
        }
        cout<<"\n";
    }
    return 0;
}
