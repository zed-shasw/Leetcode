class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        if(arr[0] <= arr[n-1]) return arr[0];
        int start = 0, end = n-1, key = arr[n-1];
        while(start<end)
        {
            int mid = ((start+end)>>1);
            if(arr[mid] > key) start = mid+1;
            else end = mid;
        }
        return arr[end];
    }
};