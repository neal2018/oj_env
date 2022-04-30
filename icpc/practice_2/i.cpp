#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
  ll n, k;
  cin >> n >> k;
  set<ll> pick;
  vector<array<ll, 3>> a(n);
  for (int i = 0; i < n; i++) {
    auto& [aa, b, c] = a[i];
    cin >> aa >> b >> c;
  }
  vector<ll> order(n);
  iota(order.begin(), order.end(), 0ll);
  sort(order.begin(), order.end(), [&](int x, int y) { return get<0>(a[x]) > get<0>(a[y]); });
  for (int i = 0; i < k; i++) {
    pick.insert(order[i]);
  }
  sort(order.begin(), order.end(), [&](int x, int y) { return get<1>(a[x]) > get<1>(a[y]); });
  for (int i = 0; i < k; i++) {
    pick.insert(order[i]);
  }
  sort(order.begin(), order.end(), [&](int x, int y) { return get<2>(a[x]) > get<2>(a[y]); });
  for (int i = 0; i < k; i++) {
    pick.insert(order[i]);
  }
  cout << pick.size() << "\n";
}