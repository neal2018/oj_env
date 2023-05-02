#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    vector<set<int>> need(k);
    for (auto i : ranges::iota_view(0, n)) {
      need[i % k].insert(i);
    }
    for (auto i : ranges::iota_view(0, n)) {
      need[i % k].erase(a[i] - 1);
    }
    int cnt = std::accumulate(need.begin(), need.end(), 0, [](auto prev, auto cur) {
      return prev + static_cast<int>(cur.size());
    });
    if (cnt == 0) {
      cout << "0\n";
    } else if (cnt == 2) {
      cout << "1\n";
    } else {
      cout << "-1\n";
    }
  }
}
