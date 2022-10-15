#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  map<int, vector<int>> mp;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i], mp[a[i]].push_back(i);
  vector<int> res(n);
  auto it = mp.end();
  int k = 0;
  while (it != mp.begin()) {
    it--;
    res[k] = it->second.size();
    k++;
  }
  for (auto& x : res) cout << x << "\n";
}
