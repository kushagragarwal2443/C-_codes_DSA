#include <bits/stdc++.h>
using namespace std;

typedef pair<int,pair<int,int>>pi;
typedef pair<int,int>p

int main()
{
	int n,m;
	int a,b,w;

	cin>>n>>m;

	vector<pi>edges;

	for(int i=0;i<m;i++)
	{
		cin>>a>>b>>w;
		edges.push_back({w,{b,a}});
		edges.push_back({w,{a,b}});
	}

	sort(edges.begin(),edges.end(),greater);

	for(int i=0;i<m;i++)
	{
		p cur=edges[i].second;

		int x=find_union(parent,cur.first);
		int y=find_union(parent,cur.second);

		if(x!=y)
		{
			ans+=edges[i].first;
			join_union(parent,cur.first,cur.second);
		}
	}
	cout<<ans<<"\n";
	return 0;
}

