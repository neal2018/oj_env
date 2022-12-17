#include <bits/stdc++.h>
using namespace std;
constexpr int limit = (3000000 + 5);  //防止溢出
#define INF 0x3f3f3f3f
#define inf 0x3f3f3f3f3f
#define lowbit(i) i&(-i)  //一步两步
#define EPS 1e-9
#define FASTIO                 \
  ios::sync_with_stdio(false); \
  cin.tie(0), cout.tie(0);
#define ff(a) printf("%d\n", a);
#define pi(a, b) pair<a, b>
#define rep(i, a, b) for (ll i = a; i <= b; ++i)
#define per(i, a, b) for (ll i = b; i >= a; --i)
#define MOD 998244353
#define traverse(u) for (int i = head[u]; ~i; i = edge[i].next)
#define FOPEN freopen("C:\\Users\\tiany\\CLionProjects\\akioi\\data.txt", "rt", stdin)
#define FOUT freopen("C:\\Users\\tiany\\CLionProjects\\akioi\\dabiao.txt", "wt", stdout)
typedef long long ll;
typedef unsigned long long ull;
char buf[1 << 23], *p1 = buf, *p2 = buf, obuf[1 << 23], *O = obuf;

inline ll read() {
#define getchar() \
  (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
  ll sign = 1, x = 0;
  char s = getchar();
  while (s > '9' || s < '0') {
    if (s == '-') sign = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = (x << 3) + (x << 1) + s - '0';
    s = getchar();
  }
  return x * sign;
#undef getchar
}  //快读
void print(ll x) {
  if (x / 10) print(x / 10);
  *O++ = x % 10 + '0';
}

void write(ll x, char c = 't') {
  if (x < 0) putchar('-'), x = -x;
  print(x);
  if (!isalpha(c)) *O++ = c;
  fwrite(obuf, O - obuf, 1, stdout);
  O = obuf;
}
int n, m, k;
int a[limit];
ll C[5005][5005];
ll p;
ll fact[5005];
void Init() {
  C[0][0] = 1;
  fact[0] = 1;
  rep(i, 1, 5004) { fact[i] = fact[i - 1] * i % p; }
  for (int i = 1; i <= 5004; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % p;
    }
  }
}
void solve() {
  cin >> n >> p;
  Init();
  ll ans = 0;
  rep(i, 1, (n + 1) / 2 - 1) {
    ll side = (n - 1) / 2 - i;
    ll tmp = n - side - 1;  //上面的个数
    tmp -= i + side;        //下面的个数
    if (tmp < 0) continue;
    //处理中间的
    ll res = 0;
    rep(j, 0, i - 1) { res += (C[i - 1][j] * fact[n - 2 - i + j]) % p; }
    res %= p;
    res = (res * tmp) % p;
    (res *= n) % p;
    ans += res;
    ans %= p;
  }
  ans += (n & 1) ? 0 : fact[n - 2] * n;
  ans %= p;
  cout << ans << endl;
};
int32_t main() {
#ifdef LOCAL
  FOPEN;
//    FOUT;
#endif
  FASTIO
  //    int kase;
  //    cin>>kase;
  //    while (kase--)
  solve();
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";
  return 0;
}
