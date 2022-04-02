#include <bits/stdc++.h>
using namespace std;

#define FOR(x, n) for (int x = 0; x < n; x++)
#define PI 3.14159265358979323846264338327950288
typedef long long ll;
typedef pair<int, int> ii;

int pow6[8];
const int TOT = 1679616;
int dist[TOT], from[TOT];
int exist[6][6];
pair<ii, ii> transition[TOT];

int encode(ii p1, ii p2, ii p3, ii p4) {
  return p1.first * pow6[7] + p1.second * pow6[6] + p2.first * pow6[5] + p2.second * pow6[4] +
         p3.first * pow6[3] + p3.second * pow6[2] + p4.first * pow6[1] + p4.second * pow6[0];
}

array<ii, 4> decode(int state) {
  ii p1, p2, p3, p4;
  p4.second = state % 6;
  state /= 6;
  p4.first = state % 6;
  state /= 6;

  p3.second = state % 6;
  state /= 6;
  p3.first = state % 6;
  state /= 6;

  p2.second = state % 6;
  state /= 6;
  p2.first = state % 6;
  state /= 6;

  p1.second = state % 6;
  state /= 6;
  p1.first = state % 6;
  return {{p1, p2, p3, p4}};
}

array<ii, 4> getmoves(ii p) {
  // RIGHT
  int ridx = p.second;
  for (int i = p.second + 1; i < 6; i++)
    if (!exist[p.first][i])
      ridx = i;
    else
      break;

  // LEFT
  int lidx = p.second;
  for (int i = p.second - 1; i >= 0; i--)
    if (!exist[p.first][i])
      lidx = i;
    else
      break;

  // DOWN
  int didx = p.first;
  for (int i = p.first + 1; i < 6; i++)
    if (!exist[i][p.second])
      didx = i;
    else
      break;

  // UP
  int uidx = p.first;
  for (int i = p.first - 1; i >= 0; i--)
    if (!exist[i][p.second])
      uidx = i;
    else
      break;

  return {{{p.first, ridx}, {p.first, lidx}, {didx, p.second}, {uidx, p.second}}};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

  ii s1, s2, s3, s4;
  ii e1, e2, e3, e4;
  cin >> s1.first >> s1.second >> s2.first >> s2.second >> s3.first >> s3.second >> s4.first >>
      s4.second;
  cin >> e1.first >> e1.second >> e2.first >> e2.second >> e3.first >> e3.second >> e4.first >>
      e4.second;

  pow6[0] = 1;
  for (int i = 1; i < 8; i++) pow6[i] = 6 * pow6[i - 1];

  int start = encode(s1, s2, s3, s4);
  int end = encode(e1, e2, e3, e4);

  memset(dist, -1, sizeof dist);
  memset(exist, 0, sizeof exist);
  dist[start] = 0;
  deque<int> q;
  q.push_back(start);
  while (dist[end] == -1) {
    assert(!q.empty());
    int cur = q.front();
    q.pop_front();
    auto pts = decode(cur);
    auto p1 = pts[0], p2 = pts[1], p3 = pts[2], p4 = pts[3];
    int curdist = dist[cur];
    exist[p1.first][p1.second]++;
    exist[p2.first][p2.second]++;
    exist[p3.first][p3.second]++;
    exist[p4.first][p4.second]++;

    ii pv = p1;
    for (ii t : getmoves(p1)) {
      p1 = t;
      int nxt = encode(p1, p2, p3, p4);
      if (dist[nxt] == -1) {
        dist[nxt] = 1 + curdist;
        from[nxt] = cur;
        transition[nxt] = {pv, t};
        q.push_back(nxt);
      }
    }
    p1 = pv;

    pv = p2;
    for (ii t : getmoves(p2)) {
      p2 = t;
      int nxt = encode(p1, p2, p3, p4);
      if (dist[nxt] == -1) {
        dist[nxt] = 1 + curdist;
        from[nxt] = cur;
        transition[nxt] = {pv, t};
        q.push_back(nxt);
      }
    }
    p2 = pv;

    pv = p3;
    for (ii t : getmoves(p3)) {
      p3 = t;
      int nxt = encode(p1, p2, p3, p4);
      if (dist[nxt] == -1) {
        dist[nxt] = 1 + curdist;
        from[nxt] = cur;
        transition[nxt] = {pv, t};
        q.push_back(nxt);
      }
    }
    p3 = pv;

    pv = p4;
    for (ii t : getmoves(p4)) {
      p4 = t;
      int nxt = encode(p1, p2, p3, p4);
      if (dist[nxt] == -1) {
        dist[nxt] = 1 + curdist;
        from[nxt] = cur;
        transition[nxt] = {pv, t};
        q.push_back(nxt);
      }
    }
    p4 = pv;

    exist[p1.first][p1.second]--;
    exist[p2.first][p2.second]--;
    exist[p3.first][p3.second]--;
    exist[p4.first][p4.second]--;
  }

  cout << dist[end] << '\n';
  vector<int> order;
  while (end != start) {
    order.push_back(end);
    end = from[end];
  }
  int tt = encode({2, 2}, {1, 1}, {2, 1}, {1, 2});
  cout << dist[tt] << "\n";
  reverse(order.begin(), order.end());
  for (int v : order) {
    auto p1 = transition[v].first;
    auto p2 = transition[v].second;
    cout << p1.first << ' ' << p1.second << ' ' << p2.first << ' ' << p2.second << '\n';
  }
}
