#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094 1:53
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end());
    unordered_map<int, int> mp;
    mp.reserve(1024);
    int mini = 1e7;
    for (auto& x : a) {
      mp[x]++;
      mini = min(mini, x);
    }
    int maxi = 0;
    for (auto& [_, v] : mp) maxi = max(maxi, v);
    if (maxi >= n / 2) {
      cout << -1 << '\n';
      continue;
    }
    for (auto& x : a) x -= mini;
    auto check = [&](int mid) {
      unordered_map<int, int> mods;
      mp.reserve(1024);
      for (auto& x : a) {
        mods[x % mid]++;
      }
      int t = 0;
      for (auto& [_, v] : mods) t = max(t, v);
      if (t >= n / 2) {
        return true;
      } else {
        return false;
      }
    };
    set<int> poss = {1};
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int diff = a[j] - a[i];
        poss.insert(diff);
        for (int k = 2; k * k <= diff; k++) {
          if (diff % k == 0) {
            poss.insert(k);
            poss.insert(diff / k);
          }
        }
      }
    }
    for (auto i = --poss.end();; i--) {
      if (check(*i)) {
        cout << *i << '\n';
        break;
      }
      if (i == poss.begin()) {
        break;
      }
    }
  }
}