#include <bits/stdc++.h>
using namespace std;

#define FOR(x, n) for (int x = 0; x < n; x++)
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define all(v) v.begin(), v.end()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
const char nl = '\n';

int main() {
  ll n, m, d;
  cin >> n >> m >> d;
  vector<pii> graph[n + 10];

  forn(i, m) {
    ll u, v, w;
    cin >> u >> v >> w;
    graph[u].push_back({v, w});
  }

  set<ll> distances;

  forn(i, d) {
    ll z;
    cin >> z;
    if (z == 0) {
      continue;
    }
    distances.insert(z);
  }

  set<pair<ll, ll>> q;
  vector<bool> visited(n + 10, false);

  q.insert({0, 1});
  vector<ll> minDistance(n + 10, 1e18);
  minDistance[1] = 0;
  vi bestPicks(n + 10, 0);
  vector<bool> multiple(n + 10, false);
  vi br(n + 10, -1);

  while (!q.empty()) {
    pair<ll, ll> cur = *q.begin();
    q.erase(cur);
    if (visited[cur.second]) continue;
    visited[cur.second] = true;

    int curPicks = bestPicks[cur.second];
    bool curMulti = multiple[cur.second];

    for (auto z : graph[cur.second]) {
      if (visited[z.first]) continue;
      ll newCost = z.second + cur.first;
      int newPicks = curPicks;
      if (distances.count(newCost)) newPicks++;
      if (newCost < minDistance[z.first]) {
        bestPicks[z.first] = newPicks;
        minDistance[z.first] = newCost;
        multiple[z.first] = curMulti;
        q.insert({newCost, z.first});
        br[z.first] = cur.second;
      } else if (newCost == minDistance[z.first]) {
        if (newPicks > bestPicks[z.first]) {
          bestPicks[z.first] = newPicks;
          multiple[z.first] = curMulti;
          br[z.first] = cur.second;
        } else if (newPicks == bestPicks[z.first]) {
          multiple[z.first] = true;
        }
      }
    }
  }

  if (bestPicks[n] != distances.size()) {
    cout << 0 << nl;
    return 0;
  }
  if (multiple[n]) {
    cout << 1 << nl;
    return 0;
  }

  vi ans;
  int cur = n;
  while (cur > 0) {
    ans.push_back(cur);
    cur = br[cur];
  }
  reverse(all(ans));
  cout << ans.size() << nl;
  for (int z : ans) cout << z << nl;
}