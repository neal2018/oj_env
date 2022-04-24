#include <bits/stdc++.h> 
using namespace std;

#define FOR(x,n) for(int x=0;x<n;x++)
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define all(v) v.begin(), v.end()
using ll = long long;
using ld = long double;
using pii = pair<int,int>;
const char nl = '\n';

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);

  int n,m;
  cin >> n >> m;

  vector<string> grid(n);
  for(string& z : grid) cin >> z;

  vector<int> a(m);

  for (int& z : a) {
    cin >> z;
  }

  int numPossible = 1;

  for(int i = 0; i < m; i++) numPossible *= 2 * n * n;

  int ans = 0;

  for(int id = 0; id < numPossible; id++) {
    int curID = id;
    vector<int> ids(m, 0);
    forn(j, m) {
      ids[j] = curID % (2 * n * n);
      curID /= (2 * n * n);
    }

    char build[n][n];
    memset(build, '.', sizeof(build));
    bool bad = false;
    forn(j, m) {
      if(bad) break;
      int cur = ids[j];
      bool vert = false;
      if(cur >= n * n) {
        cur -= n*n;
        vert = true;
      }
      int startx = cur / n;
      int starty = cur % n;

      if(vert) {
        forn(k, a[j]) {
          if(startx + k >= n) {
            bad = true;
            break;
          }
          if(build[startx+k][starty] == 'x') {
            bad = true;
            break;
          }
          build[startx+k][starty] = 'x';
        }
      }
      else {
        forn(k, a[j]) {
          if(starty + k >= n) {
            bad = true;
            break;
          }
          if(build[startx][starty + k] == 'x') {
            bad = true;
            break;
          }
          build[startx][starty+k] = 'x';
        }
      }

    }
    if(bad) continue;

    bad = false;
    forn(i, n) {
      forn(j, n) {
        if(grid[i][j] == 'O' && build[i][j] == 'x') bad = true;
        if(grid[i][j] == 'X' && build[i][j] == '.') bad = true;
      }
    }
    if(!bad) ans ++;

  }

  cout << ans << nl;

  

}