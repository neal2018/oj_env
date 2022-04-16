#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

class SkyscraperReconstruction {
public:
  vector<int> reconstruct(string visibility) {
    ll n = visibility.size();
    vector<int> res(n);
    ll maxi = n;
    for (int i = n - 1; i >= 0; i--) {
      if (visibility[i] == 'O') {
        res[i] = maxi--;
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      if (visibility[i] == 'X') {
        res[i] = maxi--;
      }
    }
    return res;
  }
};
