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
    int total = 0;
    // multiset<int> st;
    for (int i = 1; i <= n; i++) {
      total += i * (n - i + 1);
    }
    vector<array<int, 4>> res;
    int cir = 0;
    for (int len = 1; len * len <= total; len++) {
      if (total % len == 0 && total / len >= n) {
        vector<int> remain(len, total / len);
        vector<array<int, 4>> candidate;
        candidate.reserve(n * (n - 1) / 2);
        for (int cur = n; cur >= 1; cur--) {
          int k = n - cur + 1;
          for (int i = 0; i < len && k; i++) {
            while (k && remain[i] >= cur) {
              remain[i] -= cur, k--;
              candidate.push_back({remain[i], i, remain[i] + cur, i + 1});
            }
          }
        }
        if (count(remain.begin(), remain.end(), 0) == len) {
          res = candidate;
          cir = 2 * (len + total / len);
        }
      }
    }
    cout << cir << "\n";
    for (auto& [a, b, c, d] : res) {
      cout << a << " " << b << " " << c << " " << d << "\n";
    }
  }
}
