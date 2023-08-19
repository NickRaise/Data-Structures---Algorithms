// Problem: Find a triplet that sum to a given value (3sum)

// You are given an array/list ARR consisting of N integers. Your task is to find all the distinct triplets present in the array which adds up to a given number K.
// An array is said to have a triplet {ARR[i], ARR[j], ARR[k]} with sum = 'K' if there exists three indices i, j and k such that i!=j, j!=k and i!=j and ARR[i] + ARR[j] + ARR[k] = 'K'.

// Sample Input 1:
// 5
// 10 5 5 5 2
// 12
  
// Sample Output 1:
// 5 5 2


#include <bits/stdc++.h>
using namespace std;

// Function to find triplets that sum to a given value K
vector<vector<int>> findTriplets(vector<int> arr, int n, int K) {
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());

    // Iterate through the array to find triplets
    for (int i = 0; i < arr.size() - 2; i++) {

        // Skip duplicate elements for i
        if (i > 0 && (arr[i] == arr[i - 1]))
            continue;

        int left = i + 1, right = arr.size() - 1;

        // Two-pointer approach to find triplets
        while (left < right) {
            if (arr[i] + arr[left] + arr[right] == K) {
                // Found a triplet with sum K
                ans.push_back({arr[i], arr[left], arr[right]});

                // Skip duplicates for left
                while (left < right && arr[left] == arr[left + 1])
                    left++;
                // Skip duplicates for right
                while (left < right && arr[right] == arr[right - 1])
                    right--;

                left++;
                right--;
            } else if (arr[i] + arr[left] + arr[right] < K) {
                // Move left pointer to increase the sum
                left++;
            } else {
                // Move right pointer to decrease the sum
                right--;
            }
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> a;
    // Input array elements
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    int sum;
    cin >> sum;

    // Find and display triplets that sum to 'sum'
    vector<vector<int>> ans = findTriplets(a, n, sum);
    for (auto it : ans) {
        for (auto i : it) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
