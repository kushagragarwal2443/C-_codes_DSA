#include <bits/stdc++.h>
using namespace std;

typedef pair<long long int,long long int> pi;

void dijsktras(vector< long long int >&dista, long long int n,long long int m,long long int source,vector< vector< pi > > &adj)
{
	vector < bool > visit(n,false);
	vector<long long int>dist(n,10000000000);
	priority_queue< pi, vector< pi >, greater<pi> > pq;
	
	pair<long long int,long long int>t;
	
	pq.push(make_pair(0,source));
	cout<<"Printing Priority Queue\n";
	while(!pq.empty())
	{
		t=pq.top();

		cout<<t.first<<" "<<t.second<<"\n";
		pq.pop();

		if(!visit[t.second])
		{
			visit[t.second]=true;
			dist[t.second]=t.first;

			for(long long int i=0;i<adj[t.second].size();i++)
			{
				if(!visit[adj[t.second][i].first])
				{
					pq.push(make_pair((dist[t.second]+adj[t.second][i].second),adj[t.second][i].first));
				}
			}
		}
	}

	for(long long int i=0;i<n;i++)
	{
		if(dista[i]!=10000000000)
		{
			dista[i]+=dist[i];
		}
	}

}

int main()
{
	long long int n,m,start,end;
	long long int a,b,w;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	

	cin>>n>>m>>start>>end;
	start--;
	end--;

	vector<long long int>dista(n,0);


	vector < vector < pi > > adj1(100007);
	vector < vector< pi > > adj2(100007);

	for(long long int i=0;i<m;i++)
	{
		cin>>a>>b>>w;
		a--;
		b--;
		adj1[a].push_back(make_pair(b,w));
		adj2[b].push_back(make_pair(a,w));
	}

	dijsktras(dista,n,m,start,adj1);
	dijsktras(dista,n,m,start,adj2);
	dijsktras(dista,n,m,end,adj1);
	dijsktras(dista,n,m,end,adj2);
	
	long long int min=10000000000;
	long long int flag=1;

	for(long long int i=0;i<n;i++)
	{
		if(dista[i]<min && i!=start && i!=end)
		{
			min=dista[i];
			flag=0;
		}
	}

	if(flag==0)
		cout<<min<<"\n";
	else
		cout<<-1<<"\n";

	return 0;
}

