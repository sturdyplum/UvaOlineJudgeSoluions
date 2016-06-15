#include <iostream>
#include <vector>
#define vi vector<int>


using namespace std;



class SegmentTree { // the segment tree is stored like a heap array
     private: vi st, A, lazy; // recall that vi is: typedef vector<int> vi;
     int n;
     int left (int p) { return p << 1; } // same as binary heap operations
     int right(int p) { return (p << 1) + 1; }
     void build(int p, int L, int R) { // O(n)
         if (L == R) // as L == R, either one is fine
             st[p] = A[L]; // store the index
         else { // recursively compute the values
             build(left(p) , L , (L + R) / 2);
             build(right(p), (L + R) / 2 + 1, R );
             int p1 = st[left(p)], p2 = st[right(p)];
             st[p] = p1 + p2;
     } }
     int rmq(int p, int L, int R, int i, int j) { // O(log n)
         if(lazy[p] != 0) { // This node needs to be updated
            if(lazy[p] == -1)
            {
                st[p] = 0;
                if(L != R)
                {
                    lazy[p*2] = -1;
                    lazy[p*2+1] = -1;
                }
                lazy[p] = 0;
            }
            else if(lazy[p] == 1)
            {
                st[p] = R-L+1;
                if(L != R)
                {
                    lazy[p*2] = 1;
                    lazy[p*2+1] = 1;
                }
                lazy[p] = 0;
            }
            else if(lazy[p] == 2)
            {
                int temp = st[p];
                st[p] = R-L+1 - temp;
                if(L != R)
                    {
                        if(lazy[p*2] == 0)
                    {
                        lazy[p*2] = 2;
                    }
                    else if(lazy[p*2] == 1)
                    {
                        lazy[p*2] = -1;
                    }
                    else if(lazy[p*2] == -1)
                    {
                        lazy[p*2] = 1;
                    }
                    else
                    {
                        lazy[p*2] = 0;
                    }

                    if(lazy[p*2+1] == 0)
                    {
                        lazy[p*2+1] = 2;
                    }
                        else if(lazy[p*2+1] == 1)
                    {
                    lazy[p*2+1] = -1;
                    }
                    else if(lazy[p*2+1] == -1)
                    {
                        lazy[p*2+1] = 1;
                    }
                    else
                    {
                        lazy[p*2+1] = 0;
                    }
                }
                lazy[p] = 0;
            }
          }
         if (i > R || j < L) return -1; // current segment outside query range
         if (L >= i && R <= j) return st[p]; // inside query range
         // compute the min position in the left and right part of the interval
         int p1 = rmq(left(p) , L , (L+R) / 2, i, j);
         int p2 = rmq(right(p), (L+R) / 2 + 1, R , i, j);
         if (p1 == -1) return p2; // if we try to access segment outside query
         if (p2 == -1) return p1; // same as above
         return p1 + p2; // as in build routine
     }
    void updateRange(int node, int start, int end, int l, int r, int val)
     {
        if(lazy[node] != 0)
        {
            // This node needs to be updated
            if(lazy[node] == -1)
            {
                st[node] = 0;
                if(start != end)
                {
                    lazy[node*2] = -1;// Mark child as lazy
                    lazy[node*2+1] = -1; // Mark child as lazy
                }
                lazy[node] = 0;
            }
            else if(lazy[node] == 1)
            {
                st[node] = end-start+1;
                if(start != end)
                {
                    lazy[node*2] = 1;
                    lazy[node*2+1] = 1;
                }
                lazy[node] = 0;
            }
            else if(lazy[node] == 2)
            {

                int temp = st[node];
                st[node] = end-start+1 - temp;
                if(start != end)
                    {
                        if(lazy[node*2] == 0)
                    {
                        lazy[node*2] = 2;
                    }
                    else if(lazy[node*2] == 1)
                    {
                        lazy[node*2] = -1;
                    }
                    else if(lazy[node*2] == -1)
                    {
                        lazy[node*2] = 1;
                    }
                    else
                    {
                        lazy[node*2] = 0;
                    }

                    if(lazy[node*2+1] == 0)
                    {
                        lazy[node*2+1] = 2;
                    }
                    else if(lazy[node*2+1] == 1)
                    {
                        lazy[node*2+1] = -1;
                    }
                    else if(lazy[node*2+1] == -1)
                    {
                        lazy[node*2+1] = 1;
                    }
                    else
                    {
                        lazy[node*2+1] = 0;
                    }
                }
                lazy[node] = 0;
            }
        }
    if(start > end or start > r or end < l) // Current segment is not within range [l, r]
        return;
    if(start >= l and end <= r)
    {
        // Segment is fully within range
        if(val == -1)
        {
            st[node] = 0;
            if(start != end)
            {
                lazy[node*2] = -1;
                lazy[node*2+1] = -1;
            }
            return;
        }
        if(val == 1)
        {
            st[node] = end-start+1;
            if(start != end)
            {
                lazy[node*2] = 1;
                lazy[node*2+1] = 1;
            }
            return;
        }
        if(val == 2)
        {
            int temp = st[node];
            st[node] = end-start+1 -temp;
            if(start != end)
            {
                if(lazy[node*2] == 0)
                {
                    lazy[node*2] = 2;
                }
                else if(lazy[node*2] == 1)
                {
                    lazy[node*2] = -1;
                }
                else if(lazy[node*2] == -1)
                {
                    lazy[node*2] = 1;
                }
                else
                {
                    lazy[node*2] = 0;
                }

                if(lazy[node*2+1] == 0)
                {
                    lazy[node*2+1] = 2;
                }
                else if(lazy[node*2+1] == 1)
                {
                    lazy[node*2+1] = -1;
                }
                else if(lazy[node*2+1] == -1)
                {
                    lazy[node*2+1] = 1;
                }
                else
                {
                    lazy[node*2+1] = 0;
                }
            }
            return;
        }
    }
    int mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val); // Updating left child
    updateRange(node*2 + 1, mid + 1, end, l, r, val); // Updating right child
    st[node] = st[node*2] + st[node*2+1]; // Updating root with max value
}
     public:
         SegmentTree(const vi &_A) {
             A = _A; n = (int)A.size(); // copy content for local usage
             st.assign(4 * n, 0); // create large enough vector of zeroes
             lazy.assign(4*n,0);
             build(1, 0, n - 1); // recursive build
         }
         int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); } // overloading
         void updateRange(int i, int j, int val) { updateRange(1,0,n-1,i,j,val);}
};


int main()
{
    int t; cin >> t;
    int cases = 1;

    while(t--)
    {
        cout << "Case " << cases << ":\n";
        cases++;
        int questions = 1;
        int m; cin >> m;
        string pirates = "";
        for(int i = 0; i < m; i ++)
        {
            int T; cin >> T;
            string line; cin >> line;
            string temp = line;
            for(int i = 1; i < T; i ++)
            {
                line += temp;
            }
            pirates+=line;
        }
        vi pirateVector;
        for(char c: pirates)
        {
            if(c == '1') pirateVector.push_back(1);
            else pirateVector.push_back(0);
        }
        SegmentTree st(pirateVector);
        int c; cin >> c;
        for(int i = 0; i < c; i++)
        {
            char a; cin >> a;
            int num1,num2; cin >> num1 >> num2;

            if(a == 'F')//turn to 1
            {


                st.updateRange(num1,num2,1);

            }
            else if(a == 'E')//turn to 0
            {

                st.updateRange(num1,num2,-1);

            }
            else if(a == 'I')//inverse
            {

               // for(int z = 0; z < pirateVector.size(); z++)
                {
                   // cout << st.rmq(z,z);
                }
               // cout << endl;
                st.updateRange(num1,num2,2);
               // for(int z = 0; z < pirateVector.size(); z++)
                {
                  //  cout << st.rmq(z,z);
                }
             //   cout << endl;

            }
            else//query
            {
                int ans = st.rmq(num1, num2);
                cout <<"Q" << questions<<": "<< ans << endl;
                questions++;
            }
        }
    }
    return 0;
}
