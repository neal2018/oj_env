#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll ask(ll i, ll j, ll k) {
  cout << "? " << i + 1 << " " << j + 1 << " " << k + 1 << endl;
  ll res;
  cin >> res;
  return res;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    auto get_minmax = [&](int a0, int a1, int a2, int a3) -> pair<int, int> {
      array<ll, 4> tmp, a = {a0, a1, a2, a3};
      tmp[0] = ask(a[1], a[2], a[3]);
      tmp[1] = ask(a[2], a[3], a[0]);
      tmp[2] = ask(a[3], a[0], a[1]);
      tmp[3] = ask(a[0], a[1], a[2]);
      array<ll, 4> p = {0, 1, 2, 3};
      sort(p.begin(), p.end(), [&](int x, int y) { return tmp[x] < tmp[y]; });
      return {a[p[0]], a[p[1]]};
    };
    auto [x, y] = get_minmax(0, 1, 2, 3);
    int cur = 4;
    for (; cur + 2 <= n; cur += 2) {
      tie(x, y) = get_minmax(x, y, cur, cur + 1);
    }
    if (cur < n) {
      int need = 0;
      while (need == x || need == y) need++;
      tie(x, y) = get_minmax(x, y, cur, need);
    }
    cout << "! " << x + 1 << " " << y + 1 << endl;
  }
}
