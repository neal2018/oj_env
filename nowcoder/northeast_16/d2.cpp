#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  int n, q;
  cin >> n >> q;
  vector<ull> a(n);
  map<ull, ull> mp;
  for (auto &x : a) {
    cin >> x;
    if (mp.count(x) == 0) mp[x] = rng();
    x = mp[x];
  }
  vector<ull> hash(n + 1);
  for (int i = 0; i < n; i++) hash[i + 1] = hash[i] ^ a[i];
  while (q--) {
    int l, r;
    cin >> l >> r, l--;
    cout << ((hash[r] ^ hash[l]) ? "Alice\n" : "Bob\n");
  }
}
