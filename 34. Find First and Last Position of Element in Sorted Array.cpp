class Solution {
public:

int lowerBound(vector<int> &arr, int x, int n) {
	int l = 0,r = n-1;
	int ans = n;
	while(l<=r)
	{
		int mid = l + (r-l)/2;

		if(arr[mid]>=x)
		{
			ans = mid;
			r = mid-1;
		}
		else l = mid + 1;
		
	}

	return ans;
}

int upperBound(vector<int> &arr, int x, int n){
	int l = 0, r = n-1;
	int ans = n;

	while(l<=r)
	{
		int mid = l + (r-l)/2;

		if(x < arr[mid])
		{
			ans = mid;
			r = mid-1;
		}
		else l = mid+1;
	}
	return ans;
}

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int l = lowerBound(nums,target,n);
        int r = upperBound(nums,target,n) - 1;

        vector<int> ans;

        if((l==n)|| (nums[l]!=target)) return {-1,-1};
        else ans.push_back(l);

        if((nums[r]!= target)) ans.push_back(-1);
        else ans.push_back(r);

        return ans;

    }
};
