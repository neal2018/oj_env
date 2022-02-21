#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m;
  cin >> n >> m;
  if (n == 1 && m == 1) {
    cout << "1\n 1 1 1 1\n";
    return 0;
  }
  ll t = 1;
  while (2 * t <=  n * m) t *= 2;
  cout << 2 * t - 1 << "\n";
  ll two = t * 2;
  t--;
  ll r_t = t / m + 1;
  ll c_t = t % m + 1;
  if ((t + 1) % m != 1 && m != 1) {
    cout << r_t << " " << c_t - 1 << " " << r_t << " " << c_t << "\n";
  } else {
    cout << r_t - 1 << " " << m / 2 + 1 << " " << r_t << " " << m / 2 + 1 << "\n";
  }
}
