#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a * 60 + b <= c * 60 + d) {
    cout << "Takahashi\n";
  } else {
    cout << "Aoki\n";
  }
}
