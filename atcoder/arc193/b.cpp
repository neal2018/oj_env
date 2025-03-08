#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 998244353;

// Adds b to a modulo MOD
void add(ll &a, ll b) { a = (a + b) % MOD; }

// Computes the set A' for {i,i+1} given A (mask), d_i, and S[i]
int compute_A_prime(int mask, int di, char s) {
  int A_prime = 0;
  if (s == '0') {
    if (mask & 1) {  // ← in A
      int c = 0;
      if (di - c == 0) A_prime |= 2;  // → for {i,i+1}
      if (di - c == 1) A_prime |= 1;  // ← for {i,i+1}
    }
    if (mask & 2) {  // → in A
      int c = 1;
      if (di - c == 0) A_prime |= 2;
      if (di - c == 1) A_prime |= 1;
    }
  } else {           // s == '1'
    if (mask & 1) {  // ← in A
      for (int b = 0; b <= 1; b++) {
        int c = b;
        if (di - c == 0) A_prime |= 2;
        if (di - c == 1) A_prime |= 1;
      }
    }
    if (mask & 2) {  // → in A
      for (int b = 0; b <= 1; b++) {
        int c = 1 + b;
        if (di - c == 0) A_prime |= 2;
        if (di - c == 1) A_prime |= 1;
      }
    }
  }
  return A_prime;
}

int main() {
  int N;
  string S;
  cin >> N >> S;

  ll result = 0;

  // Run DP for each of the three cases
  for (int case_ = 0; case_ < 3; case_++) {
    vector<ll> prev(4, 0);
    // Initialize dp[0][A]
    if (case_ == 0)
      prev[1] = 1;  // {←}
    else if (case_ == 1)
      prev[2] = 1;  // {→}
    else
      prev[3] = 1;  // {←, →}

    // DP from i=0 to N-1
    for (int i = 0; i < N; i++) {
      vector<ll> curr(4, 0);
      for (int mask = 0; mask < 4; mask++) {
        if (prev[mask] == 0) continue;
        for (int di = 0; di <= 3; di++) {
          int A_prime = compute_A_prime(mask, di, S[i]);
          if (A_prime != 0) {  // If A' is non-empty
            add(curr[A_prime], prev[mask]);
          }
        }
      }
      prev = curr;
    }
    // Add dp[N][A] for this case
    if (case_ == 0)
      add(result, prev[1]);  // {←}
    else if (case_ == 1)
      add(result, prev[2]);  // {→}
    else
      add(result, prev[3]);  // {←, →}
  }

  // Subtract 2 for the all-1 sequence overcount
  result = (result - 2 + MOD) % MOD;

  cout << result << endl;
  return 0;
}
