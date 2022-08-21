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
    int t = int(sqrt(2 * n));
    int maxi = n;
    vector<int> a(n);
    for (int i = n - 1; i >= 0; i--) {
      a[i] = t * t - i;
      if (a[i] >= maxi) {
        t = int(sqrt(2 * i));
        a[i] = t * t - i;
        maxi = i + 1;
      }
    }
    for (auto& x : a) cout << x << " ";
    cout << "\n";
  }
}
