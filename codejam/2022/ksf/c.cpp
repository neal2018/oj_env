#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

void print(__int128 x) {
  constexpr ll P = 1e18;
  if (x < P) {
    cout << ll(x) << "\n";
  } else {
    cout << ll(x / P) << setw(18) << setfill('0') << ll(x % P) << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  for (int case_no = 1; case_no <= T; case_no++) {
    cout << "Case #" << case_no << ": ";
    ll d, n, limit;
    cin >> d >> n >> limit;
    vector<array<ll, 3>> a(n);
    for (auto& [time, profit, cnt] : a) cin >> cnt >> time >> profit;
    sort(a.begin(), a.end());
    priority_queue<pair<ll, ll>> pq;  // profit, cnt
    ll i = 0, days = 1;              // remaining days
    __int128 res = 0;
    while (days < d) {
      while (i < n && a[i][0] <= days) {
        pq.push({a[i][1], a[i][2]}), i++;
      }
      ll nex = i == n ? d : a[i][0];
      __int128 advance = min(nex - days, d - days);
      __int128 plan = advance * limit;
      while (plan > 0 && pq.size()) {
        auto [profit, cnt] = pq.top();
        pq.pop();
        __int128 use = min(__int128(cnt), plan);
        res += use * profit;
        cnt -= use;
        plan -= use;
        if (cnt > 0) {
          pq.push({profit, cnt});
        }
      }
      days += advance;
    }
    print(res);
  }
}
