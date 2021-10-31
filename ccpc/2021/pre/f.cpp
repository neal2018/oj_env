#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    ll curr = 0, i = 1;
    while (curr != n) {
      if (curr < n) {
        curr += -i * i + (i + 1) * (i + 1);
        i += 2;
      } else {
        curr += i * i - (i + 1) * (i + 1);
        i += 2;
      }
    }
    cout << i << endl;
  }
}