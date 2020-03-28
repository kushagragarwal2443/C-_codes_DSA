#include <bits/stdc++.h>
using namespace std;
#define lld long long int
#define pair pair<long long int, long long int>

class comparator
{
public:
	bool operator() (pair &a, pair &b)
	{
		if(a.second>=b.second)
			return true;
		else
			return false;
	}
};

vector<list<pair> > adj(100005);
// lld endg[100005];
priority_queue<pair, vector<pair>, comparator > pq;
vector<bool> endg(100005, false);
vector<lld> visit(100005, 0);


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	lld n,m,k,x,y,w,i,a,res;
	cin>>n>>m>>k;

	for(i=0;i<m;i++)
	{
		cin>>x>>y>>w;
		adj[x].push_back({y,w});
		adj[y].push_back({x,w});
	}

	for(i = 0; i < k; i++)
	{
		cin>>a;
		endg[a]=true;
		// visit[a]=3;
		pq.push({a,0});
	}

	while(!pq.empty())
	{
		pair top = pq.top();
		pq.pop();

		if(top.first==0)
		{
			visit[0]++;
			if(visit[0]==2)
			{
				res=top.second;
				break;
			}
		}
		else if(!endg[top.first])
		{
			visit[top.first]++;
			if(visit[top.first]==2)
				for (auto itr = adj[top.first].begin();itr!=adj[top.first].end();itr++)
					pq.push({(*itr).first,(*itr).second+top.second});
		}
		else if(endg[top.first])
		{
			if(!visit[top.first])
			{
				visit[top.first]=3;
				for (auto itr = adj[top.first].begin();itr!=adj[top.first].end();itr++)
					pq.push({(*itr).first,(*itr).second+top.second});
			}
		}
	}

	if(visit[0]!=2)
		cout<<"-1"<<endl;
	else
		cout<<res<<endl;

	return 0;
}
