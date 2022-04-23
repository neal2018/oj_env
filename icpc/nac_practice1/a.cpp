#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for(int& z : a) cin >> z;
  sort(a.begin(), a.end());

  int ans = 1;
  for(int i = 1 ; i < n; i++) {
    if(a[i] + a[i-1] > x) break;
    ans++;
  }

  cout << ans << '\n';

}