#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  int n, k, a;
  cin >> n >> k >> a;
  a--;
  a = (a + k - 1) % n;
  cout << a + 1 << '\n';
}