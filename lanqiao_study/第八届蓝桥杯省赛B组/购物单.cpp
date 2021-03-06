/**
  *@filename:购物单
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-03-31 13:21
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 1000 + 5;
const int mod = 1e9+7;

//复制数据到数组中
float price[maxn]={180.90,10.25,56.14,104.65,
100.30,297.15,26.75,130.62,240.28,270.62,115.87,
247.34,73.21,101.00,79.54,278.44,199.26,12.97,
166.30,125.50,84.98,113.35,166.57,42.56,81.90,131.78,
255.89,109.17,146.69,139.33,141.16,154.74,59.42,
85.44,293.70,261.79,11.30,268.27,128.29,251.03,
208.39,128.88,62.06,225.87,12.89,34.28,62.16,129.12,
218.37,289.69};
float discount[maxn]={0.88,0.65,0.9,0.9,0.88,0.5,0.65,0.5,0.58,0.8,0.88,
0.95,0.9,0.5,0.5,0.7,0.5,0.9,0.78,0.58,0.9,0.68,0.5,0.9,0.95,0.8,0.78,0.9,
0.68,0.65,0.78,0.8,0.8,0.68,0.88,0.65,0.88,0.58,0.88,0.8,0.75,0.75,0.9,0.75,
0.75,0.75,0.58,0.5,0.5,0.8};         
int n;
void solve(){
    float ans=0;
    for(int i=0;i<50;i++){
        ans+=price[i]*discount[i];
    }
    //直接打印，手动判断需要多少。
    cout<<ans<<endl;//5136.86
}
int main() {
    solve();
    return 0;
}