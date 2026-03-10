class Solution {
  public:
    int minTime(vector<int>& arr, int k) {
        
        long long low = *max_element(arr.begin(), arr.end());
        long long high = accumulate(arr.begin(), arr.end(), 0LL);
        long long ans = high;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            
            long long currSum = 0;
            int painters = 1;
            
            
            for (int board : arr) {
                if (currSum + board <= mid) {
                    currSum += board;
                } else {
                    painters++;
                    currSum = board;
                }
            }
            
            if (painters <= k) {
                ans = mid;
                high = mid - 1;   
            } else {
                low = mid + 1;    
            }
        }
        
        return (int)ans;
    }
};
