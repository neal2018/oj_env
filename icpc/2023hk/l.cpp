#include <bits/stdc++.h>
using namespace std;
using ll = long long;


struct SegTreeSum {
  int n;
  vector<int> t;
  SegTreeSum(int _n) : n(_n), t(2 * n) {}
  void modify(int p, int v) {
    t[p += n] = v;
    for (p /= 2; p; p /= 2) t[p] = t[2 * p] + t[2 * p + 1];
  }
  int query(int l, int r) {
    int res = 0;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) res += t[l++];
      if (r & 1) res += t[--r];
    }
    return res;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m), magic(k);
    for (auto& x : a) cin >> x, x--;
    for (auto& x : b) cin >> x, x--;
    for (auto& x : magic) cin >> x;
    if ([&] {
          vector<array<int, 2>> remove;
          remove.reserve(n);
          {
            int i = 0, j = 0;
            while (i < n && j < m) {
              while (i < n && j < m && a[i] != b[j]) {
                remove.push_back({a[i], i});
                i++;
              }
              if (i < n) i++, j++;
            }
            if (j != m) return false;
            while (i < n) {
              remove.push_back({a[i], i});
              i++;
            }
          }
          sort(remove.rbegin(), remove.rend());

          SegTreeSum seg_sum(n);
          for (int i = 0; i < n; i++) seg_sum.t[i + n] = 1;
          for (int i = n - 1; i >= 0; i--) seg_sum.t[i] = seg_sum.t[2 * i] + seg_sum.t[2 * i + 1];

          multiset<int> magic_set;
          for (auto& x : magic) magic_set.insert(-x);
          int done = 0, cur = n - 1;
          set<int> exist;
          vector<int> all_pos(n);
          for (int i = 0; i < n; i++) all_pos[a[i]] = i;
          for (int i = 0; i < remove.size(); i++) {
            int v = remove[i][0], pos = remove[i][1];
            while (cur > v) {
              exist.insert(all_pos[cur]), cur--;
            }
            cur = v - 1;
            int left = [&] {
              auto it = exist.lower_bound(pos);
              if (it == exist.begin()) return 0;
              return *(--it) + 1;
            }();
            int right = [&] {
              auto it = exist.lower_bound(pos);
              if (it == exist.end()) return n - 1;
              return (*it) - 1;
            }();
            int need = seg_sum.query(left, right + 1);
            auto it = magic_set.lower_bound(-need);
            if (it == magic_set.end()) break;
            done++, magic_set.erase(it);
            seg_sum.modify(pos, 0);
          }
          return done == remove.size();
        }()) {
      cout << "YES\n";
    } else {
      // assert(false);
      cout << "NO\n";
    }
  }
}
