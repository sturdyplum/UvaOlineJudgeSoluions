#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int num;
    while(scanf("%d",&num) != EOF)
    {
        int count = 0;
        for(int i = num+1; i <= num*2; i ++)
        {
            //cout << i << endl;
            if((i*num)%(i-num)==0)
            {
                int ans = i*num / (i-num);
               // cout << "     " << ans << endl;
                count++;
            }

        }
        printf("%d\n",count);
        for(int i = num+1; i <= num*2; i ++)
        {
            //cout << i << endl;
            if((i*num)%(i-num)==0)
            {
                int ans = i*num / (i-num);
               // cout << "     " << ans << endl;
                printf("1/%d = 1/%d + 1/%d\n",num,ans,i);
            }

        }
    }
    return 0;
}
