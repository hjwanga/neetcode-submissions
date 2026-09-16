class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int m = A.size();
        int n = B.size();
        if (m > n) {
            return findMedianSortedArrays(B, A);
        }
        int half = (m+n)/2;
        // 表示從A裡面挑0~m個
        int l = 0;
        int r = m;
        while (l <= r) {
            int mid = l + (r-l)/2;
            int k = half - mid;
            int A_left_back = mid-1 >= 0 ? A[mid-1] : INT_MIN;
            int B_left_back = k-1 >= 0 ? B[k-1] : INT_MIN;
            int A_right_front = mid < m ? A[mid] : INT_MAX;
            int B_right_front = k < n ? B[k] : INT_MAX;
            if (A_left_back <= B_right_front && B_left_back <= A_right_front) {
                // odd:
                if ((m+n)%2) {
                    return min(A_right_front, B_right_front);
                }
                // even:
                else {
                    return (max(A_left_back, B_left_back) + min(A_right_front, B_right_front)) / 2.0;
                }
            }
            else if (B_left_back > A_right_front) {
                l = mid+1;
            }
            else {
                r = mid-1;
            }
        }
        return 0.0;
    }
};

// B: [1,2,3,4,5,6,7] n = 7
// A: [100,101]. m = 2