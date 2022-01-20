#include <bits/stdc++.h>
using namespace std;
int si,last;
const int MAXLEN = 2e5+100;
struct Node{
	int link,si[5],len;
	int nxt[26];
}st[MAXLEN<<1];
void init(){
	st[0].len = 0;st[0].link = -1;last = 0;si++;
}
void insert(int c,int op){
	int cur = si++;st[cur].len = st[last].len + 1;
	st[cur].si[op] = 1;
	int p = last;
	while(p != -1 && !st[p].nxt[c]){
		st[p].nxt[c] = cur;
		p = st[p].link;
	}
	if(p == -1) st[cur].link = 0;
	else {
		int q = st[p].nxt[c];
		if(st[q].len == st[p].len + 1) st[cur].link = q;
		else {
			int cl = si++;
			st[cl].len = st[p].len + 1;
			st[cl].link = st[q].link;
			for(int i = 0;i < 26;i++) st[cl].nxt[i] = st[q].nxt[i];
			while(p != -1 && st[p].nxt[c] == q)
			{
				st[p].nxt[c] = cl;p = st[p].link;	
			}
			st[q].link = st[cur].link = cl;
		}
	}
	last = cur;
}
const int N = 2e6+100;
int nxt[N<<2],to[N<<2],head[N<<1],Cnt = 0;
void build(){
	for(int i = 1;i < si;i++){
		int x = st[i].link,y = i;
		to[++Cnt] = y;nxt[Cnt] = head[x];head[x] = Cnt;
	}
}
int n;
void dfs(int x){
	for(int i = head[x];i;i = nxt[i]){
		int y = to[i];
		dfs(y);
		for(int j = 0;j < n;j++){
			st[x].si[j] += st[y].si[j];
		}
	}
}

char ch[N];
int main()
{
	init();
	 cin>>n;
	for(int i = 1;i <= n;i++){
		cin >> ch;
		int L = strlen(ch);
		for(int j = 0;j < L;j++){
			insert(ch[j]-'a',i-1);
		}
		last = 0;
	}
	build();
	dfs(0);
	int ans = 0;
	for(int i = 0;i < si;i++){
		for(int j = 0;j < n;j++){
			if(st[i].si[j] == 0) break;
			if(j == n-1) {
				ans = max(ans,st[i].len);
			}
		}
	}
	cout << ans << endl;
	return 0;
}