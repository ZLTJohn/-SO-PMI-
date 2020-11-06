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
int i,ans,tmp,cnt,len,k,j,punc_l[20]; 
char s[10005],punc[20][6];
int main()
{
	freopen("biaodian.key","r",stdin);
	while (gets(s)!=NULL)
	{
		strcpy(punc[cnt],s);
		punc_l[cnt]=strlen(s);
		cnt++;
	}
	fclose(stdin);
	freopen("onlywords.txt","r",stdin);
	freopen("nocomma.txt","w",stdout);
	tmp=0;
	while (gets(s)!=NULL)
	{
		tmp++;
		if (tmp==6968)
		{
			tmp=1;
		}
		len=strlen(s);
		fo(i,0,len-1)
		//	if (i==0||s[i-1]==' ')
			{
				fo(j,0,cnt-1) 
				{
					fo(k,0,punc_l[j]-1) if (s[i+k]!=punc[j][k]) break;
					if (k==punc_l[j]) break;
				}
				if (j<cnt)
				{
					fo(k,0,punc_l[j]-1) s[i+k]=' ';
				}
			}
		fd(i,len-1,0)
			if (s[i]==' ') 
			{
				fo(j,0,cnt-1) 
				{
					fo(k,0,punc_l[j]-1) if (s[i-punc_l[j]+k]!=punc[j][k]) break;
					if (k==punc_l[j]) break;
				}
				if (j<cnt)
				{
					fo(k,0,punc_l[j]-1) s[i-punc_l[j]+k]=' ';
				}
			}
		printf("%s\n",s);
		fo(i,0,len-1) s[i]=0;
	}
}
