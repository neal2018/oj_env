#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

ll ask(ll i, ll j, ll k) {
  ll res;
  cout << "? " << i + 1 << " " << j + 1 << " " << k + 1 << endl;
  cin >> res;
  return res;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    auto get_minimax = [&](ll a0, ll a1, ll a2, ll a3) -> pair<int, int> {
      array<ll, 4> tmp, a = {a0, a1, a2, a3}, p = {0, 1, 2, 3};
      tmp[0] = ask(a1, a2, a3);
      tmp[1] = ask(a2, a3, a0);
      tmp[2] = ask(a3, a0, a1);
      tmp[3] = ask(a0, a1, a2);
      sort(p.begin(), p.end(), [&](ll x, ll y) { return tmp[x] < tmp[y]; });
      return {a[p[0]], a[p[1]]};
    };
    auto [x, y] = get_minimax(0, 1, 2, 3);
    int cur = 4;
    for (; cur + 2 <= n; cur += 2) {
      tie(x, y) = get_minimax(x, y, cur, cur + 1);
    }
    if (cur < n) {
      int extra = 0;
      while (extra == x || extra == y) extra++;
      tie(x, y) = get_minimax(x, y, cur, extra);
    }
    cout << "! " << x + 1 << " " << y + 1 << endl;
  }
}
