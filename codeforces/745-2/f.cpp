#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct SegTree {
  ll n;
  vector<ll> t;
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> a(n), pre(n + 1);
  for (auto& x : a) cin >> x;
  for(int i = 0; i < n; i++) pre[i+1] = pre[i] + a[i];
  ll maxi=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      ll cur = 0;
    }
  }
  cout<<maxi<<'\n';
}