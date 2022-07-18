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
    int t = n;
    for (int cnt = 0; t > 1 && cnt < 5; cnt++) {
      vector<int> b(t - 1);
      for (int i = 0; i < t - 1; i++) b[i] = a[i + 1] - a[i];
      sort(b.begin(), b.end());
      a = b, t--;
    }
    auto zero = 0;
    vector<int> c;
    for (auto& x : a) {
      if (x == 0) {
        zero++;
      } else {
        c.push_back(x);
      }
    }
    if (c.size() == 0) c = {0};
    t = int(c.size());
    while (t > 1) {
      vector<int> b;
      b.reserve(t + 1);
      if (zero > 0) {
        b.push_back(c[0]);
        zero--;
      }
      for (int i = 0; i < t - 1; i++) b.push_back(c[i + 1] - c[i]);
      sort(b.begin(), b.end());
      c = b;
      t = int(c.size());
    }
    cout << c[0] << "\n";
  }
}
