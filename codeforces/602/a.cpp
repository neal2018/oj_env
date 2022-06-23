#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    string s;
    cin >> n >> k >> s;
    string t;
    for ([[maybe_unused]] auto i : views::iota(0, k - 1)) t += "()";
    int extra = (n - int(t.size())) / 2;
    for ([[maybe_unused]] auto i : views::iota(0, extra)) t += '(';
    for ([[maybe_unused]] auto i : views::iota(0, extra)) t += ')';
    vector<pair<int, int>> res;
    for (auto i : views::iota(0, n)) {
      if (s[i] != t[i]) {
        auto nex = [&] {
          for (auto j : views::iota(i + 1, n)) {
            if (s[j] == t[i]) return j;
          }
          return -1;
        }();
        reverse(s.begin() + i, s.begin() + nex + 1);
        res.push_back({i, nex});
      }
    }
    cout << res.size() << "\n";
    for (auto& [x, y] : res) cout << x + 1 << " " << y + 1 << "\n";
    cout << "\n";
  }
}
