/******************** Easy ********************/

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
 * Iterative Way:
 * Time Complexity: O(n)
 */
int maxProfit(vector<int>& prices) 
{
    int profit = 0;
    for(int i = 1; i < prices.size(); i++)
    {
        if(prices[i] > prices[i-1])
            profit += (prices[i] - prices[i-1]);
    }
    return profit;
}





/* LeetCode 1480 Running Sum of 1D Array
 * Iterative Way:
 * Time Complexity: O(n)
 * Space Compleixty: O(1)
 */
vector<int> runningSum(vector<int>& nums) 
{        
    for(int i = 1; i < nums.size(); i++)
	{
        nums[i] = nums[i-1] + nums[i];
    }
    return nums;
}





/* LeetCode 724 Find Pivot Index
 * Iterative Way:
 * Time Complexity: O(n)
 */
int pivotIndex(vector<int>& nums) 
{
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
int majorityElement(vector<int>& nums) 
{
    int count = 0;
    int candidate = 0;
    
    for(int num : nums) 
	{
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
int fib(int n) 
{
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    return fib(n-1)+fib(n-2);
}





/* LeetCode 977 Squares of a Sorted Array
 * Iterative Way;
 * Time Complexity: O(nlog(n));
 */
vector<int> sortedSquares(vector<int>& nums) 
{
    int n = nums.size();
    vector<int> sqr;
    int sqrNum;
    for(int i = 0; i < n; i++) 
	{
        sqrNum = nums[i]*nums[i];
        sqr.push_back(sqrNum);
    }
    sort(sqr.begin(), sqr.end());
    return sqr;
}





/* LeetCode 118 Pascal's Triangle */
/* Method 1: */
vector<vector<int>> generate(int numRows) { 
    vector<vector<int>> r(numRows); // create 'n' dynamic vectors

    for(int i = 0; i < numRows; i++) {
        // for every row, the number of columns always equal to number of rows
        r[i].resize(i+1); // empty vector is resized to a size i+1
        r[i][0] = r[i][i] = 1; // every first and last element is '1'
        // Linearly traverse from 1st column to 2nd last column
        for(int j = 1; j < i; j++)
            r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
    }
    return r;
}

// Method 2:
vector<vector<int>> generate(int numRows) {
    
    vector<vector<int>> arr;
    vector<int> a;
    for(int i = 0; i < numRows; i++) {
        for(int j = 0; j < i+1; j++) {
            if(j == 0 || j == i) 
                a.push_back(1);
            else 
                a.push_back(arr[i-1][j-1] + arr[i-1][j]);
        }
        arr.push_back(a);
        a.clear();
    }
    return arr;
}





/* LeetCode 26 Remove Duplicates from Sorted Array
 * Iterative Way:
 * Time Complexity: O(n)
 */
int removeDuplicates(vector<int>& nums) {
    int i = !nums.empty();
    for(int n : nums)
        if(n > nums[i-1])
            nums[i++] = n;
    return i;
}


/******************** Medium ********************/


/* LeetCode 56 Merge Intervals
 * Iterative Way:
 * Time Complexity: O(n)
 */
vector<vector<int>> merge(vector<vector<int>>& intervals) 
{   
    vector<vector<int>> mergedIntervals; 
    
    // Edge Case: Not give any intervals
    if(intervals.size() == 0) 
	{
        return mergedIntervals;
    }
    
    // If interval given then sort
    sort(intervals.begin(), intervals.end());
    
    // tempInterval contain the first interval
    vector<int> tempInterval = intervals[0];
    
    // Traverse through the given interval
    for(auto it : intervals) 
	{
        // Checking for merging
        if(it[0] <= tempInterval[1]) 
		{
            tempInterval[1] = max(it[1], tempInterval[1]); // merging
        }
        else 
		{
            mergedIntervals.push_back(tempInterval); // not merging
            tempInterval = it;
        }
    }
    // Push the last interval into mergedIntervals
    mergedIntervals.push_back(tempInterval);
    return mergedIntervals;
}





/* LeetCode 15 3Sum
 * Time Compleixty: O(n^2)
 * Space Complexity: O(1)
 */
vector<vector<int>> threeSum(vector<int>& nums) 
{	
	vector<vector<int>> ans;
	sort(nums.begin(), nums.end());
	for(int i = 0; i < nums.size(); i++)
	{
	    int a = nums[i]; // a+b+c=0 | b+c=-a
	    int t = -a;
	    int s = i+1, e = nums.size()-1;
	    while(s < e) {
	        if(nums[s]+nums[e] == t) 
			{
	            ans.push_back({nums[i],nums[s],nums[e]}); // inserting vector inside a vector
	            while(s < e && nums[s] == nums[s+1]) s++;
	            while(s < e && nums[e] == nums[e-1]) e--;
	            s++;
	            e--;
	        }
	        else if(nums[s]+nums[e] > t) 
			{
	            e--;
	        }
	        else 
			{
	            s++;
	        }
	    }
	    while(i+1 < nums.size() && nums[i+1] == nums[i]) i++; // skip the repeted numbers
	}
	return ans;
}





/* LeetCode 238 Product of Array Except Self
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
// Using Prefix Sum Algorithm
// Way 1: Using double loops
vector<int> productExceptSelf(vector<int>& nums) {
    int p = 1;
    int n = nums.size();
    vector<int> ans(n,1);
    for(int i = 0; i < n; i++)
    {
        ans[i] = p;
        p = p*nums[i];
    }
    p = 1;
    for(int i = n - 1; i >= 0; i--)
    {
        ans[i] *= p;
        p = p*nums[i];
    }
    return ans;
}

// Way 2: Using single-pass TC: O(n) | SC: O(1)
vector<int> productExceptSelf(vector<int>& nums) {
    int left = 1, right = 1;
    int n = nums.size();
    vector<int> ans(n,1);
    for(int i = 0; i < n; i++)
    {
        ans[i] *= left;
        left = left * nums[i];
        int j = n - i - 1;
        ans[j] *= right;
        right = right * nums[j];
    }
    return ans;
}





/* LeetCode 380 Insert Delete GetRandom O(1) */
class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> m;
public:
    RandomizedSet() {
        
    }
    
    // Inserts a value to the set. Returns true if the set did not already contain the specified element.
    bool insert(int val) {
        if(m.find(val) != m.end()) return false;
        nums.emplace_back(val);
        m[val] = nums.size() - 1;
        return true;
    }
    
    // Removes a value from the set. Returns true if the set contained the specified element
    bool remove(int val) {
        if(m.find(val) == m.end()) return false;
        int last = nums.back();
        m[last] = m[val];
        nums[m[val]] = last;
        nums.pop_back();
        m.erase(val);
        return true;
    }
    
    // Get a random element from the set.
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */





/* LeetCode Subarray Sum Equals K */





/*
 * LeetCode: 31. Next Permutation
 * TC: O(N)
 * SC: O(1)
*/
void nextPermutation(vector<int>& nums) {
    int n = nums.size(), k, l; 
    // Linearly traverse to the second last element and try to find break point
    for(k = n - 2; k >= 0; k--) { 
        if(nums[k] < nums[k+1]) {
            break;
        }
    }
    
    // If no break point then reverse remaining elements
    if(k < 0)
        reverse(nums.begin(), nums.end());
    else { // If there is a break point then again linearly traverse from the last
        for(l = n - 1; l > k; l--) {
            if(nums[l] > nums[k]) {
                break;
            }
        }
        swap(nums[k], nums[l]); // also write own code for swap
        reverse(nums.begin() + k + 1, nums.end()); // also write own code for reverse
    }
}
