#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
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
    multiset<ll> st;
    ll sum = 0, res = 0, num = 0;
    auto curr = st.end();
    for (auto& v : a) {
      for (auto& x : v) {
        if (x > 0) {
          if (st.size() < k) {
            st.insert(-x);
            auto curr = st.end();
            sum += x;
          } else {
            if (curr == st.end() || x > -*curr) {
              st.insert(-x);
              curr--;
              sum += x + *curr;
            } else {
              st.insert(-x);
            }
          }
        } else {
          x = -x;
          auto toremove = st.find(-x);
          if (st.size() <= k) {
            st.erase(toremove);
            auto curr = st.end();
            sum -= x;
          } else {
            if (toremove == curr) {
              curr++;
              st.erase(toremove);
            } else {
              if (x >= -*curr) {
                st.erase(toremove);
                sum = sum - x - *curr;
                curr++;
              } else {
                st.erase(toremove);
              }
            }
          }
        }
      }
      res = max(res, sum);
    }
    cout << "Case #" << case_num << ": " << res << '\n';
  }
  return 0;
}