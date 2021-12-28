#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long

ll ask(ll x, ll y, ll z) {
  cout << "? " << x + 1 << " " << y + 1 << " " << z + 1 << endl;
  ll res = 0;
  cin >> res;
  return res;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    vector<ll> a(n, -1);   // 1:c, 0:i
    vector<ll> tt(n, -1);  // 1:c, 0:i
    ll imp = -1, crew = -1;
    for (int i = 0; i < n; i += 3) tt[i] = ask(i, i + 1, i + 2);
    for (int i = 0; i < n - 3; i += 3) {
      if (tt[i] != tt[i + 3]) {
        ll t1 = ask(i + 1, i + 2, i + 3), t2 = ask(i + 2, i + 3, i + 4);
        if (tt[i] != t1) {
          crew = i, imp = i + 3;
        } else if (tt[i] != t2) {
          crew = i + 1, imp = i + 4;
        } else {
          crew = i + 2, imp = i + 5;
        }
        if (tt[i] == 0) swap(crew, imp);
        break;
      }
    }
    for (int i = 0; i < n; i += 3) {
      ll t = ask(i, i + 1, tt[i] ? imp : crew);
      ll t2 = ask(i + 1, i + 2, tt[i] ? imp : crew);
      if (t == !tt[i]) {
        a[i + 2] = tt[i];
        a[i + 1] = t2, a[i] = !t2;
      } else {
        a[i] = tt[i], a[i + 1] = tt[i];
        a[i + 2] = t2;
      }
    }
    cout << "! " << count(a.begin(), a.end(), 0) << ' ';
    for (int i = 0; i < n; i++) {
      if (a[i] == 0) cout << i + 1 << ' ';
    }
    cout << endl;
  }
}