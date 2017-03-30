#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int tc; cin>>tc;
	while(tc--){
	    int r,c; cin>>r>>c;
	    int arr[r][c],dp[r][c];
	    for(int i=0;i<r;i++)
	    {
	        for(int j=0;j<c;j++){
	            cin>>arr[i][j];
	        }
	    }
	    int i=0,j=0; if(arr[i][j]<=0) dp[i][j]=abs(arr[i][j])+1; else dp[i][j]=1;
	    for(j=1;j<c;j++) { arr[i][j]+=arr[i][j-1]; if(arr[i][j]<=0) dp[i][j]=max(abs(arr[i][j])+1,dp[i][j-1]); else dp[i][j]=dp[i][j-1]; } 
	    i=0; j=0;
	    for(i=1;i<r;i++) { arr[i][j]+=arr[i-1][j]; if(arr[i][j]<=0) dp[i][j]=max(abs(arr[i][j])+1,dp[i-1][j]); else dp[i][j]=dp[i-1][j]; } 
		i=0; j=0; 
	    for(i=1;i<r;i++){
	        for(j=1;j<c;j++){
	            if(dp[i-1][j]>dp[i][j-1]) { arr[i][j]+=dp[i][j-1]; 
	                if(arr[i][j]<=0) dp[i][j]=abs(arr[i][j])+1; else dp[i][j]=dp[i][j-1];
	            }
	            else{   arr[i][j]+=dp[i-1][j]; 
	                if(arr[i][j]<=0) dp[i][j]=abs(arr[i][j])+1; else dp[i][j]=dp[i-1][j];
	            }
	        }
	    }
	    
	    for(i=0;i<r;i++){
	        for(j=0;j<c;j++){
	           cout<<dp[i][j]<<" ";
	        }
	        cout<<endl;
	    }
	    cout<<dp[r-1][c-1]<<endl;
	}
	return 0;
}