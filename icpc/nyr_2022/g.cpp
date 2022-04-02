#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  vector<ll> a(1000);
  auto s = [&](int i) { return (i % 2 == 0 ? (i / 2) : i + 1); };
  for (int i = 1; i < 4; i++) {
    int cnt = 0;
    while (i != 1) {
      cnt++;
      i = s(i);
    }
    a[i]++;
  }
  for (int i = 0; i < 10; i++) {
    cout << i << " " << a[i] << "\n";
  }
}
