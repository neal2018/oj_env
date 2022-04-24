#include <bits/stdc++.h>
using namespace std;

#define FOR(x, n) for (int x = 0; x < n; x++)
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define all(v) v.begin(), v.end()
using vi = vector<int>;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
const char nl = '\n';

int ans = 0;
char curGrid[5][5];
vi a;
int n, m;
// int cnt;
void check(int ptr, int minX, int minY) {
  // cnt++;
  if(ptr != 0 && a[ptr] != a[ptr-1]) {
    minX = 0;
    minY = 0;
  }
  if (ptr == a.size()) {
    ans++;
    return;
  }
  int length = a[ptr];
  for (int i = minX; i < n; i++) {
    if(i != minX) minY = 0;
    for(int j = minY; j < n; j++) {
      if(j < n + 1 - length) {
        bool good = true;
        forn(k, length) {
          if (curGrid[i][j + k] == 'X') good = false;
        }
        if (good) {
          forn(k, length) curGrid[i][j + k] = 'X';
          check(ptr + 1,i,j);
          forn(k, length) curGrid[i][j + k] = 'O';
        }
      }
      if(i < n + 1 - length && length > 1) {
        bool good = true;
        forn(k, length) {
          if (curGrid[i + k][j] == 'X') good = false;
        }
        if (!good) continue;
        forn(k, length) curGrid[i + k][j] = 'X';
        check(ptr + 1, i,j );
        forn(k, length) curGrid[i + k][j] = 'O';
      }
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);

  cin >> n >> m;

  vector<string> grid(n);
  for (string& z : grid) cin >> z;

  a = vi(m);
  int one = 0;
  int sum = 0;

  for (int& z : a) {
    cin >> z;
    sum += z;
  }
  sort(a.rbegin(), a.rend());

  int numPossible = 1 << (n * n);

  forn(id, numPossible) {
    if (__builtin_popcount(id) != sum) continue;
    int cur = id;
    forn(i, n * n) {
      if (cur % 2) {
        curGrid[i / n][i % n] = 'O';
      } else
        curGrid[i / n][i % n] = 'X';
      cur /= 2;
    }
    bool bad = false;
    for (int i = 0; i < n && !bad; i++) {
      for (int j = 0; j < n && !bad; j++) {
        if (grid[i][j] == 'X' && curGrid[i][j] == 'O') {
          bad = true;
        }
        if (grid[i][j] == 'O' && curGrid[i][j] == 'X') {
          bad = true;
        }
      }
    }
    if (bad) continue;
    check(0, 0, 0);
  }
  // cout<<cnt<<"\n";
  vi cnt(6, 0);
  for(int z : a) cnt[z]++;
  for(int z : cnt) {
    if(z==2) ans *= 2;
    if(z==3) ans *= 6;
    if(z==4) ans *= 24;
    if(z==5) ans *= 120;
  } 
  cout << ans << nl;
}