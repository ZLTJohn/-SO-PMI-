#include<bits/stdc++.h>
using namespace std;
#define fo(i,j,k) for(i=j;i<=k;i++)
#define fd(i,j,k) for(i=j;i>=k;i--)
#define cmax(a,b) (a=(a>b)?a:b)
#define cmin(a,b) (a=(a<b)?a:b)
typedef long long ll;
typedef double db;
const int N=1e6+5,mo=1e9+7;
const db EEE=2.71828182845904523536028747;
set<string> tr,pstrs,nstrs;
multiset<string>trtemp;
map<pair<string,string>,int> union_p;
map<string,int> single_p;
string str,str1;
struct rec
{
	string str;
	double so_PMI;
};
bool operator<(rec a,rec b)
{
	return a.so_PMI<b.so_PMI;
}
vector<rec> final;
char s[10005],s1[10005];
int i,j,len,freq_whole,f12,f1,f2;
int derive(char *s,int i)
{
	while (s[i]!=' '&&s[i]!='\n'&&s[i]!=0) i++;
	return i;
}
void filter_EN();
void filter_CH_punc();
void load_seed();
void load_data();
void calc_PMI();
int main()
{
//	system("python divide_words.py");
	filter_EN();
	filter_CH_punc();
	load_seed();
	load_data();
	calc_PMI();
	freopen("result.txt","w",stdout);
	for(auto prt:final) 
	if (pstrs.find(prt.str)==pstrs.end()&&nstrs.find(prt.str)==nstrs.end())
	{
		cout<<prt.str<<' '<<prt.so_PMI<<'\n';
	}
}

void filter_EN()
{
	int i; 
	char s[10005];
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
void filter_CH_punc()
{
	int i,cnt,len,k,j,punc_l[20]; 
	char s[10005],punc[20][6];
	freopen("biaodian.key","r",stdin);
	cnt=0;
	while (gets(s)!=NULL)
	{
		strcpy(punc[cnt],s);
		punc_l[cnt]=strlen(s);
		cnt++;
	}
	freopen("onlywords.txt","r",stdin);
	freopen("nocomma.txt","w",stdout);
	while (gets(s)!=NULL)
	{
		len=strlen(s);
		fo(i,0,len-1)
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
		printf("%s\n",s);
		fo(i,0,len-1) s[i]=0;
	}
}
void load_seed()
{	
	freopen("pseed.txt","r",stdin);
	while (gets(s)!=NULL)
	{
		len=strlen(s);
		fo(i,0,len-1)
		if (s[i]!=' ')
		{
			j=derive(s,i)-1;
			strncpy(s1,s+i,j-i+1);
			s1[j-i+1]=0;
			str=s1;
			pstrs.insert(str);
			i=j;
			//cout<<str<<'\n';
		}
		fo(i,0,len-1) s[i]=0;
	}
	
	freopen("nseed.txt","r",stdin);
	while (gets(s)!=NULL)
	{
		len=strlen(s);
		fo(i,0,len-1)
		if (s[i]!=' ')
		{
			j=derive(s,i)-1;
			strncpy(s1,s+i,j-i+1);
			s1[j-i+1]=0;
			str=s1;
			nstrs.insert(str);
			i=j;
			//cout<<str<<'\n';
		}
		fo(i,0,len-1) s[i]=0;
	}
	
}
void load_data()
{
	 
	freq_whole=0;
	freopen("nocomma.txt","r",stdin);
	while (gets(s)!=NULL)
	{
		len=strlen(s);
		trtemp.clear();
		
		fo(i,0,len-1)
		if (s[i]!=' ')
		{
			j=derive(s,i)-1;
			strncpy(s1,s+i,j-i+1);
			s1[j-i+1]=0;
			str=s1;
			tr.insert(str);
			trtemp.insert(str);
			i=j;
			freq_whole++;
			single_p[str]++;
		//	cout<<str<<' ';
		}
		for(auto str:trtemp)
		{
			for(auto ps:pstrs)
				if (trtemp.find(ps)!=trtemp.end())
					union_p[make_pair(str,ps)]++;
			for(auto ns:nstrs)
				if (trtemp.find(ns)!=trtemp.end())
					union_p[make_pair(str,ns)]++;
		}
		fo(i,0,len-1) s[i]=0;
	}
}
void calc_PMI()
{
	for (auto tar_str:tr)
	{
		db psum=0,nsum=0,val=0;
	//	if (single_p[tar_str]<10) continue;
		for (auto ps:pstrs)
		{
			f12=union_p[make_pair(tar_str,ps)];
			f1=single_p[tar_str];
			f2=single_p[ps];
			val=(db)(1ll*f12*freq_whole)/(db)(1ll*f1*f2);
			if (val!=0) psum+=log(val)/log(2);
		}
		for (auto ns:nstrs)
		{
			f12=union_p[make_pair(tar_str,ns)];
			f1=single_p[tar_str];
			f2=single_p[ns];
			val=(db)(1ll*f12*freq_whole)/(db)(1ll*f1*f2);
			if (val!=0) nsum+=log(val)/log(2);
		}
		rec tmp;
		tmp.so_PMI=psum-nsum;
		tmp.str=tar_str;
		final.push_back(tmp);
	}
	sort(final.begin(),final.end());
}
