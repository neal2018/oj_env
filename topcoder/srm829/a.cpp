#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

class GameShowTotal {
public:
  string verify(int n, vector<int> a, int w) {
    reverse(a.begin(), a.end());
    ll cur = 0;
    ll f = 0;
    if (cur == w) f = 1;
    for (auto& x : a) {
      cur += x;
      if (cur == w) f = 1;
    }
    return f ? "possible" : "impossible";
  }
};
