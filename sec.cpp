#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define fo(i,j,k) for(i=j;i<=k;i++)
#define fd(i,j,k) for(i=j;i>=k;i--)
#define cmax(a,b) (a=(a>b)?a:b)
#define cmin(a,b) (a=(a<b)?a:b)
typedef long long ll;
typedef double db;
const int N=1e6+5,mo=1e9+7;
const db EEE=2.71828182845904523536028747;
int nxt[N],n,A,k,a[N],i,ans,tmp; 
char s[505];
int main()
{
	freopen("processed.txt","r",stdin);
	freopen("onlywords.txt","w",stdout);
	while (gets(s)!=NULL)
	{
		int len=strlen(s);
		fo(i,0,len-1)
			if (s[i]!=' '&&(unsigned char)s[i]<128)
				s[i]=' ';
		printf("%s\n",s);
		fo(i,0,len-1) s[i]=0;
	}
}
