
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(10);
  int T;
  cin >> T;
  map<ll, vector<ll>> res;
  vector<ll> stk;
  function<void(ll, ll, ll, ll)> dfs = [&](ll cur_sum, ll cur_mul, ll cnt, ll mini) {
    if (cur_sum == 41) {
      if (!res.count(cur_mul)) {
        res[cur_mul] = stk;
      } else {
        if (res[cur_mul].size() > stk.size()) {
          res[cur_mul] = stk;
        }
      }
      return;
    }
    for (ll t = mini; t + cur_sum <= 41; t++) {
      stk.push_back(t);
      dfs(cur_sum + t, cur_mul * t, cnt + 1, t);
      stk.pop_back();
    }
  };

  dfs(0, 1, 0, 1);

  for (int test_case_no = 1; test_case_no <= T; test_case_no++) {
    ll p;
    cin >> p;
    cout << "Case #" << test_case_no << ": ";
    if (!res.count(p)) {
      cout << "-1\n";
    } else {
      cout << res[p].size() << " ";
      for (auto& x : res[p]) cout << x << " ";
      cout << "\n";
    }
  }
}
