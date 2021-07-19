//Given an even number ( greater than 2 ), return two prime numbers whose sum will be equal to given number.

//NOTE A solution will always exist. read Goldbach’s  conjecture

//Example: Input : 4
//Output: 2 + 2 = 4

//If there are more than one solutions possible, return the lexicographically smaller solution.
//If [a, b] is one solution with a <= b, and [c,d] is another solution with c <= d, then [a, b] < [c, d] 
//If a < c OR a==c AND b < d. 

bool prime(int n)
{
    if(n<2)
        return false;
    if(n<4)
        return true;
    if(n%2==0)
        return false;
    int i=3;
    while(i<=sqrt(n))
    {
        if(n%i==0)
            return false;
        i=i+2;
    }
    return true;
    
}
vector<int> Solution::primesum(int A) {
    int i=2;
    vector<int> ans;
    while(i<A)
    {
        bool flag=prime(i);
        if(flag)
        {
            flag=prime(A-i);
            if(flag)
            {
                ans.push_back(i);
                ans.push_back(A-i);
                return ans;
            }
        }
        i++;
    }
}
