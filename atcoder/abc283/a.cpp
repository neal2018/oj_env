#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll power(ll a, ll b, ll res = 1) {
  for (; b; b /= 2, (a *= a))
    if (b & 1) (res *= a);
  return res;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int a, b;
  cin >> a >> b;
  cout << power(a, b) << "\n";
}
