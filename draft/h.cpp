#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
      cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, c;
    cin>>n;
    vector<int> p(n), a(n), b(n);
    for(auto&x:p)cin>>x;
    for(auto&x:a)cin>>x;
    for(auto&x:b)cin>>x;
    vector<set<pair<int,int>>> st(4);
    for(int i=0;i<n;i++){
        st[a[i]].insert({p[i], i});
        if (a[i]!=b[i]) st[b[i]].insert({p[i], i});
    }
    cin>>m;
    vector<int> res(m, -1);
    for(int i=0;i<m;i++){
        cin>>c;
        if (st[c].size()==0)continue;
        auto [cc, index] = *st[c].begin();
        st[c].erase(*st[c].begin());
        if (st[a[index]].count(pair{p[index], index})){
            st[a[index]].erase({p[index], index});
        }
        if (st[b[index]].count(pair{p[index], index})){
            st[b[index]].erase(pair{p[index], index});
        }
        res[i]=p[index];
    }
    for(int i=0;i<m;i++)cout<<res[i]<<" ";
    cout<<'\n';
}