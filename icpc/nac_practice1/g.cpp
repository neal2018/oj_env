#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';

int main() {

  int n;
  cin >> n;

  string s;
  cin >> s;
  s += s;

  vector<int> pa(2*n + 1), pb(2*n + 1), pc(2*n +1);
  int ta = 0, tb = 0, tc = 0;
  for(int i = 0; i < 2*n; i++) {
    pa[i + 1] = pa[i]; pb[i + 1] = pb[i]; pc[i + 1] = pc[i];
    if(s[i] == 'A') {
      if(i < n) ta++;
      pa[i + 1]++;
    }
    else if(s[i] == 'B') {
      if(i < n) tb++;
      pb[i + 1]++;
    }
    else {
      if(i < n) tc++;
      pc[i + 1]++;
    }
  }

  int best = 0;
  for(int i = 0; i < n; i++) {
    int cur = i, cand = 0;
    cand += pa[cur + ta] - pa[cur];
    cur += ta;
    cand += pb[cur + tb] - pb[cur];
    cur += tb;
    cand += pc[cur + tc] - pc[cur];
    best = max(best, cand);

    cur = i, cand = 0;
    cand += pa[cur + ta] - pa[cur];
    cur += ta;
    cand += pc[cur + tc] - pc[cur];
    cur += tc;
    cand += pb[cur + tb] - pb[cur];
    best = max(best, cand);
  }
  cout << n - best << '\n';
}