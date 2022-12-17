#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    int zero_total = int(count(a.begin(), a.end(), 0));
    ll inv = 0;
    for (int cur = 0; auto& x : a) {
      if (x == 0) {
        inv += cur;
      } else {
        cur++;
      }
    }
    ll extra = 0;
    for (int one = 0, zero = 0; auto& x : a) {
      ll temp = 0;
      if (x == 0) {
        temp = -one + (zero_total - zero - 1);
      } else {
        temp = one - (zero_total - zero);
      }
      extra = max(extra, temp);
      (x == 0 ? zero : one)++;
    }
    cout << inv + extra << "\n";
  }
}
