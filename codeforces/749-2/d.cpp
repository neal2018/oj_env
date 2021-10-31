#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094 1:53
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, x;
  cin >> n;
  vector<int> after(n);
  // after[i]=j : the nex number of p[i] is p[j]
  // starting from 0
  int indexone = 0;
  int indexn = 0;
  for (int i = n - 1; i >= 0; i--) {
    cout << "? ";
    for (int j = 0; j < n; j++) {
      cout << (j == i ? 1 : 2) << " ";
    }
    cout << endl;
    cin >> x;
    x--;
    if (x == -1) {
      indexone = i;
    } else if (x != i) {
      after[x] = i;
    }
    cout << "? ";
    for (int j = 0; j < n; j++) {
      cout << (j == i ? 2 : 1) << " ";
    }
    cout << endl;
    cin >> x;
    x--;
    if (x == -1) {
      indexn = i;
    } else if (x != i) {
      after[i] = x;
    }
  }
  vector<int> ans(n);
  int p = indexone;
  ans[p] = 1;
  for (int i = 0; i < n - 1; i++) {
    ans[after[p]] = ans[p] + 1;
    p = after[p];
  }
  cout << "! ";
  for (int j = 0; j < n; j++) {
    cout << ans[j] << " ";
  }
  cout << endl;
}