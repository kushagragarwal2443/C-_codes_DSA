#include <bits/stdc++.h>

using namespace std;

vector <vector<pair <int, int>>> adst(100000);
vector<int> visited(10000, 0);

void addedge(int u, int v, int wt)
{
    adst[u].push_back(make_pair(v, wt));
    adst[v].push_back(make_pair(u, wt));
}

void prims(int src, int v, int d[], vector <int> &visited) {

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>>> Q;

    src = 0;
    Q.push(make_pair(0, src));

    visited.resize(v);

    for(int i=0; i<v; i++)
    {
        visited[i]=0;
    }

    while (!Q.empty()) {

        pair<int, int> temp;
        temp = Q.top();
        Q.pop();

        if (visited[temp.second] == 0) {

            visited[temp.second] = 1;
            d[temp.second]=temp.first;

            for (int i = 0; i < adst[temp.second].size(); i++) {
                if (visited[adst[temp.second][i].first] == 0) {
                    Q.push(make_pair(adst[temp.second][i].second, adst[temp.second][i].first));
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);

    int v, e, k;
    cin>>v>>e>>k;

    adst.resize(v);

    int v1, v2, wt;
    for(int i=0; i<e; i++)
    {
        cin>>v1>>v2>>wt;
        v1--;
        v2--;
        addedge(v1, v2, wt);
    }

    int d[v] = {INT_MAX};

    prims(0, v, d, visited);

    int sum=0;
    int flag = 1;

    for(int i=0; i<v; i++)
    {
        if(visited[i] == 0)
        {
            flag = 0;
        }
    }

    if( flag == 0)
    {
        cout<<"-1\n";
    }
    else{
        sort(d, d+v, less<int>());

        for(int i=0; i<v; i++)
        {
            sum += d[i];
        }
        int updates = 0;
        while(updates>=0)
        {
            if(sum<=k)
            {
                cout<<updates<<"\n";
                break;
            }
            else if(updates == v-1)
            {
                cout<<"-1\n";
                break;
            }
            else{
                updates++;
                sum -= d[updates-1];
                sum += 1;
            }
        }
    }

    return 0;
}
