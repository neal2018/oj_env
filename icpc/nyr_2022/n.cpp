#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
const double PI = acos(-1);
const ll mod7 = 1e9 + 7;
const ll mod9 = 998244353;
const ll INF = 2 * 1024 * 1024 * 1023;
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define all(v) v.begin(), v.end()

// #pragma GCC optimize("O2")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

ll l, r, k, n, m, p, q, u, v, w, x, y;

//////////////////  LIBRARY CODE /////////////////////

//////////////////////////////////////////////////////

vector<vi> grid;
vector<vi> leftNeighbor;
vector<vi> upNeighbor;
vector<vector<bool>> takenRow;
vector<vector<bool>> takenColumn;

void dfs(int cur) {
  if (cur == n * n) {
    forn(i, n) {
      forn(j, n) { cout << grid[i][j] << ' '; }
      cout << '\n';
    }
    exit(0);
  }

  int x = cur / n;
  int y = cur % n;

  if (grid[x][y] != -1) {
    dfs(cur + 1);
    return;
  }

  for (int curNum = 1; curNum <= n; curNum++) {
    if (takenRow[x][curNum]) continue;
    if (takenColumn[y][curNum]) continue;
    if (y != 0) {
      int prevNum = grid[x][y - 1];
      if (abs(prevNum - curNum) <= 1) {
        if (leftNeighbor[x][y] == 0) continue;
      } else {
        if (leftNeighbor[x][y] == 1) continue;
      }
    }
    if (x != 0) {
      int prevNum = grid[x - 1][y];
      if (abs(prevNum - curNum) <= 1) {
        if (upNeighbor[x][y] == 0) continue;
      } else {
        if (upNeighbor[x][y] == 1) continue;
      }
    }

    takenRow[x][curNum] = true;
    takenColumn[y][curNum] = true;
    grid[x][y] = curNum;
    dfs(cur + 1);
    takenRow[x][curNum] = false;
    takenColumn[y][curNum] = false;
    grid[x][y] = -1;
  }
}

bool multiTest = false;
void solve(int tt) {
  cin >> n >> k;

  grid = vector<vi>(n, vi(n, -1));
  leftNeighbor = vector<vi>(n, vi(n, 0));
  upNeighbor = vector<vi>(n, vi(n, 0));
  takenRow = vector<vector<bool>>(n, vector<bool>(n + 1, 0));
  takenColumn = vector<vector<bool>>(n, vector<bool>(n + 1, 0));

  forn(i, n) {
    string s;
    cin >> s;
    forn(j, n - 1) {
      if (s[j] == '0') {
        leftNeighbor[i][j + 1] = 0;
      } else
        leftNeighbor[i][j + 1] = 1;
    }
    if (i == n - 1) continue;
    cin >> s;
    forn(j, n) {
      if (s[j] == '0') {
        upNeighbor[i + 1][j] = 0;
      } else
        upNeighbor[i + 1][j] = 1;
    }
  }

  forn(i, k) {
    cin >> u >> v >> w;
    u--;
    v--;

    grid[u][v] = w;
    takenRow[u][w] = true;
    takenColumn[v][w] = true;
  }

  dfs(0);

  cout << "oops!" << '\n';
  exit(1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef yangster
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t = 1;
  if (multiTest) cin >> t;
  for (int ii = 0; ii < t; ii++) {
    solve(ii + 1);
  }
}
