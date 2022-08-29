#include<bits/stdc++.h>
using namespace std;
int dp[1005]={0},h[50005]={0},n,ans;
int main(){
    cin >> n;
    for(int i=0;i<n;i++) cin>>h[i];
    for(int i=0;i<n;i++){
        dp[i]=1;//单独的数字作为子序列答案为1
        for(int j=0;j<i;j++){
            // 补全代码：填写dp数组
            if(h[i] <= h[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        // 补全代码：更新dp数组最大值
        ans=max(ans,dp[i]);
    }
    cout << ans;
    return 0;
}