//
// Created by Shahd Elnassag on 12/29/2024.
// Problem 5 in Part 1 Dynamic Programming
//
#include <bits/stdc++.h>


using namespace std;

// Function to Search the length of the Longest Increasing Subsequence
int getlongestSubsquence(int length, vector<int>& A) {
    vector<int> subseq;

    for (int i = 0; i < length; ++i) {
        // Find the position where A[i] can replace an element in subseq using binary search
        auto it = lower_bound(subseq.begin(), subseq.end(), A[i]);

        // If it is not in the subseq array, append it
        if (it == subseq.end()) {
            subseq.push_back(A[i]);
        } else {
            // Otherwise, replace the element at the found position with A[i]
            *it = A[i];
        }
    }

    // The length of the subseq array will be the length of the longest increasing subsequence
    return subseq.size();
}

int main() {
    // Input
    int length;
    cin >> length;
    vector<int> A(length);
    for (int i = 0; i < length; ++i) {
        cin >> A[i];
    }

    // Find the length of the longest increasing subsequence
    int result = getlongestSubsquence(length, A);

    // Output the result
    cout << result << endl;

    return 0;
}
