#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<queue>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<map>
#include<set>

using namespace std;

int main(){

    int a[3000],a2[3000],n;
    while(cin >> n){
        for(int i = 0; i < n; i++)cin >> a[i];
        int j = 1;
        for(int i = 1; i < n;i++){
            a2[j++] = abs(a[i]-a[i-1]);
        }
        sort(a2+1,a2+j);
        int f=1;
        for(int i = 1; i < j; i++){
            if(a2[i] != i){
               f=0;
                break;
            }
        }
        if(f==1)cout << "Jolly" << endl;
        else cout << "Not jolly" << endl;
    }
    return 0;
}
