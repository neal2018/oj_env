#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  int sum = 0;
  vector<int> a{0};
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    sum += x;
    sum %= 360;
    a.push_back(sum);
  }
  sort(a.begin(), a.end());
  int maxi = 0;
  for (int i = 0; i < n - 1; i++) {
    maxi = max(maxi, a[i + 1] - a[i]);
  }
  maxi = max(maxi, (a[0] + 360 - a.back()) % 360);
  cout << maxi << "\n";
}
