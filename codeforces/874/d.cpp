#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    if (n == 1) {
      for (auto& x : a) cout << x << " ";
      cout << "\n";
      continue;
    }
    reverse(a.begin(), a.end());
    auto pos = find(a.begin(), a.end(), (n == a.back()) ? n - 1 : n);
    reverse(a.begin(), pos + 1);
    auto res = a;
    for (auto i = pos + 1; i != a.end(); i++) {
      if (pos != a.begin() && i == pos + 1) continue;
      reverse(i, a.end());
      if (a > res) res = a;
      reverse(i, a.end());
    }
    for (auto& x : res) cout << x << " ";
    cout << "\n";
  }
}
