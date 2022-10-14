#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  for (int case_no = 1; case_no <= T; case_no++) {
    cout << "Case #" << case_no << ": ";
    int n;
    cin >> n;
    array<set<int>, 4> a;
    for (auto& r : a) {
      for (int i = 0, x; i < n / 4; i++) cin >> x, r.insert(x);
    }
    int win = 0;
    for (int _ = 0; _ < n / 4; _++) {
      int maxi = 0;
      int cur = 0;
      auto play_small = [&](int id, int t) {
        auto p = *a[id].begin();
        a[id].erase(p);
        if (p > maxi) {
          maxi = p, cur = t;
        }
      };
      auto play_large = [&](int id, int t, int need) {
        auto p = *a[id].lower_bound(need);
        a[id].erase(p);
        if (p > maxi) {
          maxi = p, cur = t;
        }
      };
      play_small(0, 0);
      if (maxi > *a[1].rbegin()) {
        play_small(1, 1);
      } else {
        auto it = a[1].lower_bound(maxi);
        auto it2 = a[3].lower_bound(maxi);
        if (it2 != a[3].end() && *it2 < *it) {
          play_small(1, 1);
        } else {
          play_large(1, 1, maxi);
        }
      }
      if (maxi > *a[2].rbegin()) {
        play_small(2, 0);
      } else {
        play_large(2, 0, *a[2].rbegin());
      }
      if (cur == 1 || maxi > *a[3].rbegin()) {
        play_small(3, 1);
      } else {
        play_large(3, 1, maxi);
      }
      win += (cur == 0);
    }
    cout << win << "\n";
  }
}
