#include <bits/stdc++.h>
typedef long long LL;
const int INF=0x3f3f3f3f;
const double eps =1e-8;
const int mod=1e8;
const int maxn=1e5+10;
using namespace std;

pair<int,int> pos[15];
int dp[1<<11][11];//dp[i][j]Ŀǰ�߹���״̬�Ƕ�����i�������һ���߹��ĵ���j

int cal(int a,int b)
{
    return abs(pos[b].first-pos[a].first)+abs(pos[b].second-pos[a].second);
}

int main()
{

    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m,k;
        scanf("%d %d %d %d %d",&n,&m,&pos[0].first,&pos[0].second,&k);//pos[0]�ǳ�ʼλ��
        for(int i=1;i<=k;i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            pos[i]=make_pair(x,y);
        }
        int ans=INF;
        memset(dp,INF,sizeof(dp));
        for(int i=1;i<=k;i++)
            dp[1<<(i-1)][i]=cal(0,i);
        for(int s=0;s<(1<<k);s++)
        {
            for(int i=1;i<=k;i++) //������״̬��һ����i��Ϊ���һ�������ĵ�
            {
                if(s & (1<<(i-1)))
                {
                    for(int j=1;j<=k;j++)//������״̬��һ����j��Ϊ��j�ߵ�i
                    {
                        if(s & (1<<(j-1)))
                            dp[s][i]=min(dp[s][i],dp[s^(1<<(i-1))][j]+cal(j,i));
                    }
                }
            }
        }
        for(int i=1;i<=k;i++)
            ans=min(ans,dp[(1<<k)-1][i]+cal(i,0));
        printf("The shortest path has length %d\n",ans);
    }

    return 0;
}
