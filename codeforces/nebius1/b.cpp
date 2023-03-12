#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, k, d, w;
    cin >> n >> k >> d >> w;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    set<array<ll, 3>> events;
    for (int i = 0; i < n; i++) {
      auto& x = a[i];
      events.insert({x, 1, i});
      events.insert({x + w, -1, i});
    }
    vector<int> good(n);
    vector<ll> vac;
    int id = 0;
    int res = 0;
    set<ll> inside;
    for (auto it = events.begin(); it != events.end(); it++) {
      auto [time, type, number] = *it;
      if (type == 2) {
        vac[number] = 0;
      } else {
        if (good[number]) {
          inside.erase(number);
          continue;
        }
        if (type == -1) {
          while (id < vac.size() && vac[id] == 0) id++;
          if (id == vac.size()) {
            events.insert({time + d, 2, res});
            vac.push_back(k), res++;
            inside.erase(number);
          }
          good[number] = 1, vac[id]--;
          while (vac[id] > 0 && inside.size()) {
            auto people = *inside.begin();
            good[people] = 1, vac[id]--;
            inside.erase(inside.begin());
          }
        } else {
          if (id < vac.size() && vac[id] == 0) id++;
          if (id < vac.size()) {
            good[number] = 1, vac[id]--;
          } else {
            inside.insert(number);
          }
        }
      }
    }
    cout << res << "\n";
  }
}
