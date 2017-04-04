#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[100];

void printbfs(int start){
	queue<int> q; q.push(start);
	while(!q.empty()){
		int top = q.front(); cout<<top<<"  "; q.pop(); vector<int>::iterator it;
		for(it=graph[top].begin();it<graph[top].end();it++){
			q.push(*it);
		}
	}
	cout<<endl;
}
int main(){
	int edges; cin>>edges; 
	for(int i=0;i<edges;i++){
		int u,v; cin>>u>>v;
		graph[u].push_back(v);
		//graph[v].push_back(u);
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<graph[i].size();j++){
			cout<<graph[i][j]<<" ";
		}
		cout<<endl;
	}
	printbfs(1);
	return 0;	
}