#include <iostream>
#include <vector>
#define vi vector<int>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<string> names;
        vector<vi > prices;
        while(n--)
        {
            string name;
            int low, high;
            cin >> name >> low >> high;
            names.push_back(name);
            vi temp;
            temp.push_back(low);
            temp.push_back(high);
            prices.push_back(temp);
        }
        cin >> n;
        for(int a = 0; a < n; a ++)
        {
            int price;
            int C = 0;
            int index = -1;
            cin >> price;
            for(int i = 0; i < prices.size(); i++)
            {
                if(price >= prices[i][0] and price <= prices[i][1])
                {
                    index = i;
                    C++;
                    if(C > 1)
                    {
                        cout << "UNDETERMINED\n";
                        break;
                    }
                }
            }
            if(C == 1)
            {
                cout << names[index] << endl;
            }
            else if (C== 0){
                 cout << "UNDETERMINED\n";
            }
        }
        if(t)
        {
            cout << endl;
        }

    }
    return 0;
}
