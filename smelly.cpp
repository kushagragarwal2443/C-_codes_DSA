#include <bits/stdc++.h>
using namespace std;

typedef long long int lld;
typedef pair<lld,lld>pi;

lld smell(lld n, lld m, vector<vector< pi > >&adj, vector<lld> &K, vector<lld>&visit)
{
	lld ans=-1;
	priority_queue< pi, vector< pi >, greater<pi> > pq;

	vector<bool>finish(n,false);

	for(lld i=0;i<K.size();i++)
	{
		pq.push(make_pair(0,K[i]));
		finish[K[i]]=true;
	}

	while(!pq.empty())
	{
		pi t=pq.top();
		pq.pop();

		if(t.second==0)
		{
			if(visit[0]==1)
			{
				ans=t.first;
				break;
			}
			else
				visit[0]++;
		}
		else if(!finish[t.second])
		{
			visit[t.second]++;
			if(visit[t.second]==2)
			{
				for(lld i=0;i<adj[t.second].size();i++)
                                        pq.push(make_pair((t.first+adj[t.second][i].second),adj[t.second][i].first));
                        }
		}
		else if(finish[t.second])
		{
			if(visit[t.second]==0)
			{
				visit[t.second]=10;
				for(lld i=0;i<adj[t.second].size();i++)
                                        pq.push(make_pair((t.first+adj[t.second][i].second),adj[t.second][i].first));
			}
		}

	}
	if(visit[0]==0)
		return -1;
	else
		return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	lld n,m,k;
        lld a,b,w;
        lld c;

	cin>>n>>m>>k;

	vector < vector < pi > > adj(n+2);
	
	for(lld i=0;i<m;i++)
	{
		cin>>a>>b>>w;
		adj[a].push_back(make_pair(b,w));
		adj[b].push_back(make_pair(a,w));
	}


	vector<lld>K;

	for(lld i=0;i<k;i++)
	{
		cin>>c;
		K.push_back(c);
	}

	//for(lld i=0;i<k;i++)
//	{
//		cout<<K[i]<<" ";
//	}
//	cout<<"\n";

	vector<lld> visit(n,0);
	
	long long int an;
	an=smell(n,m,adj,K,visit);

	cout<<an<<"\n";

	return 0;
}


	
