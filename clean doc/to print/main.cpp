//$ time g++ -c -std=c++11 vec.cpp -fconstexpr-depth=600
//#pragma comment(linker, "/STACK:36777216")
//OPT COMPILER:global compiler c++11
//Lex MOD-0 ver. 2.4 (22/06/2018)
//la ilaha illallah
//{
#include<bits/stdc++.h>
#define ll                  long long
#define rep(i,n)            for(auto i=0;i<(n);++i)
#define pb                  push_back
#define mp                  make_pair
#define ff                  first
#define ss                  second
#define sz(v)               v.size()
#define all(v)              std::begin(v), std::end(v)
#define vi                  vector<int>
#define mod                 1000000007LL

#define StringToInt(s,n)    if ( ! (istringstream(s) >> n) ) n = 0;
using namespace std;
template <typename T>
string NumberToString ( T Number ){
	std::ostringstream ss; ss << Number; return ss.str();}

#ifdef ONLINE_JUDGE
#define line
#define o(x)
#else
#define line                cerr<<'\n';
#define o(x)				cerr << __LINE__ << " $" << #x << " = " << x << "\n";
#endif // ONLINE_JUDGE

ll qpow(ll p,ll q){ll f=1;while(q){if(q&1)f=f*p%mod;p=p*p%mod;q>>=1;}return f;}
inline int read() {
	int x=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	while (ch>='0'&&ch<='9') { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}
//}
int main() {
#ifndef ONLINE_JUDGE
//freopen("a.txt", "r", stdin);
#endif // ONLINE_JUDGE
	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	//cout << fixed << setprecision(9);

	int ttt; cin >> ttt;
	while (ttt--) {
		
	}
	return 0;}