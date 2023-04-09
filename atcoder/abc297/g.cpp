#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  // ll l = 3, r = 10;
  // map<ll, ll> memo{{0, 0}};
  // function<int(int)> dfs = [&](int x) {
  //   if (memo.count(x)) return memo[x];
  //   set<int> st;
  //   for (int t = l; t <= r; t++) {
  //     if (x - t >= 0) st.insert(dfs(x - t));
  //   }
  //   int i = 0;
  //   while (st.count(i)) i++;
  //   return memo[x] = i;
  // };
  // for (int i = 0; i < 100; i++) {
  //   cout << i << " " << dfs(i) << "\n";
  // }
  ll n, l, r;
  cin >> n >> l >> r;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  ll res = 0;
  for (auto x : a) {
    x %= (l + r);
    x = x / l;
    res ^= x;
  }
  if (res == 0) {
    cout << "Second\n";
  } else {
    cout << "First\n";
  }
}
