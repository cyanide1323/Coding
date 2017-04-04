#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int tc; cin>>tc;
    while(tc--){
        int n,m; cin>>n>>m;
        int arr[n][m]; int row[n],col[m];
        for(int i=0;i<n;i++) row[i]=0;
        for(int i=0;i<m;i++) col[i]=0;
        int max_row,prev,cnt;
        
        for(int i=0;i<n;i++){
            max_row=1; prev=arr[i][0]; cnt=1;
            for(int j=1;j<m;j++){
                if(arr[i][j]==prev) { cnt++;  max_row=max(max_row,cnt); }
                else { cnt=1; prev=arr[i][j]; }
            }
            row[i]=max_row;
        }
        
        int max_col;
        for(int j=0;j<m;j++){
            max_col=1; prev=arr[0][j]; cnt=1;
            for(int i=1;i<n;i++){
                if(arr[i][j]==prev) { cnt++; max_col = max(max_col,cnt); }
                else { cnt=1; prev=arr[i][j]; }
            }
            col[j]=max_col;
        }
        
        int max_val=1; 
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                max_val=max(max_val,row[i]*col[j]);
            }
        }
        
        cout<<"row"<<endl;
        for(int i=0;i<n;i++) cout<<row[i]<<" ";
        cout<<endl; cout<<"col"<<endl;
        for(int j=0;j<m;j++) cout<<col[j]<<" ";
        cout<<endl;
        cout<<max_val<<endl;
    }
    return 0;
}
