#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i];}cout<<endl;
#define pprint(A,m,n) rep(j,0,m){print(A[j],n);}
const long mod=1e9+7;
const int size=1e5;
const int inf=1e9;
template<typename T> T fact(T n){//n! O(n)
    T res=1;
    rep(i,1,n+1) res*=i;
    return res;
}
template<typename T> T perm(T n,T r){//nPr O(r)
    T res=1;
    rep(i,n-r+1,n+1) res*=i;
    return res;
}
template<typename T> T comb(T n,T r){//nCr
    return perm(n,r)/fact(r);
}
//----------------------------------------------------------
long fact[size];
void calc(int n){
	fact[0]=1;
	rep(i,1,n+1){
		fact[i]=(fact[i-1]*i)%mod;
	}
	return;
}
long modcomb(long n,long r){//nCr mod p
	if(n<r) return 0;
	long temp=(fact[n-r]*fact[r])%mod;
	long res=1; int i=0;
	while( (mod-2) >= (1<<i) ){
		if( (mod-2) & (1<<i) ) (res*=x)%=mod;
		i++; x = x * x % mod;
	}
    return (res*fact[n])%mod;
}
//------------------------------------------------------------
long modfact(long n,long p){//n! mod p
    if(n>=p) return 0;
    long res=1;
    rep(i,1,n+1) (res*=i)%=p;
    return res;
}
long modperm(long n,long r,long p){//nPr mod p
    if( n-r >= p || r%p > n%p) return 0;
    long res=1;
    rep(i,n-r+1,n+1) (res*=i)%=p;
    return res;
}
long modcomb(long n,long r,long p){//nCr mod p
	long temp=modfact(r,p);
	long res=1; int i=0;
	while( (p-2) >= (1<<i) ){
		if( (p-2) & (1<<i) ) (res*=x)%=p;
		i++; x = x * x % p;
	}
    return (res*modperm(n,r,p))%p;
}
//-------------------------------------------------------------
template<typename T>
vector<vector<T>> pascal(T n){//O(N^2)
	vector<vector<T>> table(n+1,vector<T>(n+1));
	rep(i,0,n+1){
		rep(j,0,i+1){
			if(j==0||j==i) table[i][j]=1;
			else table[i][j]=table[i-1][j-1]+table[i-1][j];
		}
	}return table;
}

int main(){
	int n,r;cin>>n>>r;
	cout<<fact(n)<<" "<<perm(n,r)<<" "<<comb(n,r)<<endl;
	cout<<modfact(n,7)<<" ";
	cout<<modperm(n,r,7)<<" ";
	cout<<modcomb(n,r,7)<<endl;
	pprint(pascal(n),n+1,n+1);
}