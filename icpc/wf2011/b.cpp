#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

constexpr ll MAX = 1e9;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s;
  cin >> s;
  ll n = s.size();
  ll target;
  cin >> target;
  auto get_left = [&]() {
    ll res = 0;
    for (int i = 0; i < n;) {
      if (isdigit(s[i])) {
        res = 10 * res + (s[i] - '0');
        i++;
      } else if (s[i] == '+') {
        ll nex = 0;
        i++;
        while (isdigit(s[i])) {
          nex = 10 * nex + (s[i] - '0');
          i++;
        }
        res += nex;
      } else {
        ll nex = 0;
        i++;
        while (isdigit(s[i])) {
          nex = 10 * nex + (s[i] - '0');
          i++;
        }
        res *= nex;
      }
    }
    return res;
  };
  auto get_normal = [&]() {
    ll pre = 0;
    ll res = 0;
    for (int i = 0; i < n;) {
      if (isdigit(s[i])) {
        pre = 10 * pre + (s[i] - '0');
        i++;
      } else if (s[i] == '+') {
        i++;
        res += pre, pre = 0;
        ll nex = 0;
        while (isdigit(s[i])) {
          nex = 10 * nex + (s[i] - '0');
          i++;
        }
        pre = nex;
      } else {
        i++;
        ll nex = 0;
        while (isdigit(s[i])) {
          nex = 10 * nex + (s[i] - '0');
          i++;
        }
        pre *= nex;
      }
    }
    res += pre;
    return res;
  };
  ll a1 = get_left();
  ll a2 = get_normal();
  int f1 = (a1 == target), f2 = (a2 == target);
  if (f1 && f2) {
    cout << "U\n";
  } else if (f1) {
    cout << "L\n";
  } else if (f2) {
    cout << "M\n";
  } else {
    cout << "I\n";
  }
}
