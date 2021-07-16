/* 
Find the largest continuous sequence in a array which sums to zero.
Example:
Input:  {1 ,2 ,-2 ,4 ,-4} 
*/
vector<int> Solution::lszero(vector<int> &A) {
    vector<int> ans ;
    
    if(A.size() == 0)
        return ans ;
    
    int start = -1 , end = -1 ;  
    unordered_map<int , int> Hash ;
    int sum = 0 ;
    for(int i = 0 ; i < A.size() ; i++)
    {
        sum += A[i] ;
        
	//case 1: When element itself is zero.
        if(A[i] == 0 && end - start == 0)
        {
            start = i ;
            end = i+1 ;
        }
		
	//case 2: When zero sum is encountered while considering elements from begining
        if(sum == 0)
        {
            start = 0 ;
            end = i+1 ;
        }
        
	//case 3: When already that sum is present in array that means that our required sequence is not starting from begining
        if(Hash.find(sum) == Hash.end())
        {
            Hash[sum] = i ;
        }
        else
        {
            int j = Hash[sum] ;
            if(end - start < i - j)
            {
                end = i+1 ;
                start = j+1 ;
            }
        }
    }
    
    if(start != -1 && end != -1)
    {
        for(int i = start ; i < end ; i++)
        {
            ans.push_back(A[i]) ;
        }
        return ans ;
    }
    
    return ans ;
}
