#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, x, sum = 0;
  cin >> n;
  vector<ll> a(n);
  for (auto& t : a) {
    cin >> t;
    sum += t;
  }
  cin >> x;
  ll res = (x / sum) * n;
  x %= sum;
  for (int i = 0; i < n && x >= 0; i++) {
    x -= a[i];
    res++;
  }
  cout << res << endl;
}