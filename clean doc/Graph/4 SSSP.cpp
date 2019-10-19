//{
#define _CRT_SECURE_NO_WARNINGS
//#define ONLINE_JUDGE
#include<bits/stdc++.h>
#define ll                  long long
#define ull                 unsigned long long
#define rep(i,n)            for(ll i=0;i<n;i++)
#define hell                1000000007LL
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define sz(v)               v.size()

#ifdef ONLINE_JUDGE
    #define w(arg)
#else
    #define w(arg) std::cout<<'#'<<arg<<'#'<<'\n';
#endif

using namespace std;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); } // a>b
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
ll Max(ll a, ll b) { return a > b ? a : b; }
ll Min(ll a, ll b) { return a < b ? a : b; }

double pow(double a, int n) { // exponentiation rapide
    double ret = 1.0;
    while(n) {
        if( n & 1 ) ret *= a;
        a *= a; n>>=1;
    }
    return ret;
}

void PLAY() {
#ifndef ONLINE_JUDGE
    freopen("Nouveau document texte.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	//cout << fixed << setprecision(9);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
//}



const double eps = 1e-9;

int Dyjkestra_infinite = std::numeric_limits<int>::max();
#define Dj_val_min  0
#define nax 10000
#define null -1
int to[nax];
int nxt[nax];
int from[nax];
//int p[nax][nax];//poid
int cost[nax];//poid
ull dist[nax];
int edge_size = 0;
void AddEdge(int de, int vers,int poid){
to[edge_size] = vers;
nxt[edge_size] = from[de];
    cost[edge_size]=poid;
from[de] = edge_size;
edge_size++;
}

int d_cmp(double a,double b){
    if(fabs(a-b)<eps)
        return 0;
    return ((a>b)<<1)-1;
}
void dijkstra_init(){
    memset(from, -1, nax*(sizeof from[0]));
    edge_size=0;
}
double dijkstra(int src, int snk){
    priority_queue<pair<ull,int>,vector<pair<ull,int>>, greater<pair<ull,int>>> q;
    //priority_queue< pair<ull,int> > q;
    q.push({Dj_val_min,src});
    memset(dist, Dyjkestra_infinite, nax*(sizeof dist[0]));//initialisé à l'inf
    while(q.size()){
        double d=q.top().first;
        int cur=q.top().second;
        q.pop();
        if(d>dist[cur])
            continue;
        if(snk==cur)
            return d;
        for(int j=from[cur];~j;j=nxt[j]){
            int t=to[j];
            ll dd=d+cost[j];//produit
            if(dist[t]>dd){//inferieur
                dist[t]=dd;
                q.push({dd,t});
            }
        }
    }
    return -1;
}

void _main();
int main() {
	PLAY();
	int ttt;
	cin >> ttt;
	while (ttt--) {
_main();






	}
	return 0;
}
void _main(){

    //init
dijkstra_init();


int v,k,a,b,c;
cin>>v>>k;
/*
int noeud[v];//ptr to dernier element lié à
to[k];
nxt[k];
cost[k];
*/
rep(i,k){
    cin>>a>>b>>c;
    AddEdge(a-1,b-1,c);
}
cin>>a>>b;
ll mn = dijkstra(a-1, b-1);
if (mn==-1){
    cout <<"NO\n";
}else{

    cout <<mn<<"\n";
    }
}


