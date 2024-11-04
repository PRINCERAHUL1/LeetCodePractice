class Solution {
public:

    bool binary_search(int s, int e, int val, vector<int> &arr)
    {
        if(e>=s)
        {
            int mid = (s+e)/2;

            if(arr[mid] == val)
                return true;
            else if(arr[mid] < val)
                return binary_search(mid+1, e, val, arr);
            else
                return binary_search(0, mid-1, val, arr);
        }

        return false;
    }

    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        for(int i=0; i<arr.size(); i++)
        {
            if(arr[i] % 2 == 0)
            {
                if(arr[i]>=0 && binary_search(0, i-1, arr[i]/2, arr))
                    return true;
                else if(arr[i]<0 && binary_search(i+1, arr.size()-1, arr[i]/2, arr))
                    return true;
            }
        }

        return false;
    }
};
