#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, time, easy, hard;
    cin >> n >> time >> easy >> hard;
    vector<pair<ll, ll>> a(n);
    ll easy_cnt = 0, hard_cnt = 0, cur_easy = 0, cur_hard = 0;
    for (auto& [x, y] : a) cin >> y, hard_cnt += y;
    for (auto& [x, y] : a) cin >> x;
    easy_cnt = n - hard_cnt;
    a.push_back({time + 1, 0});
    sort(a.begin(), a.end());
    ll res = 0;
    for (int i = 0, j = 0; i < n + 1; i = j) {
      if (a[i].first != 0) {
        // leaves at a[i].first-1
        ll need = easy * cur_easy + hard * cur_hard;
        if (need <= a[i].first - 1) {
          ll extra = a[i].first - 1 - need;
          ll cur = cur_easy + cur_hard;
          ll remain_easy = easy_cnt - cur_easy;
          ll remain_hard = hard_cnt - cur_hard;
          ll extra_easy = min(remain_easy, extra / easy);
          extra -= extra_easy * easy, cur += extra_easy;
          ll extra_hard = min(remain_hard, extra / hard);
          cur += extra_hard;
          res = max(res, cur);
        }
      }
      for (j = i; j < n + 1 && a[i].first == a[j].first;) j++;
      for (int k = i; k < j; k++) {
        if (a[k].second == 0) {
          cur_easy++;
        } else {
          cur_hard++;
        }
      }
    }
    cout << res << "\n";
  }
}
