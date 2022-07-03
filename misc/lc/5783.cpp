#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 1000000

ll n, m, a[MAX], t[MAX << 2], lazy[MAX << 2];

void push_up(ll p) { t[p] = t[p * 2] + t[p * 2 + 1]; }

void build(ll p, ll l, ll r) {
  lazy[p] = 0;
  if (l == r) {
    t[p] = a[l];
    return;
  }
  ll mid = (l + r) >> 1;
  build(p * 2, l, mid);
  build(p * 2 + 1, mid + 1, r);
  push_up(p);
}

void f(ll p, ll l, ll r, ll k) {
  lazy[p] = lazy[p] + k;
  t[p] = t[p] + k * (r - l + 1);
}

void push_down(ll p, ll l, ll r) {
  ll mid = (l + r) / 2;
  f(p * 2, l, mid, lazy[p]);
  f(p * 2 + 1, mid + 1, r, lazy[p]);
  lazy[p] = 0;
}

void update(ll nl, ll nr, ll l, ll r, ll p, ll k) {
  if (nl <= l && r <= nr) {
    t[p] += k * (r - l + 1);
    lazy[p] += k;
    return;
  }
  push_down(p, l, r);
  ll mid = (l + r) >> 1;
  if (nl <= mid) update(nl, nr, l, mid, p * 2, k);
  if (nr > mid) update(nl, nr, mid + 1, r, p * 2 + 1, k);
  push_up(p);
}

ll query(ll q_x, ll q_y, ll l, ll r, ll p) {
  ll res = 0;
  if (q_x <= l && r <= q_y) return t[p];
  ll mid = (l + r) / 2;
  push_down(p, l, r);
  if (q_x <= mid) res += query(q_x, q_y, l, mid, p * 2);
  if (q_y > mid) res += query(q_x, q_y, mid + 1, r, p * 2 + 1);
  return res;
}

void scan() {
  cin >> n >> m;
  for (ll i = 1; i <= n; i++) scanf("%lld", &a[i]);
}

int main() {
  ll a1, b, c, d, e, f;
  scan();
  build(1, 1, n);
  while (m--) {
    scanf("%lld", &a1);
    if (a1 == 1) {
      scanf("%lld%lld%lld", &b, &c, &d);
      update(b, c, 1, n, 1, d);
    } else {
      scanf("%lld%lld", &e, &f);
      printf("%lld\n", query(e, f, 1, n, 1));
    }
  }
  return 0;
}