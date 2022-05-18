#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    if (n < 4 || (n % 4) % 2 != 0) {
      cout << "-1\n";
      continue;
    }
    ll mini = n / 4;
    ll maxi = (n / 24) * 4;
    ll remain = n % 24;
    maxi += remain / 6 + (remain % 6 != 0);
    // maxi = (n + 6) / 6;
    cout << maxi << " " << mini << "\n";
  }
}
