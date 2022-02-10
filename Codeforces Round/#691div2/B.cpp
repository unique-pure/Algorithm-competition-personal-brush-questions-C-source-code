/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-08-24 21:28
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n;
void solve(){
    if(n & 1){
        n /= 2;
        cout << 1LL * 2 * (n + 1) * (n + 2) << endl;
    }
    else{
        n /= 2;
        cout << (n + 1) * (n + 1) << endl; 
    }
}
int main(){	
    cin >> n;
    solve();
    return 0;
}