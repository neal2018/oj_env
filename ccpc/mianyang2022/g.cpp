#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x, x--;
  set<int> avail, bad;
  for (int i = 0; i < n; i++) avail.insert(i);
  int step = 0;
  for (int i = 0; i < n; i++) {
    if (i > 0 && a[i - 1] > a[i]) bad.insert(i);
    if (i < n - 1 && a[i + 1] > a[i]) bad.insert(i);
  }
  auto check = [&](auto it) {
    auto nex = next(it);
    if (it != avail.begin() && a[*prev(it)] > a[*it]) return true;
    if (nex != avail.end() && a[*nex] > a[*it]) return true;
    return false;
  };
  while (avail.size() > 1) {
    step++;
    for (auto& x : bad) avail.erase(x);
    set<int> next_bad;
    for (auto& x : bad) {
      auto it = avail.upper_bound(x);
      if (it != avail.end() && check(it)) next_bad.insert(*it);
      if (it != avail.begin() && check(--it)) next_bad.insert(*it);
    }
    bad = next_bad;
  }
  cout << step << "\n";
}
