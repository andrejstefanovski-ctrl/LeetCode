class Solution {
public:
    void merge(vector<int>& a, int low, int mid, int high) {
        vector<int> c(2000);
        int i = low;
        int j = mid + 1;
        int k = low;
        while (i <= mid && j <= high) {
            if (a[i] < a[j]) c[k++] = a[i++];
            else c[k++] = a[j++];
        }
        while (i <= mid) c[k++] = a[i++];
        while (j <= high) c[k++] = a[j++];
        for (i = low; i <= high; i++) a[i] = c[i];
    }

    void mergeSort(vector<int>& a, int low, int high) {
        if (low < high) {
            int mid = (low + high) / 2;
            mergeSort(a, low, mid);
            mergeSort(a, mid + 1, high);
            merge(a, low, mid, high);
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> x(nums1.begin(), nums1.end());
        x.insert(x.end(), nums2.begin(), nums2.end());
        mergeSort(x, 0, x.size() - 1);
        int n = x.size();
        if (n % 2 == 0)
            return (x[n/2] + x[n/2 - 1]) / 2.0;
        return x[n/2];
    }
};
