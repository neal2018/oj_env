#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll T, n, s;
  cin >> T;
  while (T--) {
    cin >> n >> s;
    n = n - (n - 1) / 2;
    int a = s / n, b = s % n;
    cout << a << '\n';
  }
}