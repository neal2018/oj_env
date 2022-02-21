#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;
  cout << n / 10 - (n < 0 && n % 10) << "\n";
}
