#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void f(int) { cout << "f(int)\n"; }
void f(int &) { cout << "f(int&)\n"; }
void f(volatile int) {}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int a = 10;
  // f(a);
}
