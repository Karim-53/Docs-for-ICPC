//SPOJ
//diamètre
//Longest path in an undirected tree:
//Given an undirected tree, we need to find the longest path of this tree where a path is defined as a sequence of nodes.





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

//  method returns farthest node and its distance from node u
//<node, distance>
pair<int, int> bfs(int u)
{
    //  mark all distance with -1
    vector<int> dis( sz(g) , -1 );

    queue<int> q;
    q.push(u);

    //  distance of u from u will be 0
    dis[u] = 0;

    while (!q.empty())
    {
        int t = q.front();       q.pop();

        //  loop for all adjacent nodes of node-t
        for (auto v : g[t])
        {
            // push node into queue only if
            // it is not visited already
            if (dis[v] == -1)
            {
                q.push(v);

                // make distance of v, one more
                // than distance of t
                dis[v] = dis[t] + 1;
            }
        }
    }

    //  get farthest node distance and its index
   auto it =  max_element(all(dis));
    int maxDis = *it ;
    int idx = distance(dis.begin(), it);

     return mp(idx, maxDis);
}

//  method prints longest path of given tree
void LongestPathLength()
{
    // first bfs to find one end point of longest path
    auto t1 = bfs(0);

    //  second bfs to find actual longest path
    auto t2 = bfs(t1.first);

    cout << "Longest path is from " << t1.first << " to " << t2.first << " of length " << t2.second;
//cout<<t2.second;
}

// Driver code pour calibrage
//int main_drive(){
int main(){
    // Create a graph given in the example
    g.resize(10);
    addBiEdge(0, 1);
    addBiEdge(1, 2);
    addBiEdge(2, 3);
    addBiEdge(2, 9);
    addBiEdge(2, 4);
    addBiEdge(4, 5);
    addBiEdge(1, 6);
    addBiEdge(6, 7);
    addBiEdge(6, 8);

    LongestPathLength();
    //rep="Longest path is from 5 to 7 of length 5"
    return 0;
}
//int main(){
//int n,a,b;
//cin>>n;
//rep(i,n-1){
//cin>>a>>b;
//addBiEdge(a,b);
//}
//
//
// longestPathLength();
//
//}
