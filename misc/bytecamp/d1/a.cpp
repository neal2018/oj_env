#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 30010;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  string s, t;
  cin >> n >> s >> t;
  deque<int> take(2 * n + 1);
  int end = 0;
  for (int cur = n, i = 0; i < n; i++) {
    if (t[i] == 'R') {
      cur++;
    } else if (t[i] == 'L') {
      cur--;
    } else {
      take[cur]++;
    }
    end = cur;
  }
  auto check = [&](string& t) {
    deque<int> take(2 * n + 1);
    for (int cur = n, i = 0; i < n; i++) {
      if (t[i] == 'R') {
        cur++;
      } else if (t[i] == 'L') {
        cur--;
      } else {
        take[cur]++;
      }
      end = cur;
    }
    int res = 0;
    for (int i = 0; i < 2 * n + 1; i++) {
      res += (s[i] == '1') && (take[i] > 0);
    }
    return res;
  };
  auto bf = [&](string t) {
    int res = check(t);
    for (int i = 0; i < n; i++) {
      t = t.substr(1, n - 1) + t[0];
      res = max(res, check(t));
    }
    return res;
  };
  bitset<3 * N> s2;
  bitset<3 * N> t2;
  for (int i = 0; i < 2 * n + 1; i++) {
    s2[i] = (s[i] == '1');
    t2[i] = (take[i] > 0);
  }
  ll res = (s2 & t2).count();
  int start = n;
  auto update = [&](int i, int v) {
    take[i] += v;
    t2[i] = take[i] > 0;
  };
  for (int i = 0; i < n; i++) {
    if (t[i] == 'T') {
      update(start, -1);
      update(end, 1);
    } else if (t[i] == 'L') {
      t2 <<= 1;
      take.pop_back(), take.push_front(0);
    } else {
      t2 >>= 1;
      take.pop_front(), take.push_back(0);
    }
    ll cur = (s2 & t2).count();
    res = max(res, cur);
  }
  // auto bf_t = bf(t);
  // assert(res == bf_t);
  cout << res << "\n";
}
