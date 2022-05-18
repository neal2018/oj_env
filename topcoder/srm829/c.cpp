#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

class SnookerScoring {
public:
  vector<int> scoreN(int n, int r, int cc) {
    if (n <= cc + 1) {
      return vector<int>{n};
    }
    for (int i = 2; i <= cc + 1; i++) {
      for (int j = i; j <= cc + 1; j++) {
        vector<int> res;
        ll sum = 0;
        for (int k = i; k <= j; k++) {
          res.push_back(k);
          sum += k;
        }
        if (sum == n) return res;
        if (i == 2 && n - sum <= 1 + cc + 1) {
          res.insert(res.begin(), int(n - sum - 1));
          res.insert(res.begin(), 1);
          return res;
        }
      }
    }
    for (int c = cc; c >= 2; c--) {
      ll all = (2 + c + 1) * c / 2;
      if (n >= all) {
        for (int t = r; t >= 0; t--) {
          ll maxi = (1 + c + 1) * t + all;
          ll mini = (1 + 2) * t + all;
          if (n <= maxi && n >= mini) {
            ll remain = n - 3 * t - all;
            vector<ll> a;
            while (remain > 0) {
              ll minus = min(c - 1ll, remain);
              a.push_back(minus);
              remain -= minus;
            }
            vector<int> res;
            for (int i = 0, pos = 0; i < t; i++) {
              res.push_back(1);
              ll nex = 2;
              if (pos != a.size()) {
                nex += a[pos], pos++;
              }
              res.push_back((int)nex);
            }
            for (int i = 2; i <= c + 1; i++) {
              res.push_back(i);
            }
            // ll tt = accumulate(res.begin(), res.end(), 0ll);
            return res;
          }
        }
      }
    }
    {
      for (int t = r; t >= 0; t--) {
        ll maxi = (1 + cc + 1) * t;
        if (t < r) maxi += 1;
        ll mini = (1 + 2) * t;
        if (n <= maxi && n >= mini) {
          ll remain = n - 3 * t;
          vector<ll> a;
          while (remain > 0) {
            ll minus = min(cc - 1ll, remain);
            a.push_back(minus);
            remain -= minus;
          }
          vector<int> res;
          for (int i = 0, pos = 0; i < t; i++) {
            res.push_back(1);
            ll nex = 2;
            if (pos != a.size()) {
              nex += a[pos], pos++;
            }
            res.push_back((int)nex);
          }
          if (remain == -1) res.push_back(1);
          // ll tt = accumulate(res.begin(), res.end(), 0ll);
          return res;
        }
      }
    }
    return vector<int>();
  }
};

int main() {
  auto a = SnookerScoring();
  for (int i = 1; i < 3000; i++) {
    auto t = a.scoreN(i, 100, 10);
    cout << i << "\n";
    for (auto& x : t) cout << x << " ";
    cout << "\n\n";
  }
  return 0;
}
