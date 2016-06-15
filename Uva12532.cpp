#include <vector>
#include <iostream>
#include <cstdio>
#define LSOne(S) (S & (-S))
#define vi vector<int>

using namespace std;

class FenwickTree {
private: vi ft; // recall that vi is: typedef vector<int> vi;
public: FenwickTree(int n) { ft.assign(n + 1, 0); } // init n + 1 zeroes
int rsq(int b) { // returns RSQ(1, b)
int sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
return sum; } // note: LSOne(S) (S & (-S))
int rsq(int a, int b) { // returns RSQ(a, b)
return rsq(b) - (a == 1 ? 0 : rsq(a - 1)); }
// adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
void adjust(int k, int v) { // note: n = ft.size() - 1
for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v; }
};

int getSign(int n)
{
    if( n  < 0)
    {
        return -1;
    }
    if( n == 0)
        return 0;
    return 1;
}

int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k) != EOF)
    {
        vi numbers;
        for(int i = 0; i < n; i++)
        {
            int temp; cin >> temp;
            numbers.push_back(temp);
        }
        FenwickTree negatives(numbers.size());
        FenwickTree zeros(numbers.size());
        for(int i = 0; i < n ; i ++)
        {
            if(numbers[i] < 0)
            {
               negatives.adjust(i+1,1);
            }
            if(numbers[i] == 0)
            {
                zeros.adjust(i+1,1);
            }
        }
        for(int i = 0; i < k; i++)
        {
            char c;
            int one, two;
            cin >> c >> one >> two;
            if(c == 'C')
            {
                if(two < 0)
                {
                    if(numbers[one-1] == 0) zeros.adjust(one,-1);
                    if(!(numbers[one-1] < 0))
                    {
                        numbers[one-1] = -1;
                        negatives.adjust(one,1);
                    }
                }
                else if(two == 0)
                {
                    if(numbers[one-1] < 0) negatives.adjust(one,-1);
                    if(!(numbers[one-1] == 0))
                    {
                        numbers[one-1] = 0;
                        zeros.adjust(one,1);
                    }
                }
                else
                {
                    if(numbers[one-1] < 0) negatives.adjust(one,-1);
                    if(numbers[one-1] == 0) zeros.adjust(one,-1);
                    numbers[one-1] = 1;
                }
            }
            else
            {
                int temp = zeros.rsq(one,two);
                if(temp > 0)
                {
                    cout << "0";
                }
                else
                {
                    temp = negatives.rsq(one,two);
                    if(temp % 2 == 0)
                    {
                        cout << "+";
                    }
                    else
                    {
                        cout << "-";
                    }
                }
            }
        }
        cout <<endl;
    }
}

