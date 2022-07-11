#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  if (n == 2) {
    cout << "1 1\n";
    return 0;
  }
  ll a = 0, b = 1, c = 0;
  while (a + b <= n) {
    c = a + b, a = b, b = c;
  }
  cout << a << ' ' << b << "\n";
}
