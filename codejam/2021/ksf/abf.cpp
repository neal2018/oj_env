#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define IO
ll INF = 1e18;

int main(int, char**) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll total_cases_number, d, n, k, h, s, e;
  cin >> total_cases_number;
  for (ll case_num = 1; case_num <= total_cases_number; case_num++) {
    cin >> d >> n >> k;
    vector<vector<ll>> a(d + 2);
    for (int i = 0; i < n; i++) {
      cin >> h >> s >> e;
      a[s].push_back(h);
      a[e + 1].push_back(-h);
    }
    map<ll, ll> mp;
    ll sum = 0, res = 0, cnt = 0, num = 0, curr = 0;
    for (auto& v : a) {
      for (auto& x : v) {
        if (x > 0) {
          mp[-x]++;
          cnt++;
        } else {
          mp[x]--;
          if (mp[x] == 0) {
            mp.erase(x);
          }
          cnt--;
        }
      }
      auto it = mp.begin();
      sum = 0;
      for (ll i = min(k, (ll)cnt); i >= 0 && it != mp.end();) {
        sum -= it->first * min(it->second, i);
        i -= min(it->second, i);
        it++;
      }
      res = max(res, sum);
    }
    cout << "Case #" << case_num << ": " << res << '\n';
  }
  return 0;
}