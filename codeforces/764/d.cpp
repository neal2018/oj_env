#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094
constexpr ll MOD = 1e9 + 7;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  cin >> T;
  for (; T--;) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> a(26);
    for (auto& c : s) a[c - 'a']++;
    int even = 0, odd = 0;
    for (auto& x : a) {
      if (x & 1) odd++;
      even += 2 * (x / 2);
    }
    int res = even / 2 / k * 2 + (odd >= k);
    if (odd < k) {
      int need = k - odd;
      if (need & 1) need++;
      even -= need;
      res = max(res, even / 2 / k * 2 + 1);
    }
    cout << res << "\n";
  }
}