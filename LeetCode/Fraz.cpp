/* LeetCode 1. Two Sum
 * Iterative Way:
 * Time Complexity: O(n^2)
 */
vector<int> twoSum(vector<int>& nums, int target) 
{
    vector<int> a;
    
    for(int i=0;i<nums.size()-1;i++)
	{
    	for(int j=i+1;j<nums.size();++j)
		{
            if(nums[i]+nums[j] == target)
			{
                a.push_back(i);
                a.push_back(j);
            }
        }
    }
    return a;
}





/* LeetCode 121. Best Time to Buy and Sell Stock
 * Iterative Way:
 * Time Complexity: O(n)
 */
int maxProfit(vector<int>& prices) 
{  
    int low = INT_MAX, high = 0;
    for(int i = 0; i < prices.size(); i++) 
	{
        low = min(low, prices[i]);
        high = max(high, prices[i]-low);
    }
    return high;
}





/* LeetCode 88. Merge Sorted Array
 * Iterative Way:
 * Time Complexity: O(n)
 */
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
    int a = m-1, b = n-1, i = m+n-1;
    while(b >= 0) 
	{
        if(a >= 0 && nums1[a] > nums2[b])
            nums1[i--] = nums1[a--];
        else
            nums1[i--] = nums2[b--];
    }
}





/* LeetCode 283. Move Zeros
 * Iterative Way:
 * Time Complexity: O(n)
 */
void moveZeroes(vector<int>& nums) 
{
    int j = 0; 
    for(int i = 0; i < nums.size(); i++) 
	{
        if(nums[i] != 0)
            nums[j++] = nums[i];
    }
    for(; j < nums.size(); j++)
        nums[j] = 0;
}





/* LeetCode 122. Best Time to Buy and Sell Stock II
 */





/* LeetCode 1480 Running Sum of 1D Array
 * Iterative Way:
 * Time Complexity: O(n)
 * Space Compleixty: O(1)
 */
vector<int> runningSum(vector<int>& nums) 
{        
    for(int i = 1; i < nums.size(); i++){
        nums[i] = nums[i-1] + nums[i];
    }
    return nums;
}





/* LeetCode 724 Find Pivot Index
 * Iterative Way:
 * Time Complexity: O(n)
 */
int pivotIndex(vector<int>& nums) {
    int totalSum = 0;
    for(int num : nums)
        totalSum += num;
    
    int leftSum = 0;
    for(int i = 0; i < nums.size(); leftSum+=nums[i++])
        if(leftSum * 2 == totalSum - nums[i])
            return i;
    return -1;
}





/* LeetCode 169 Majority Element
 * Iterative Way:
 * Time Complexity: O(n)
 */
int majorityElement(vector<int>& nums) {
    int count = 0;
    int candidate = 0;
    
    for(int num : nums) {
        if(count == 0)
            candidate = num;
        
        if(num == candidate)
            count += 1;
        
        else 
            count -= 1;
    }
    return candidate;
}





/* LeetCode 509 Fibonacci Number
 * Recursive Way:
 * Time Complexity: O(2^n)
 */
int fib(int n) {
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    return fib(n-1)+fib(n-2);
}
