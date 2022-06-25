#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int ask(int u, int v, int w) {
  assert(u != v), assert(u != w), assert(v != w);
  cout << "? " << u + 1 << " " << v + 1 << " " << w + 1 << endl;
  int res;
  cin >> res;
  if (res == -1) exit(0);
  return res - 1;
}

constexpr int LIMIT = 420;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  int h;
  cin >> h;
  int n = (1 << h) - 1;
  vector<int> cnt(n);
  for ([[maybe_unused]] auto _ : views::iota(0, LIMIT)) {
    set<int> to_ask;
    while (to_ask.size() < 3) {
      int candidate = int(rng() % n);
      if (to_ask.count(candidate) == 0) to_ask.insert(candidate);
    }
    int res = ask(*to_ask.begin(), *++to_ask.begin(), *to_ask.rbegin());
    cnt[res]++;
  }
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int x, int y) { return cnt[x] > cnt[y]; });
  for (auto i : views::iota(0, n)) {
    if (i != order[0] && i != order[1] && i == ask(i, order[0], order[1])) {
      cout << "! " << i + 1 << endl;
      return 0;
    }
  }
}
