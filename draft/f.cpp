#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  int N = 1025;
  for (int l = 1, r; l <= N; l = r + 1) {
    int v = N / l;
    r = N / v;
    cout << "l=" << l << "\tr=" << r << "\tv=" << v << endl;
  }
}