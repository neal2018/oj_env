#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  auto run = [&](vector<int> a) {
    for (int t = 0; t < 2; t++) {
      auto inv = a;
      for (int i = 0; i < a.size(); i++) {
        inv[a[i]] = i;
      }
      for (auto& x : inv) cout << x << " ";
      cout << "\n";
      a = inv;
    }
    cout << "\n";
  };
  run({2, 1, 0});
  // vector<int> a(5);
  // iota(a.begin(), a.end(), 0);
  // do {
  //   run(a);
  // } while (next_permutation(a.begin(), a.end()));
  // int T;
  // cin >> T;
  // while (T--) {
  //   int n;
  //   cin >> n;
  //   vector<int> a(n);
  //   iota(a.begin(), a.end(), 0);
  //   int res = [&] {
  //     int cnt = 0;
  //     do {
  //       vector<int> inv(n);
  //       for (int i = 0; i < n; i++) {
  //         inv[i] = int(find(a.begin(), a.end(), i) - a.begin());
  //       }
  //       [&] {
  //         for (int i = 0; i < n; i++) {
  //           if (abs(a[i] - inv[i]) > 1) return;
  //         }
  //         cnt++;
  //       }();
  //     } while (next_permutation(a.begin(), a.end()));
  //     return cnt;
  //   }();
  //   int res2 = [&] {
  //     int cnt = 0;
  //     do {
  //       vector<int> inv(n);
  //       for (int i = 0; i < n; i++) {
  //         inv[a[i]] = i;
  //       }
  //       [&] {
  //         for (int i = 0; i < n; i++) {
  //           if (abs(a[i] - inv[i]) > 1) return;
  //         }
  //         cnt++;
  //       }();
  //     } while (next_permutation(a.begin(), a.end()));
  //     return cnt;
  //   }();
  //   cout << res << ' ' << res2 << "\n";
  // }
}
