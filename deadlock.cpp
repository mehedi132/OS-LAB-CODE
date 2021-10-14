#include<iostream>
#include<vector>
#include<map>
using namespace std;
const int maxN =  100000;
vector<int> adj[maxN];
int visited[maxN],par[maxN];
int cycle = 0;
string str[maxN],e1,e2;
int Count=1;

void path(int cur,int target)
{
    if(cur==target)
    {
        cout<<str[cur]<<" ";
        return;
    }
    path(par[cur],target);
    cout<<str[cur]<<" ";
}
void dfs(int node)
{
    visited[node]  = 1;
    for(int i=0;i<adj[node].size();i++)
    {
        if(visited[adj[node][i]]==0)
        {
            par[adj[node][i]]  =node;
            dfs(adj[node][i]);
        }
        else if(visited[adj[node][i]]==1)
        {

            cycle++;
            cout<<"Deadlock ";
            cout<<Count++;
            cout<<" Detected Among Nodes : ";
            path(node,adj[node][i]);
            cout<<endl;
        }
    }
    visited[node]  = 2;
}
int main()
{
    int n,m;
    cout<<"Enter number of nodes : ";
    cin>>n;
    cout<<"Node Names : ";
    map<string,int> com;
    for(int i=1;i<=n;i++)
    {
        cin>>str[i];
        com[str[i]]  = i;
    }
    cout<<"Enter number of edges : ";
    cin>>m;
    cout<<"Edges :"<<endl;
    while(m--)
    {
        cin>>e1>>e2;
        adj[com[e1]].push_back(com[e2]);
    }
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            par[i]  = i;
            dfs(i);
        }
    }
    if(!cycle)
    {
        cout<<"No DeadLock Detected"<<endl;
    }
    if(cycle){
        cout<<"\nNumber of Cycles detected :"<<cycle<<endl;
    }
    return 0;
}
