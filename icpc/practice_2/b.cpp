#include <bits/stdc++.h>
using ll = long long;
using namespace std;
using vi = vector<int>;


int computeS(vi& results) {
  int n = results.size()/2;
  int curDiff = 0;
  int oneLeft = n;
  int twoLeft = n;
  int a = 0;
  int b = 0;
  int s = 0;

  for(int i = 0; i < 2*n; i++) {
    if(i % 2) {
      curDiff -= results[i];
      b += results[i];
      twoLeft--;
    }
    else {
      curDiff += results[i];
      a += results[i];
      oneLeft--;
    }

    int maxDiff = curDiff + oneLeft;
    int minDiff = curDiff - twoLeft;
    
    if((maxDiff < 0 && minDiff < 0) || (maxDiff > 0 && minDiff > 0)) {
      return i+1;
      break;
    }
    if(i == 2*n-1) {
      return i+1;
    }
  }
  return -1;
}

void solve() {
  int n;
  cin >> n;

  vi results(2*n,0);

  for(int i = 0; i < 2*n; i++) {
    char c;
    cin >> c;
    if(c == 'E') results[i] = 1;
  } 

  int curDiff = 0;
  int oneLeft = n;
  int twoLeft = n;
  int a = 0;
  int b = 0;
  int s = 0;

  for(int i = 0; i < 2*n; i++) {
    if(i % 2) {
      curDiff -= results[i];
      b += results[i];
      twoLeft--;
    }
    else {
      curDiff += results[i];
      a += results[i];
      oneLeft--;
    }

    int maxDiff = curDiff + oneLeft;
    int minDiff = curDiff - twoLeft;
    
    if((maxDiff < 0 && minDiff < 0) || (maxDiff > 0 && minDiff > 0)) {
      s = i+1;
      break;
    }
    if(i == 2*n-1) {
      s = i+1;
    }
  }

  int c = 0;
  
  for(int mask = 0; mask < (1 << (2*n)); mask++) {
    vi cur;
    int mm = mask;
    for(int i = 0; i < 2*n; i++) {
      cur.push_back(mm%2);
      mm/=2;
    }

    int aCnt = 0;
    int bCnt = 0;
    for(int i = 0; i < s; i++) {
      if(i%2) bCnt += cur[i];
      else aCnt += cur[i];
    }

    if(aCnt != a || bCnt != b || computeS(cur) != s) continue;

    if(cur == results) continue;

    for(int i = 0; i < s; i++) {
      if(results[i] != cur[i]) {
        c = max(c, i+1);
        break;
      }
    }

  }





  cout << s << ' ' << c << '\n';
}

int main() {

  int t;
  cin >> t;

  while(t--) {
    solve();
  }

}