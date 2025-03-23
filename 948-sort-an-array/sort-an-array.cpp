class Solution {
public:
    void merge(vector<int>& arr, int l, int r, int m)
    {
        vector<int> temp;
        int i = l, j = m + 1;
        while (i <= m && j <= r)
        {
            temp.push_back((arr[i] < arr[j]) ? arr[i++] : arr[j++]);
        }
        while (i <= m)
        {
            temp.push_back(arr[i++]);
        }
        while (j <= r)
        {
            temp.push_back(arr[j++]);
        }
        for (int a = 0; a < temp.size(); a++)
        {
            arr[l + a] = temp[a];
        }
    }

    void mergeSort(vector<int>& arr, int l, int r)
    {
        if (l >= r)
        {
            return;
        }
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, r, mid);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
