/*code_by_taisuishen*/ 
#include<bits/stdc++.h>
using namespace std;
string s,ho,mi,se,str;
int l,miao,fen,hour,ss[2][5]={1,3,4,6,7,18,20,21,23,24};
int num=-2,jin=0;//修改Num值改变时间 
void done(int i)
{
		miao=hour=fen=jin=0;
		ho=mi=se="";
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
	int si=0;
	freopen("a.srt","r",stdin);
	freopen("b.srt","w",stdout);
	while(getline(cin,s))
	{
		if(si)
		{
		done(0),done(1);
		si=0;
		}
		if(s.size()==1) 
		si=1;
		
		cout<<s<<endl;
	
	}
	return 0;
} 
