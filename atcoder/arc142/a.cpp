#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, k;
  cin >> n >> k;
  string sk = to_string(k);
  ll rev_k = stoll(string(sk.rbegin(), sk.rend()));
  if (k > rev_k) {
    cout << "0\n";
    return 0;
  }
  ll res = 0;
  for (ll t = k; t <= n; t *= 10) {
    res++;
  }
  if (rev_k != k) {
    for (ll t = rev_k; t <= n; t *= 10) {
      res++;
    }
  }
  cout << res << "\n";
}

