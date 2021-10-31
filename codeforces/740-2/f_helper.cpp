#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  vector<ll> a = {5, 4, 3, 2, 1};
  auto print = [&]() {
    for (auto& x : a) cout << x << " ";
    cout << endl;
  };
  for (int i = 1; i < a.size(); i++) {
    if (a[i] < a[i - 1]) {
      for (int j = 0; j < i; j++) {
        if (a[i] < a[j]) {
          ll store = a[i];
          for (int k = i; k > j; k--) {
            a[k] = a[k - 1];
          }
          a[j] = store;
          break;
        }
      }
    }
    print();
  }
}