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

    int res = 0, last1 = 1e9, last2 = 1e9;

    for (auto& x : a) {
      if (last1 > last2) {
        swap(last1, last2);
      }
      if (x <= last1) {
        last1 = x;
      } else if (x <= last2) {
        last2 = x;
      } else {
        last1 = x;
        res++;
      }
    }
    cout << res << "\n";
  }
}
