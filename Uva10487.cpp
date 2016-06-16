#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n; cin >> n;
    int Case = 1;
    while(n)
    {
        vector<int> numbers;
        for(int i = 0; i < n; i++)
        {
            int temp;cin >> temp;
            numbers.push_back(temp);
        }
        sort(numbers.begin(),numbers.end());
        int num; cin >> num;
        cout << "Case " <<Case<<":\n";
        Case++;
        for(int i = 0; i < num; i ++)
        {
            int closest = 1000000000;
            int sum = 0;
            int goal; cin >> goal;
            for(int a = 0; a < numbers.size(); a++)
            {
                for(int z = a+1; z < numbers.size(); z++)
                {
                     int temp = numbers[z] + numbers[a];
                     if(abs(temp-goal) < closest) {
                            closest = abs(temp-goal);
                            sum = temp;
                     }
                }
            }
            cout << "Closest sum to " << goal << " is " <<sum<<"." << endl;
        }
        cin >> n;
    }
    return 0;
}
