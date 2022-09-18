#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  cout << 'b';
  for (int i = 0; i < k - 1; i++) {
    cout << 'a';
  }
  for (int i = 0; i < n - k; i++) {
    cout << 'z';
  }
}
