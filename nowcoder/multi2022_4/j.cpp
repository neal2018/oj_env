#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int fa[N],size[N],n,m,ans;
int read(){
	int x=0,w=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*w;
}

int find(int x){
	if(fa[x]==x)return fa[x];
	fa[x]=find(fa[x]);
	size[fa[x]]+=size[x];
	size[x]=0;
	return fa[x];
}

void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy){
		size[fx]+=size[fy];size[fy]=0;
		fa[fy]=fx;
	}
}
//以上是并查集 
int main(){
	n=read();m=read();ans=0;
	for(int i=1;i<=2*n;i++)fa[i]=i;
	for(int i=1;i<=n;i++)size[i]=0;
	for(int i=1+n;i<=2*n;i++)size[i]=1;//预处理 
	for(int i=1;i<=m;i++){
		int x=read(),y=read();
		int fx=find(x),fy=find(y),fxn=find(x+n),fyn=find(y+n);//假定x,y表示坏人，x+n,y+n表示好人 
		string ch;cin>>ch;
		if(ch=="good"){
			merge(x, y);merge(x+n, y+n);//如果x说y是好人，则x,y要么同时是好人，要么同时是坏人 
		}else {
			merge(x, y+n);merge(y, x+n);//如果x说y是坏人，则x,y一定有一好一坏的情况 
		}
	}
	for(int i=1;i<=n;i++){
		if(find(i)==find(i+n)){cout<<-1<<endl;return ;}//如果出现了i既是好人又是坏人的情况，则无解 
	}
	for(int i=1;i<=n;i++){
		ans+=max(sz[find(i)], sz[find(i+n)]);//统计答案 ,取max是因为贪心取最大就好，因为两个不同条件的成立带来的影响是不一样的 
		size[find(i)]=size[find(i+n)]=0;//注意清0，因为之前已经统计过答案了 
	}cout<<ans<<endl;
	return 0;
}


