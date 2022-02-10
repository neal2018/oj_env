#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  if (-(1ll << 31) <= n && n < (1ll << 31)) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}
