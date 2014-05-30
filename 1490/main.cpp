#include <iostream>
#include <cstdio>
#include <stack>
#include <cstdlib>
#include <cstring>

#define MAX 26

using namespace std;
struct Node{
	 char c;
	 int r;
	 Node(int _r, int _c):c('A'+_c), r(_r +1 ){}
};

stack<Node> trace;
bool visited[MAX+4][MAX+4];

bool fun(int r,int c, int p, int q){
	bool finish = true;
	visited[r][c] = true;
	for(int i = 2; i < p + 2; ++i){
		for( int j = 2; j < q + 2; ++j){
			if(!visited[i][j]){
				finish = false;
				break;
			}
		}
		if(!finish)
			break;
	}
	if(finish)
		return true;
	for (int m = -2; m < 3; ++m){
		if (m == 0)
			continue;
		int i;
		i = r - 2 / abs(m);
		int j = c + m;
		if(!visited[i][j]){
			if(fun(i, j, p, q)){
				trace.push(Node(i-2,j-2));
				return true;
			}
			else
				visited[i][j] = false;
		}
		i = r + 2 / abs(m);
		if(!visited[i][j]){
			if(fun(i, j, p, q)){
				trace.push(Node(i-2,j-2));
				return true;
			}
			else
				visited[i][j] = false;
		}
	}
	return false;
}


int main(){
	freopen("in.txt","r",stdin);
	freopen("result.txt","w",stdout);
	int n;
	cin>>n;
	for(int s = 1; s <= n; ++s){
		int p,q;
		cin>>p>>q;
		cout<<"Scenario #"<<s<<":\n";
		bool find = false;
		for (int r_start = 0; r_start < p; ++r_start){
			for(int c_start = 0; c_start < q; ++c_start){
				memset(visited, false, sizeof(bool) * (MAX+4) * (MAX+4));
				for (int i = 0; i < p + 4; ++i)
					visited[i][0] = visited[i][1] = visited[i][q+2] = visited[i][q+3] = true;
				for (int i = 0; i < q + 4; ++i)
					visited[0][i] = visited[1][i] = visited[p+2][i] = visited[p+3][i] = true;
				if(fun(r_start + 2 , c_start + 2,p,q)){
					Node start(r_start,c_start);
					cout<<start.c<<start.r;
					while(trace.size() != 0){
						cout<<trace.top().c<<trace.top().r;
						trace.pop();
					}
					cout<<"\n\n";
					find = true;
					break;
				}
			}
			if(find)
				break;
		}
		if(!find)
			cout<<"impossible\n\n";
	}
	return 0;
}





