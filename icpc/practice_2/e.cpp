#include <bits/stdc++.h>
using ll = long long;
using namespace std;
using vi = vector<int>;

vi pre(1e6+10, 0);

void preCompute() {
  for(int i = 1; i < 333334; i++) {
    int maxSquareFactor = 1;
    ll cur = i;
    for(int j = 2; j * j <= cur; j++) {
      while(cur % (j*j) == 0) {
        maxSquareFactor *= j;
        cur /= j*j;
      }
    }

    int step = i / maxSquareFactor;
    for(int j = i + step;; j+= step) {
      ll curSum = i + j;
      ll top = j;
      ll bottom = i;
      cur = j * top / bottom;
      curSum += cur;
      if(curSum > 1000000) break;
      pre[curSum]++;
      while(true) {
        cur *= top;
        if(cur % bottom) break;
        cur /= bottom;
        curSum += cur;
        if(curSum > 1000000) break;
        pre[curSum]++;
      }
    }
  }
}

int main() {

  preCompute();

  int n;
  cin >> n;

  for(int i = 0; i < n; i++) {
    int m;
    cin >> m;
    int ans = 1 + (m-1)/2;
    ans += pre[m];
    cout << ans << ' ';

  }
  
}