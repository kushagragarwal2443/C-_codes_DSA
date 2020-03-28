#include <bits/stdc++.h>
using namespace std;

typedef pair<long long int, long long int> pi;

void prims_algorithm(long long int n,long long int m,long long int key[],vector < bool > &visit,vector< vector< pi > > &adj)
{
	priority_queue< pi, vector< pi >, greater<pi> > pq;
	pq.push(make_pair(0,0));
	pi t;

	while(!pq.empty())
	{
		t=pq.top();
		pq.pop();

		if(!visit[t.second])
		{
			visit[t.second]=true;
			key[t.second]=t.first;

			for(long long int i=0;i<adj[t.second].size();i++)
                        {
                                if(!visit[adj[t.second][i].first])
                                {
                                        pq.push(make_pair((adj[t.second][i].second),adj[t.second][i].first));
                                }
                        }
                }
        }
}

int main()
{
	long long int n,m,k;
	long long int a,b,w;

	ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

	cin>>n>>m>>k;
	
	vector < vector < pi > > adj(n);

	for(long long int i=0;i<m;i++)
	{
		cin>>a>>b>>w;
		a--;
		b--;

		adj[a].push_back(make_pair(b,w));
		adj[b].push_back(make_pair(a,w));
	}

	long long int key[n]={10000000000};
	vector <bool> visit(n,false);

	prims_algorithm(n,m,key,visit,adj);
	
	long long int flag=0;
	for(long long int i=0;i<n;i++)
	{
		if(!visit[i])
			flag=1;
	}
	
	if(flag==1)
		cout<<-1<<"\n";
	else
	{
		sort(key,key+n,less<long long int>());
		
		//for(long long int i=0;i<n;i++)
		//	cout<<key[i]<<" ";
		//cout<<"\n";
		
		long long int su=0;
		long long int co=0;
		for(long long int i=0;i<n;i++)
                {
	                su+=key[i];
                }

		for(;;)
		{
			if(su<=k)
			{
				cout<<co<<"\n";
				break;
			}
			else
			{
				if(n>0)
				{
					co++;
					su-=key[n-1];
					n--;
					su+=1;
				}
				else
				{
					cout<<-1<<"\n";
					break;
				}
			}
		}
	}
	return 0;
}
		

