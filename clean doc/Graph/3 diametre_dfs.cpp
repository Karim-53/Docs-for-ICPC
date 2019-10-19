// lpl using 1 dfs recursive time: O( n log n )  ;  space O( log( n ) )


//{
#include<bits/stdc++.h>
#define ll                  long long
#define rep(i,n)            for(auto i=0;i<(n);++i)
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define sz(v)               v.size()
#define all(v)              std::begin(v), std::end(v)
#define vi                  vector<int>
#define hell                1000000007LL
#define StringToInt(s,n)    if ( ! (istringstream(s) >> n) ) n = 0;
using namespace std;
ll gcd(ll p,ll q){return q==0?p:gcd(q,p%q);}
ll qpow(ll p,ll q){ll f=1;while(q){if(q&1)f=f*p;p=p*p;q>>=1;}return f;}
inline int read() {
	int x=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	while (ch>='0'&&ch<='9') { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}
//}


#define Graph  vector<vector<int > >
Graph g;

void addBiEdge(int v, int w)
{
    g[v].pb(w);    // Add w to v’s list.
    g[w].pb(v);    // Since the graph is undirected
}

//  method returns farthest node and its distance from $node


vector<int> h;//height: doit etre init à -1, ça sera fait dans le main plus tard
vector<int> d;//Diameter: les diamtres des sous arbres

//< height , Diameter >
pair<int,int> lpl(int node) {



    if (~h[node] || !h[node] ){// ni blanc, ni gris  ;/ ne serait-il pas plus rapide de faire h[node]>0
        return mp(h[node],d[node]);
    }
    if (sz(g[node]) == 0) return mp(0,0);
//    cerr<<node<<endl;

    h[node]=0;//coloration gris (en cours)
    int Diameter = 0, h1=-1, h2=-1;

    for (auto v : g[node])
        {
    //cerr<<v<<" "<<!~h[node]<<endl;
            // push node into queue only if
            // it is not visited already
            if (!~h[v])
            {
                auto p = lpl(v);
                if(p.fi >= h1){h2 = h1;h1 = p.fi;}
                else if(p.fi > h2){h2 = p.fi;}
                Diameter = max(Diameter,p.se);
            }
        }


    return mp(1+ max(h1,h2),
              max( Diameter, h1 + h2 + 2)
              );
}



int main(){


//freopen("a.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);





int n,a,b;
cin>>n;
g.resize(n);
rep(i,n-1){
cin>>a>>b;
addBiEdge(a-1,b-1);
}


d.resize(n);
h.resize(n,-1);
auto p = lpl(0);
cout<<p.se;
}
