#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  if (n >= 42) n++;
  cout << "AGC" << setfill('0') << setw(3) << n << "\n";
}