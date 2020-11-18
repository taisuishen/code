/*code_by_taisuishen*/ 
#include<bits/stdc++.h>
using namespace std;
string s,ho,mi,se,str,hm;
int l,miao,fen,hour,hmiao,cc,ss[2][7]={12,14,15,17,18,20,21,23,25,26,28,29,31,32};
float num,jin=0,kk;
void done(int i)
{
		miao=hour=fen=jin=hmiao;
		ho=mi=se=hm="";
		l=s.find("Dialogue");
		num=(int)num;
	
		if(l+1)
		{
		
			hmiao=(s[ss[i][5]]-'0')*10+s[ss[i][6]]-'0';
			miao=(s[ss[i][3]]-'0')*10+s[ss[i][4]]-'0';
			fen=(s[ss[i][1]]-'0')*10+s[ss[i][2]]-'0';
			hour=s[ss[i][0]]-'0';
	//	cout<<hour<<":"<<fen<<":"<<miao<<":"<<hmiao<<endl;
	
			if(hmiao+cc>=100)
			miao++;
			else if(hmiao+cc<0)
			{
				if(miao-1<0)
				{
					miao=59;
						if(fen-1<0)
						{
						if(hour-1<0)hour=-1,fen=59;
						else fen=59;
						}
						else fen-=1;
				}
				else
				{
					miao-=1;
				}
				
			}
			cout<<cc<<endl;
			if(hmiao+cc<0)hmiao+=(int)(100+cc)%100;
			else hmiao+=cc;
		//cout<<miao<<endl; 
			if(miao+num>=60)
			{
				if(fen+1==60)hour+=1,fen=0;
				else fen+=1;
				miao=int(miao+num)%60;
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
				hm+=char(hmiao/10+'0');hm+=char(hmiao%10+'0');
				ho+=char(hour+'0');
				mi+=char(fen/10+'0');mi+=char(fen%10+'0');
				se+=char(miao/10+'0');se+=char(miao%10+'0');
				
				s.replace(ss[i][0],1,ho);
				s.replace(ss[i][1],2,mi);
				s.replace(ss[i][3],2,se);
				s.replace(ss[i][5],2,hm);
			}
			
		
		}
}
int main()
{
	cin>>num;
	cc=((num-int(num))*100);
	freopen("a.ass","r",stdin);
	freopen("b.ass","w",stdout);
	while(getline(cin,s))
	{
		done(0);done(1);
		cout<<s<<endl;
	
	}
	return 0;
} 
