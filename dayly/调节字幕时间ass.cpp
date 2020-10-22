/*code_by_taisuishen*/ 
#include<bits/stdc++.h>
using namespace std;
string s,ho,mi,se,str;
int l,miao,fen,hour,ss[2][5]={12,14,15,17,18,23,25,26,28,29};
int num=-5,jin=0;
void done(int i)
{
		miao=hour=fen=jin=0;
		ho=mi=se="";
		l=s.find("Dialogue");
		if(l+1)
		{
			miao=(s[ss[i][3]]-'0')*10+s[ss[i][4]]-'0';
			fen=(s[ss[i][1]]-'0')*10+s[ss[i][2]]-'0';
			hour=s[ss[i][0]]-'0';
			
			if(miao+num>=60)
			{
				if(fen+1==60)hour+=1,fen=0;
				else fen+=1;
				miao=(miao+num)%60;
			}
			else if(miao+num>=0)miao=(miao+num);
			
			else if(miao+num<0)
			{
				miao+=60+num;
				if(fen-1<0)
				{
					if(hour-1<0)hour=-1,fen=59;
					else fen=59;
				}
				else fen-=1;
				
			}
			{
				ho+=char(hour+'0');
				mi+=char(fen/10+'0');mi+=char(fen%10+'0');
				se+=char(miao/10+'0');se+=char(miao%10+'0');

				s.replace(ss[i][0],1,ho);
				s.replace(ss[i][1],2,mi);
				s.replace(ss[i][3],2,se);
			}
			
		
		}
}
int main()
{
	freopen("a.ass","r",stdin);
	freopen("b.ass","w",stdout);
	while(getline(cin,s))
	{
		done(0);
		done(1);
		cout<<s<<endl;
	
	}
	return 0;
} 
