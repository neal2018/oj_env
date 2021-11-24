#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  int s, t, x;
  cin >> s >> t >> x;
  if (s > t) s -= 24;
  if (x > t) x -= 24;
  if (s <= x && x < t) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}