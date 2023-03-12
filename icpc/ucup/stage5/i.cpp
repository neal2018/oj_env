#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MOD = 998244353;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  if (n <= 2) {
    cout << "1\n";
  } else {
    cout << (n * 2) % MOD << "\n";
  }
}

