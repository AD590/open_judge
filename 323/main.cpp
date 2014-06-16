#include <iostream>
#include <cstdio>

using namespace std;


int fun(bool* board, int n,int k){
	int result = 0;
	if(k==1){
		for (int i = 0;i < n; ++i){
			for (int j = 0; j< n; ++j)
				result += board[i*n +j];
		}
		return result;
	}
	for (int i = 0; i < n; ++i){
		for(int j= 0; j < n; ++j){
			if(board[n * i + j]){
				bool sub_board[n*n];
				memcpy(sub_board, board, sizeof(bool)*n*n);
				for (int m = 0; m < n; ++m){
					sub_board[i * n + m] = sub_board[n * m + j] = false;
				}
				board[i *n + j] = false;
				result += fun(sub_board, n, k-1);
			}
		}

	}
	return result;
}



int main(){
	freopen("in.txt","r",stdin);
	int n,k,i,j;
	cin>>n>>k;
	while(n != -1 && k != -1){
		bool board[n * n];
		for(i = 0 ; i < n; ++i){
			char tmp[n + 1];
			scanf("%s", tmp);
			for (j = 0 ; j < n; ++j){
				board[i * n + j] = (tmp[j]=='#');
			}
		}
		cout<<fun(board, n, k)<<endl;
		cin>>n>>k;
	}
	return 0;
}





