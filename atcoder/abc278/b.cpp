#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  auto tran = [](int h, int m) {
    int hh = h / 10 * 10 + m / 10;
    int mm = h % 10 * 10 + m % 10;
    return pair{hh, mm};
  };
  auto check = [&](int h, int m) {
    auto [hh, mm] = tran(h, m);
    if (hh <= 23 && mm <= 59) {
      return true;
    } else {
      return false;
    }
  };
  int h, m;
  cin >> h >> m;
  while (true) {
    if (check(h, m)) {
      cout << h << " " << m << "\n";
      return 0;
    }
    m++;
    if (m == 60) h++, m = 0;
    if (h == 24) h = 0;
  }
}
