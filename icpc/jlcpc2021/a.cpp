#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int a[2] = {};
  int n;
  cin >> n;
  for (int i = 0, x; i < n; i++) {
    cin >> x, a[x % 2]++;
  }
  if (abs(a[0] - a[1]) <= 1) {
    cout << "Good\n";
  } else {
    cout << "Not Good\n";
  }
}
