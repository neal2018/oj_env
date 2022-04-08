#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

pair<ll, ll> teleport(ll node) {
  ll ne, cnt;
  cout << "T " << node + 1 << endl;
  cin >> ne >> cnt;
  return {ne - 1, cnt};
}

pair<ll, ll> walk() {
  ll ne, cnt;
  cout << "W" << endl;
  cin >> ne >> cnt;
  return {ne - 1, cnt};
}

void answer(ll cnt) { cout << "E " << cnt << endl; }

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  int T;
  cin >> T;
  for (int case_num = 1; case_num <= T; case_num++) {
    ll n, k, node, cnt;
    cin >> n >> k >> node >> cnt;
    ll random_cnt = 0;
    ld sum = 0;
    while (k) {
      auto [ne, a] = teleport(rng() % n);
      random_cnt ++;
      k--;
      if (k) {
        k--;
        auto [_, b] = walk();
        sum += ((ld)a * b) / (a + b);
      }
    }
    answer(ll(sum * n / random_cnt));
  }
}
