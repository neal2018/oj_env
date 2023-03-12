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
    int res = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (a[i] < a[j]) res++;
      }
    }
    cout << res << "\n";
  }
}
