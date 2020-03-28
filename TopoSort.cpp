#include <bits/stdc++.h>

using namespace std;

vector<int>topos;

void TopoSort(queue<int>&q,vector<vector<int>>&adj,vector<int>&indegree,int n)
{
	for(int i=0;i<n;i++)
	{
		if(indegree[i]==0)
		{
			q.push(i);
		}
	}
	
	
	while(!q.empty())
	{
		int node=q.front();
		int size=adj[node].size();
		for(int j=0;j<size;j++)
		{
			indegree[adj[node][j]]--;
			if(indegree[adj[node][j]]==0)
				q.push(adj[node][j]);
		}
		cout<<q.front()<<" ";
		q.pop();
	}

}


void perfTopSort(int u,vector<bool>&visit,vector<vector<int>>&adj,int n,stack<int>&st)
{
	visit[u]=true;
	
	int y=adj[u].size();

	for(int i=0;i<y;i++)
	{
		if(!visit[adj[u][i]])
		{
			perfTopSort(adj[u][i],visit,adj,n,st);
		}
	}
	
	st.push(u);
	return;
}


void TopSort(int u,vector<bool>&visit,vector<vector<int>>&adj,int n,stack<int>&st)
{
	perfTopSort(u,visit,adj,n,st);
	return;
}

void visitDFS(int x,vector<bool>&visiting,vector<vector<int>>&revadj,int n)
{
        visiting[x]=true;
        cout<<x<<" ";

        int y=revadj[x].size();

        for(int i=0;i<y;i++)
        {
                if(!visiting[revadj[x][i]])
                        visitDFS(revadj[x][i],visiting,revadj,n);
        }

        return;
}


void DFS(int u,vector<bool>&visiting,vector<vector<int>>&revadj,int n)
{
        visitDFS(u,visiting,revadj,n);
	cout<<"\n";
        return;
}

int main()
{
	int val,n,a,b,e;

	cin>>n>>e;

	vector<vector<int>>adj(n);
	vector<vector<int>>revadj(n);
	
	vector<int>indegree(n,0);

	stack <int> st;

	vector<bool>visit(n,false);

	for(int i=0;i<e;i++)
	{
		cin>>a>>b;
		adj[a].push_back(b);
		indegree[b]++;
		revadj[b].push_back(a);

	}

	cout<<"\nThe Adjacency list is as follows:\n";

	for(int i=0;i<n;i++)
	{
		cout<<i<<": ";
		for(int j=0;j<adj[i].size();j++)
		{
			cout<<adj[i][j]<<", ";

		}
		cout<<"\n";
	}

	cout<<"\nThe Topological Sort by DFS algorithm is:\n";
	
	for(int i=0;i<n;i++)
	{
		if(visit[i]==0)
		{
			TopSort(i,visit,adj,n,st);
			//cout<<"\n";
		}
	}

	for(int i=0;i<n;i++)
	{
		val=st.top();
		topos.push_back(val);
		st.pop();
		cout<<val<<" ";
	}

	cout<<"\n";
	queue<int>q;
	cout<<"\nThe Topological Sort by Kahn's Algorithm is:\n";
	TopoSort(q,adj,indegree,n);
	cout<<"\n";
	
	cout<<"\nThe Strongly Connected Components are:\n";
	//for(int i=0;i<topos.size();i++)
	//	cout<<topos[i]<<" ";
	//cout<<"\n";
	
	vector<bool>visiting(n,false);
	for(int i=0;i<topos.size();i++)
	{
		if(!visiting[i])
			DFS(topos[i],visiting,revadj,n);
	}


	return 0;
}
	
