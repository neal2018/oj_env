#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

const double PI = acos(-1);

class SingleOrDouble {
public:
  double probAlice(int N, int D, int A, int B) {
    vector<double> res;
    vector<vector<int>> dp(N + 1, vector<int>(D * N + 1));
    for (int i = 1; i <= D; i++) {
      dp[1][i] = 1;
    }
    for (int i = 2; i <= N; i++) {
      for (int j = i; j <= D * i; j++) {  
        for (int k = 1; k <= D; k++) {
          if (j - k < 1) break; 
          dp[i][j] += dp[i - 1][j - k];
        }
      }
    }
    ll sum = 1;
    for (int i = 0; i < N; i++) sum *= D;
    for (int i = N; i <= D * N; i++) {
      res.push_back(dp[N][i] * 1.0 / sum);
    }
    double pa = res[A-N], pb = res[B-N];
    double pp = (pa + pa * pb) / (pa + pa * pb + pb * pb);
    return pp;
  }
};
