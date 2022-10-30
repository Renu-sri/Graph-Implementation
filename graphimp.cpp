#include<bits/stdc++.h>
using namespace std;
void graphs(vector<int> vec[],int p,int q)
{
vec[p].push_back(q);
}
void prints(vector<int> vec[],int n)
{
for(int i=0;i<n;i++)
{
cout<<i;
        for (auto x : vec[i])  
        printf("\n");
}
}
void dfsvisit(bool *visit,int v,vector<int> vec[])
{
visit[v]=true;
cout<<v<<" ";
vector<int>::iterator itr;
for(itr=vec[v].begin();itr!=vec[v].end();itr++)
{
if(!visit[*itr])
dfsvisit(visit,*itr,vec);
}
}
void dfs(int v,int n,vector<int> vec[])
{
bool visit[n];
for(int i=0;i<n;i++)
visit[i]=false;
for (int i = 0; i < n; i++) 
        if (visit[i] == false) 
            dfsvisit(visit,i,vec);
}
void bfsprint(bool *visit,int v,int n,vector<int> vec[])
{
vector<int>::iterator itr;
list<int> que;
que.push_back(v);
visit[v]=true;
while(que.empty()==true)
{
v=que.front();
cout<<v<<" ";
que.pop_front();
for(itr=vec[v].begin();itr!=vec[v].end();itr++)
{
if(!visit[*itr])
{
visit[*itr]=true;
que.push_back(*itr);
}
}
}
}
void bfs(int v,int n,vector<int> vec[])
{
bool visit[n];
for(int i=0;i<n;i++)
visit[i]=false;
bfsprint(visit,v,n,vec);
}
int main()
{
int n,m,p,q;
cin>>n>>m;
vector<int> vec[n];
for(int i=0;i<m;i++)
{
cin>>p>>q;
graphs(vec,p,q);
}
prints(vec,n);
dfs(0,n,vec);
bfs(0,n,vec);
/*graphs(vec,0,4);
graphs(vec,1,2);
graphs(vec,1,3);
graphs(vec,1,4);
graphs(vec,2,3);
graphs(vec,3,4);
prints(vec,n);*/
return 0;
}
