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
    int t = int(sqrt(n - 1)) + 1;
    int maxi = n, n_maxi = t * t - (n - 1);
    vector<int> a(n);
    for (int i = n - 1; i >= 0; i--) {
      a[i] = t * t - i;
      if (a[i] >= maxi) {
        while (t * t - i >= n_maxi) t--;
        a[i] = t * t - i;
        maxi = n_maxi, n_maxi = a[i];
      }
    }
    for (auto& x : a) cout << x << " ";
    cout << "\n";
  }
}
