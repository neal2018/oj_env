#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  int n;
  cin >> n;
  vector<ll> p(n), a(n);
  for (auto& x : p) cin >> x, x--;
  for (auto& x : a) cin >> x, x--;
  ll maxi = *max_element(a.begin(), a.end());
  set<ll> a_set(p.begin(), p.end());
  ll k = (maxi - (n - 1)) / (n - a_set.size());
  vector<ll> res(n);
  iota(res.begin(), res.end(), 0);
  for (; k; k /= 2) {
    if (k & 1) {
      for (int i = 0; i < n; i++) res[i] = p[res[i]];
    }
    vector<ll> nex = p;
    for (int i = 0; i < n; i++) nex[i] = p[nex[i]];
    swap(p, nex);
  }
  vector<ll> mini(n);
  vector<vector<ll>> divide(n);
  for (int i = 0; i < n; i++) divide[res[i]].push_back(i);
  for (int i = 0; i < n; i++) {
    ll cur = a[i] < n ? a[i] : -1;
    for (auto& ii : divide[i]) mini[ii] = cur;
  }

  set<ll> candidate, all_mini;
  for (auto& x : mini) all_mini.insert(x);
  for (int i = 0; i < n; i++) {
    if (!all_mini.count(i)) candidate.insert(i);
  }
  for (int i = 0; i < n; i++) {
    if (mini[i] != -1 && all_mini.count(mini[i])) {
      all_mini.erase(mini[i]);
    } else {
      auto it = candidate.lower_bound(mini[i]);
      mini[i] = *it;
      candidate.erase(it);
    }
  }
  for (auto& x : mini) cout << x + 1 << " ";
  cout << "\n";
}
