#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
using ll = long long;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  cin >> T;
  auto f = [&]() {
    int n, k;
    cin >> n >> k;
    if (k > (n + 1) / 2) {
      cout << -1 << "\n";
      return;
    }

    vector<string> s(n, string(n, '.'));
    for (int i = 0; i < k; i++) {
      s[i * 2][i * 2] = 'R';
    }
    for (auto& t : s) cout << t << "\n";
    // cout << "\n";
  };
  for (; T--;) f();
}