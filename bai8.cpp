#include <iostream>
#include <vector>
#include <deque>

using namespace std;

typedef long long ll;
ll p, f;
deque<bool> a;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>p>>f;
    a.push_back(0);
    while(f--){
        vector<bool>tmp(a.size());
        for (size_t i = 0; i < a.size(); i++){
            tmp[i]=1-a[i];
        }
        for (int i=(int)tmp.size()-1;i>=0;i--){
            a.push_front(tmp[i]);
        }
    }
    p--;
    if (p<a.size()) {
        if(a[p]==0)cout<<'U';
        else cout<<'D';
    }

    return 0;
}
