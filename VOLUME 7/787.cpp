#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;
int a[110];
class BigInteger {

public:
 int num[150];
 int len;

 BigInteger(long long value, bool sign) {
  len = 0;
  while (value>0)
  {
   num[++len] = value%10000;
   value/=10000;
  }
  num[0] = sign;
 }

 BigInteger () {}

 BigInteger multi(int x) {
  int nho = 0;
  int xx = x; x = abs(x);
  BigInteger result(0,1);
  for (int i=1; i<=this->len; i++)
  {
   int tmp = this->num[i]*x+nho;
   result.num[++result.len] = tmp%10000;
   nho = tmp/10000;
  }
  while (nho>0)
  {
   result.num[++result.len] = nho%10000;
   nho/=10000;
  }
  int sign;
  if (this->num[0]==0) sign = -1;
  else sign = 1;
  if (sign*xx<0) result.num[0] = 0;
  else result.num[0] = 1;
  while (result.num[result.len]==0 && result.len>1) result.len--;
  return(result);
 }

 bool cmp(BigInteger a) {
  if (this->num[0]<a.num[0]) return(true);
  if (this->num[0]>a.num[0]) return(false);
  if (this->len<a.len) return(true);
  if (this->len>a.len) return(false);
  if (this->num[0]==a.num[0] && this->len==a.len)
   for (int i=len; i>=1; i--)
   {
    if (this->num[i]<a.num[i]) return(true);
    if (this->num[i]>a.num[i]) return(false);
   }
  return(false);
 }

 void print() {
  if (num[0]==0) cout << "-";
  if (len==0) cout << 0;
  for (int i=len; i>=1; i--)
   if (num[i]<1000 && num[i]>=100 && i!=len) cout << "0" << num[i];
   else if (num[i]<100 && num[i]>=10 && i!=len) cout << "00" << num[i];
   else if (num[i]<10 && num[i]>0 && i!=len) cout << "000" << num[i];
   else if (num[i]==0 && i!=len) cout << "0000";
   else cout << num[i];
 }
};
int main() {
 while (!cin.eof())
 {
  int n = 0;
  int value;
  cin >> value;
  if (cin.eof()) break;
  while (value!=-999999)
  {
   a[++n] = value;
   cin >> value;
  }
  BigInteger result(abs(a[1]),a[1]==abs(a[1]));
  for (int i=1; i<=n-1; i++)
  {
   BigInteger cur(abs(a[i]),a[i]==abs(a[i]));
   if (result.cmp(cur)) result = cur;
   for (int j=i+1; j<=n; j++)
   {
    cur = cur.multi(a[j]);
    if (result.cmp(cur)) result = cur;
   }
  }
  result.print();
  cout << endl;
 }
 return 0;
}
