#include<iostream>
using namespace std;
const int MAXN = 220;
bool r[MAXN], c[MAXN];
int n, m, a[MAXN][MAXN];

bool check()
{
    bool b = false;
    //n遍历行数
    for(int i = 1, j, s; i <= n; ++i)
    {
        s = a[i][1] ^ c[1];
        for(j = 2; j <= m; ++j)
            if((a[i][j] ^ c[j]) != s)
            {
                if(b)
                    return false;
                b = true, s = a[i][j] ^ c[j];
            }
        r[i] = (s ^ !b ? 0 : 1);
    }
    return true;
}

int main()
{
    //从系统中读入行数n和列数m
    scanf("%d %d", &n, &m);
    //从系统中读入数据
    for(int i = 1, j; i <= n; ++i)
        for(j = 1; j <= m; ++j)
            scanf("%d", &a[i][j]);
    for(int i = 1; i <= m; ++i)
        c[i] = !a[1][i];
    for(int i = 1; i <= m + 1; ++i)
    {
        //如果颠倒后check成功的话
        if(check())
        {
            printf("YES\n");
            for(int j = 1; j <= n; ++j)
                //r[j]是row的颠倒
                printf("%d", r[j]);
            printf("\n");
            //c[j]是column的颠倒
            for(int j = 1; j <= m; ++j)
                printf("%d", c[j]);
            exit(0);
        }
        c[i] = !c[i];
    }
    printf("NO\n");
}