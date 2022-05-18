#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  for (int case_num = 1; case_num <= T; case_num++) {
    cout << "Case #" << case_num << ": ";
    ll n, k;
    cin >> n >> k;
    ll skip = n * n - (k + 1), layer = (n - 1) / 2;
    vector<ll> id, a;
    ll cur = 0, len = n;
    for (int i = 0; i < layer; i++) {
      for (int j = 0; j < 4; j++) {
        a.push_back(8 * layer - 2 - 8 * i - 2 * j);
        id.push_back(cur + 2 + j * (len - 1));
      }
      cur += 4 * (len - 1), len -= 2;
    }
    id.pop_back(), a.pop_back();
    vector<ll> res;
    for (int i = 0; i < id.size() && skip > 0; i++) {
      if (skip >= a[i]) {
        res.push_back(i);
        skip -= a[i];
        i += 3;
      }
    }
    if (skip) {
      cout << "IMPOSSIBLE\n";
    } else {
      cout << res.size() << "\n";
      for (auto& i : res) {
        cout << id[i] << " " << id[i] + a[i] + 1 << "\n";
      }
    }
  }
}
