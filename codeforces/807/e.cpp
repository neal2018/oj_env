#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto& x : a) cin >> x;

  map<int, int> mp;
  mp[-1] = 0;  // [l, r)

  auto add = [&](int x) {
    auto it = --mp.upper_bound(x);
    if (it->second <= x) {
      mp[x] = x + 1;
    } else {
      if (it->first != x) {
        mp[x] = it->second;
        it->second = x;
      }
      it = mp.find(x);
      int pre = it->second;
      while (true) {
        it = mp.erase(it);
        if (it == mp.end() || it->first != pre) break;
        pre = it->second;
      }
      mp[pre] = pre + 1;
    }
  };

  auto sub = [&](int x) {
    auto it = --mp.upper_bound(x);
    if (it->second <= x) {
      it = mp.upper_bound(x);
      mp[x] = it->first;
      if (it->second != it->first + 1) {
        mp[it->first + 1] = it->second;
      }
      mp.erase(it);
    } else {
      if (it->first != x) {
        mp[x] = it->second;
        it->second = x;
      }
      if (mp[x] != x + 1) {
        mp[x + 1] = mp[x];
      }
      mp.erase(x);
    }
  };

  for (auto& x : a) add(x);

  while (q--) {
    int p, x;
    cin >> p >> x, p--;
    sub(a[p]);
    a[p] = x;
    add(a[p]);
    cout << (mp.rbegin()->second - 1) << "\n";
  }
}
