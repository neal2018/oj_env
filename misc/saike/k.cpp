#include<bits/stdc++.h>
using namespace std;
constexpr int N = 205, mod = 1e9 + 7;
void qmo(int &x){x += x >> 31 & mod;}
int T, n, m, f[N][N][N];
char str[N];
void solve(){
	cin >> n >> m >> str;
	if(m & 1){cout<<0<<"\n"; return;}
	for(int i = 0;i <= m;++ i) memset(f[i], 0, sizeof(f[i]));
	f[0][0][0] = 1;
	for(int i = 0;i < m;++ i)
		for(int j = 0;j <= n;++ j)
			for(int k = 0;k < m;++ k){
				qmo(f[i + 1][j + (j < n && str[j] == '(')][k + 1] += f[i][j][k] - mod);
				if(k) qmo(f[i + 1][j + (j < n && str[j] == ')')][k - 1] += f[i][j][k] - mod);
			}
	cout << f[m][n][0] << '\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin >> T; while(T --) solve();
}
