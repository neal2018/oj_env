#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  int pre = -1;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x > pre)
      pre = x;
    else
      break;
  }
  cout << pre << "\n";
}
