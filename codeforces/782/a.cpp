#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    ll n, r, b;
    cin >> n >> r >> b;
    ll avg = r / (b + 1);
    ll extra = r % (b + 1);
    if (extra) {
      cout << string(avg + 1, 'R');
      extra--;
    } else {
      cout << string(avg, 'R');
    }
    for (int i = 0; i < b; i++) {
      cout << 'B';
      if (extra) {
        cout << string(avg + 1, 'R');
        extra--;
      } else {
        cout << string(avg, 'R');
      }
    }
    cout << "\n";
  }
}
