class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
    vector<int> C(n, 0);
    unordered_set<int> seenA, seenB; 
    int commonCount = 0;

    for (int i = 0; i < n; ++i) {
        if (seenB.count(A[i])) {
            commonCount++;
        }
        if (seenA.count(B[i])) {
            commonCount++;
        }
        if (A[i] == B[i]) {
            commonCount++; // Avoid double-counting when A[i] == B[i]
        }

        seenA.insert(A[i]);
        seenB.insert(B[i]);

        C[i] = commonCount;
    }

    return C;
    }
};