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
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    for (auto& x : a) {
      int k;
      string s;
      cin >> k >> s;
      ll up = count(s.begin(), s.end(), 'U');
      ll down = count(s.begin(), s.end(), 'D');
      x = (x + down - up + 10) % 10;
    }
    for (auto& x : a) cout << x << " ";
    cout << "\n";
  }
}
