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
    int maxi1 = -1, maxi2 = -1;
    for (auto& x : a) {
      if (x > maxi1) {
        maxi2 = exchange(maxi1, x);
      } else if (x > maxi2) {
        maxi2 = x;
      }
    }
    for (auto& x : a) {
      if (x == maxi1) {
        cout << x - maxi2 << " ";
      } else {
        cout << x - maxi1 << " ";
      }
    }
    cout << "\n";
  }
}
