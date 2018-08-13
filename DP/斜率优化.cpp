#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define sz(a) (int)a.size()
#define de(a) cout<<#a<<" = "<<a<<endl
#define dd(a) cout<<#a<<" = "<<a<<" "
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
//---

const int N=400005;
const int mod=1e9+7;

ll a[N],f[N],s[N];
int n,t,l,r,pos;

struct node{
	ll x,y;
	node(ll x=0,ll y=0):x(x),y(y){}
} h[N];

ll cal(int x) {
	return f[x]-s[x]+a[x+1]*x;
}

bool check(const node &a,const node &b,const node &c) {
	return (c.y-b.y)*(b.x-a.x)>(b.y-a.y)*(c.x-b.x);
}//判断斜率递增 

bool check2(const node &a,const node &b,int w) {
	return (b.y-a.y<(b.x-a.x)*w);
}//判断后比前优 

int main(){
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	ios::sync_with_stdio(false);
	while (cin>>n>>t) {
		rep(i,1,n+1) cin>>a[i];
		sort(a+1,a+n+1);
		rep(i,1,n+1) s[i]=s[i-1]+a[i];
		l=1;r=0;
		rep(i,t,n+1) {
			if (i-t<t) f[i]=s[i]-a[1]*i;else {
				while (l<r && check2(h[l],h[l+1],i)) l++;
				f[i]=h[l].y+s[i]-h[l].x*i; 	
			}		
			pos=i+1-t;if (pos<t) continue;
			node tmp(a[pos+1],cal(pos));	
			while (l<r && !check(h[r-1],h[r],tmp)) r--;
			h[++r]=tmp;
		}
		cout<<f[n]<<endl;
	} 
	return 0;
}
