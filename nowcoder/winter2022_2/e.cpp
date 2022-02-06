#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

constexpr ll inf = 1e18;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  cout << n - 1 << " ";
  if (n % 2) {
    cout << n * (n - 1) / 2 << "\n";
  } else {
    cout << n * (n - 2) / 2 + 1 << "\n";
  }
}
