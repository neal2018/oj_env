#include <bits/stdc++.h> 
using namespace std;

#define FOR(x,n) for(int x=0;x<n;x++)
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define all(v) v.begin(), v.end()
using vi = vector<int>;
using ll = long long;
using ld = long double;
using pii = pair<int,int>;
const char nl = '\n';

int ans = 0;
char curGrid[5][5];
vi a;
int n, m;


void check(int ptr) {
  if(ptr == a.size()) {
    ans++;
    return;
  }
  int length = a[ptr];
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n + 1 - length; j++) {
      bool good = true;
      forn(k, length) {
        if(curGrid[i][j+k] == 'X') good = false;
      }
      if(!good) continue;
      forn(k, length) curGrid[i][j+k] = 'X';
      check(ptr+1);
      forn(k, length) curGrid[i][j+k] = 'O';
    } 
  }
  if(length == 1) return;
  for(int i = 0; i < n + 1 - length; i++) {
    for(int j = 0; j < n; j++) {
      bool good = true;
      forn(k, length) {
        if(curGrid[i+k][j] == 'X') good = false;
      }
      if(!good) continue;
      forn(k, length) curGrid[i+k][j] = 'X';
      check(ptr+1);
      forn(k, length) curGrid[i+k][j] = 'O';
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);

  cin >> n >> m;

  vector<string> grid(n);
  for(string& z : grid) cin >> z;

  a = vi(m);
  int one = 0;
  int sum = 0;

  for (int& z : a) {
    cin >> z;
    sum += z;
  }
  sort(a.rbegin(), a.rend());

  int numPossible = 1 << (n*n);

  forn(id, numPossible) {
    if(__builtin_popcount(id) != sum) continue;
    int cur = id;
    forn(i, n*n) {
      if(cur % 2) {
        curGrid[i/n][i%n] = 'O';
      }
      else curGrid[i/n][i%n] = 'X';
      cur /= 2;
    }
    bool bad = false;
    forn(i, n) {
      forn(j, n) {
        if(grid[i][j] == 'X' && curGrid[i][j] == 'O') bad = true;
        if(grid[i][j] == 'O' && curGrid[i][j] == 'X') bad = true;
      }
    }
    if(bad) continue;
    check(0);

  }
  
  cout << ans << nl;

}