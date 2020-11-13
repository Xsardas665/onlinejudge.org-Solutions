#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<functional>
#include<deque>
// C
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cctype>
#include<cmath>
using namespace std;
typedef long long lli;
typedef unsigned long long ull;
template<class T> T max(T a, T b, T c){ return max(a, max(b, c)); }
template<class T> T min(T a, T b, T c){ return min(a, min(b, c)); }
#define MAX_N 105
#define MAX_M 1000
#define MOD 1000000007
#define INF 1e9
#define NONE -1
#define EPS 1e-6
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
const double PI = 2.0 * acos(0.0);
const int mx[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
const int my[] = { -1, 0, 1, 0, 1, -1, -1, 1 };
void flip(char &c){
	if (c == '0')
		c = '1';
	else
		c = '0';
}
int main(){
	int n, m, r, c;
	while (scanf("%d%d%d%d", &n, &m, &r, &c) == 4){
		if (n == 0 && m == 0 && r == 0 && c == 0)	break;
		char S[MAX_N][MAX_N], T[MAX_N][MAX_N];
		for (int i = 0; i < n; i++)
			scanf("%s", S + i);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				T[i][j] = '0';
		int ans = 0;
		for (int i = 0; i < n - r + 1; i++){
			for (int j = 0; j < m - c + 1; j++){
				if (S[i][j] != T[i][j]){
					for (int p = 0; p < r; p++)
						for (int q = 0; q < c; q++)
							flip(T[i + p][j + q]);
					ans++;
				}
			}
		}
		bool res = true;
		for (int i = 0; i < n&&res; i++)
			for (int j = 0; j < m&&res; j++)
				if (S[i][j] != T[i][j])
					res = false;
		if (res)
			printf("%d\n", ans);
		else
			printf("%d\n", -1);
	}
	return 0;
}
