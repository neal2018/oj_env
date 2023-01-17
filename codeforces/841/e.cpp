#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, m;
    cin >> n >> m;
    ll total = n * (n + 1) / 2 - n;
    if (m > total) {
      cout << "-1\n";
      continue;
    }
  }
}
