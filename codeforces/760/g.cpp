#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

struct Node {
  ll prev = -1, next = -1, cnt = 0, sum = 0, val = 0;
};

int main() {
  ll n, m, q, cur = 0;
  cin >> n >> m >> q;
  ll sz = n + m;
  vector<ll> res(q);
  vector<pair<ll, ll>> qs(q), a(sz);
  for (int i = 0; i < n; i++) cin >> a[i].first, a[i].second = 1;
  for (int i = 0; i < m; i++) cin >> a[i + n].first, a[i + n].second = 0;
  for (int i = 0; i < q; i++) cin >> qs[i].first, qs[i].second = i;
  sort(a.begin(), a.end());
  vector<ll> pre(sz + 1);
  for (int i = 0; i < sz; i++) pre[i + 1] = pre[i] + a[i].first;
  sort(qs.begin(), qs.end());
  vector<Node> lst(sz);
  for (int i = 0; i < sz; i++) {
    if (i > 0) lst[i].prev = i - 1;
    if (i < sz - 1) lst[i].next = i + 1;
    lst[i].val = a[i].first;
    if (a[i].second) {
      lst[i].cnt = 1, lst[i].sum = lst[i].val;
      cur += lst[i].sum;
    }
  }
  vector<pair<ll, ll>> edges(sz - 1);  // val, from
  for (int i = 0; i < sz - 1; i++) {
    edges[i] = {lst[i + 1].val - lst[i].val, i};
  }
  sort(edges.begin(), edges.end());
  ll e = 0;
  for (auto& [k, id] : qs) {
    while (e < sz - 1 && edges[e].first <= k) {
      // link from and from->next
      ll i = edges[e].second, ne = lst[i].next, prev = lst[i].prev;
      cur -= lst[i].sum + lst[ne].sum;
      lst[ne].cnt += lst[i].cnt;
      lst[ne].sum = pre[ne + 1] - pre[lst[i].next + 1 - lst[ne].cnt];
      cur += lst[ne].sum;
      if (prev != -1) lst[prev].next = ne;
      lst[ne].prev = prev;
      e++;
    }
    res[id] = cur;
  }
  for (auto& x : res) cout << x << "\n";
}