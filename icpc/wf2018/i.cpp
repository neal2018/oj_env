#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

struct Node {
  bool left = false, right = false, up_left = false, up_right = false, down_left = false,
       down_right = false;
};

struct SegTree {
  ll n;
  vector<int> t;
  SegTree(ll _n) : n(_n), t(2 * n) {}
  void modify(ll p, int v) {
    t[p += n] += v;
    for (p /= 2; p; p /= 2) t[p] = t[2 * p] + t[2 * p + 1];
  }
  int query(ll l, ll r) {
    int res = 0;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) res += t[l++];
      if (r & 1) res += t[--r];
    }
    return res;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int r, c;
  cin >> r >> c;
  c = (c + 1) / 2;
  string s;
  getline(cin, s);
  vector nodes(r, vector<Node>(c));
  for (int i = 0; i < 2 * r - 1; i++) {
    getline(cin, s);
    ll cnt = 0, sz = s.size();
    if (i % 2 == 0) {
      bool is_link = false;
      for (int j = 0; j < sz; j++) {
        if (s[j] == '-') {
          is_link = true;
        } else if (s[j] == 'x') {
          if (cnt > 0 && is_link) {
            nodes[i / 2][cnt - 1].right = true;
            nodes[i / 2][cnt].left = true;
          }
          cnt++, is_link = false;
        }
      }
    } else {
      if (i % 4 == 1) {
        for (int j = 1; j < sz; j += 2) {
          if (s[j] == '\\') {
            nodes[(i + 1) / 2][j / 4].up_left = true;
            nodes[i / 2][j / 4].down_right = true;
          } else if (s[j] == '/') {
            nodes[(i + 1) / 2][j / 4].up_right = true;
            nodes[i / 2][j / 4 + 1].down_left = true;
          }
        }
      } else {
        for (int j = 1; j < sz; j += 2) {
          if (s[j] == '/') {
            nodes[(i + 1) / 2][j / 4].up_right = true;
            nodes[i / 2][j / 4].down_left = true;
          } else if (s[j] == '\\') {
            nodes[(i + 1) / 2][j / 4 + 1].up_left = true;
            nodes[i / 2][j / 4].down_right = true;
          }
        }
      }
    }
  }
  vector up_left(r, vector<ll>(c)), up_right(r, vector<ll>(c)), down_left(r, vector<ll>(c)),
      down_right(r, vector<ll>(c)), left(r, vector<ll>(c));
  for (int i = 0; i < r; i++) {
    for (int j = 1; j < c; j++) {
      if (nodes[i][j].left) {
        left[i][j] = 1 + left[i][j - 1];
      }
    }
  }
  for (int i = 1; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (nodes[i][j].up_left) {
        up_left[i][j] = 1 + up_left[i - 1][j - (i % 2 == 0)];
      }
      if (nodes[i][j].up_right) {
        up_right[i][j] = 1 + up_right[i - 1][j + (i % 2)];
      }
    }
  }
  for (int i = r - 2; i >= 0; i--) {
    for (int j = 0; j < c; j++) {
      if (nodes[i][j].down_left) {
        down_left[i][j] = 1 + down_left[i + 1][j - (i % 2 == 0)];
      }
      if (nodes[i][j].down_right) {
        down_right[i][j] = 1 + down_right[i + 1][j + (i % 2)];
      }
    }
  }
  ll res = 0;
  constexpr ll HASH = 1000000;
  for (int i = 0; i < r; i++) {
    vector<array<ll, 2>> qs;
    qs.reserve(2 * c);
    for (int j = 0; j < c; j++) {
      if (up_right[i][j]) qs.push_back({(up_right[i][j] + j) * HASH + 1, j});
      ll qq = min(left[i][j], up_left[i][j]);
      if (qq) qs.push_back({j * HASH, j});
    }
    sort(qs.begin(), qs.end(), greater<>());
    SegTree seg(c);
    for (auto& [val, pos] : qs) {
      if (val % HASH == 1) {
        seg.modify(pos, 1);
      } else {
        ll qq = min(left[i][pos], up_left[i][pos]);
        res += seg.query(pos - qq, pos);
      }
    }
  }
  for (int i = 0; i < r; i++) {
    vector<array<ll, 2>> qs;
    qs.reserve(2 * c);
    for (int j = 0; j < c; j++) {
      if (down_right[i][j]) qs.push_back({(down_right[i][j] + j) * HASH + 1, j});
      ll qq = min(left[i][j], down_left[i][j]);
      if (qq) qs.push_back({j * HASH, j});
    }
    sort(qs.begin(), qs.end(), greater<>());
    SegTree seg(c);
    for (auto& [val, pos] : qs) {
      if (val % HASH == 1) {
        seg.modify(pos, 1);
      } else {
        ll qq = min(left[i][pos], down_left[i][pos]);
        res += seg.query(pos - qq, pos);
      }
    }
  }
  cout << res << "\n";
}
