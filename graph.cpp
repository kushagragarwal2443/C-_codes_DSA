#include <bits/stdc++.h>

using namespace std;

void bfs(int s,vector<vector<int>>&adj,int n)
{
	queue<int>qu;
	qu.push(s);
	vector<bool>visit(n,false);

	while(!qu.empty())
	{
		int node=qu.front();
		qu.pop();
		visit[node]=true;
		for(int i=0;i<adj[node].size();i++)
		{
			if(!visit[adj[node][i]])
				qu.push(adj[node][i]);
		}
	cout<<node<<" ";
	}
	return;
}


void visitDFS(int x,vector<bool>&visit,vector<vector<int>>&adj,int n)
{
        visit[x]=true;
        cout<<x<<" ";

        int y=adj[x].size();

        for(int i=0;i<y;i++)
        {
                if(!visit[adj[x][i]])
                        visitDFS(adj[x][i],visit,adj,n);
        }

        return;
}


int visitDFScycle(int x,vector<bool>&visit,vector<vector<int>>&adj,int n,int flag)
{
	visit[x]=true;
	int a;

	int y=adj[x].size();

	for(int i=0;i<y;i++)
	{
		if(!visit[adj[x][i]])
			a=visitDFScycle(adj[x][i],visit,adj,n,flag);
		else
		{
			flag=1;
		}
	}

	return flag;
}
void DFScycle(int u,vector<vector<int>>&adj,int n)
{
	vector<bool>visit(n,false);
	int x=visitDFScycle(u,visit,adj,n,0);
	if(x==0)
		cout<<"No cycle exists\n";
	else
		cout<<"Cycle exists\n";
	return;
}

void DFS(int u,vector<vector<int>>&adj,int n)
{
        vector<bool>visit(n,false);
        visitDFS(u,visit,adj,n);
	return;
}




int main()
{
	int x,y,n,e,a,b,i,j,z;
	cin>>n>>e;

	//vector<vector><int>adj(n,vector<int>(0));
	vector<vector<int>>adj(n);
	
	for(i=0;i<e;i++)
	{
		cin>>a>>b;
		adj[a].push_back(b);
	}
	
	cout<<"\nThe graphs adjacency lists are as follows\n";
	for(i=0;i<n;i++)
	{
		cout<<i<<": ";
		for(j=0;j<adj[i].size();j++)
		{
			cout<<adj[i][j]<<", ";
		}
		cout<<"\n";
	}
	cout<<"\nThe BFS is to be found with: ";
	cin>>x;
	bfs(x,adj,n);
	cout<<"\n";
	
	cout<<"\nThe DFS is to be found with: ";
	cin>>y;
	DFS(y,adj,n);
	cout<<"\n";

	cout<<"\nChecking for cycle: ";
        DFScycle(1,adj,n);

	return 0;
}
