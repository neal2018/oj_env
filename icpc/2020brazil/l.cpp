#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (auto& x : a) cin >> x;
  int t;
  cin >> t;
  int res = 0;
  map<string, int> mp;
  while (t--) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    mp[s]++;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      map<string, int> got;
      {  // vertical
        for (int start = 0; start <= i; start++) {
          string s;
          for (int end = start; end < n; end++) {
            s += a[end][j];
            if (end >= i) {
              sort(s.begin(), s.end());
              if (mp.count(s) && !got.count(s)) got[s] = mp[s];
            }
          }
        }
      }
      {  // horizontal
        for (int start = 0; start <= j; start++) {
          string s;
          for (int end = start; end < m; end++) {
            s += a[i][end];
            if (end >= j) {
              sort(s.begin(), s.end());
              if (mp.count(s) && !got.count(s)) got[s] = mp[s];
            }
          }
        }
      }
      {  // horizontal
        int minus = min(i, j);
        int si = i - minus, sj = j - minus;
        for (; si <= i; si++, sj++) {
          string s;
          for (int cur_i = si, cur_j = sj; cur_i < n && cur_j < m; cur_i++, cur_j++) {
            s += a[cur_i][cur_j];
            if (cur_i >= i) {
              sort(s.begin(), s.end());
              if (mp.count(s) && !got.count(s)) got[s] = mp[s];
            }
          }
        }
      }
      {  // horizontal
        int minus = min(i, m - 1 - j);
        int si = i - minus, sj = j + minus;
        for (; si <= i; si++, sj--) {
          string s;
          for (int cur_i = si, cur_j = sj; cur_i < n && cur_j >= 0; cur_i++, cur_j--) {
            s += a[cur_i][cur_j];
            if (cur_i >= i) {
              sort(s.begin(), s.end());
              if (mp.count(s) && !got.count(s)) got[s] = mp[s];
            }
          }
        }
      }
      int total = 0;
      for (auto& [k, v] : got) total += v;
      if (total >= 2) res++;
      // cout << i << " " << j << " " << total << "\n";
    }
  }
  cout << res << "\n";
}
