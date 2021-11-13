#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  vector<ll> a(5), b(5);
  auto f = [&](int ai, int bi) {
    ai--, bi--;
    ll x = min(a[ai], b[bi]);
    a[ai] -= x, b[bi] -= x;
    if (bi - ai) b[bi - ai - 1] += x;
  };
  cin >> T;
  while (T--) {
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    for (int i = 5; i >= 1; i--) {
      f(i, i);
      for (int j = 5; j >= i; j--) f(i, j);
    }
    cout << (count_if(a.begin(), a.end(), [](int x) { return x; }) ? "No\n" : "Yes\n");
  }
}