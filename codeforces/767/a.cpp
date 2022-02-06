#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  cin >> T;
  for (; T--;) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    vector<int> b;
    vector<deque<int>> v(n + 1);
    for (int i = 0; i < n; i++) v[a[i]].push_back(i);
    function<void(int)> work = [&](int start) {
      if (start == n) return;
      int not_have = n + 1, maxi = start;
      for (int i = 0; i <= n; i++) {
        while (v[i].size() && v[i][0] < start) v[i].pop_front();
        if (!v[i].size()) {
          not_have = i;
          break;
        } else {
          maxi = max(maxi, v[i][0]);
        }
      }
      b.push_back(not_have);
      work(maxi + 1);
    };
    work(0);
    cout << b.size() << "\n";
    for (auto& x : b) cout << x << " ";
    cout << "\n";
  }
}