#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  auto ask = [](ll a, ll b) {
    ll res = 0;
    cout << "? " << a << " " << b << endl;
    cin >> res;
    if (res == 0) exit(0);
    return res;
  };
  ll cur = 2;
  while (true) {
    auto tmp = ask(1, cur);
    if (tmp == -1) {
      cout << "! " << cur - 1 << endl;
      return 0;
    }
    auto tmp2 = ask(cur, 1);
    if (tmp != tmp2) {
      cout << "! " << tmp + tmp2 << endl;
      return 0;
    }
    cur++;
  }
}
