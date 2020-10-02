
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int lt = 0, rt = 0, sum = 0;
        int n = A.size();
        int res = A[0];
        for (int i = 0; i < n; i ++) 
            res = max(res, A[i]), A.push_back(A[i]);
        n += n;
        vector<int> sums;
        for (int i = 0; i < n; i ++) sum += A[i], sums.push_back(sum);
        
        deque<int> idx;
        for (int i = 0; i < n / 2; i ++) {
            while (!idx.empty() && sums[idx.back()] > sums[i]) idx.pop_back();
            idx.push_back(i);
        }
        
        for (int i = n / 2; i < n; i ++) {
            while (!idx.empty() && i - idx.front() > n / 2) idx.pop_front();
            while (!idx.empty() && sums[idx.back()] > sums[i]) idx.pop_back();
            res = max(res, sums[i] - sums[idx.front()]);
            idx.push_back(i);
        }
        return res;
    }
};
