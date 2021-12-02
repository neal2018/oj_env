#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll N = 1 << 20;
  vector<ll> a(N, -1);
  ll q, t, x;
  cin >> q;
  set<int> pos;
  for (int i = 0; i < N; i++) pos.insert(i);
  while (q--) {
    cin >> t >> x;
    if (t == 1) {
      int h = x % N;
      auto it = pos.lower_bound(h);
      if (it == pos.end()) it = pos.begin();
      a[*it] = x;
      pos.erase(it);
    } else {
      cout << a[x % N] << '\n';
    }
  }
}