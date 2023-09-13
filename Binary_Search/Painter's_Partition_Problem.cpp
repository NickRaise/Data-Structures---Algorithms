// Problem: Painter's Partition Problem

// Given an array/list of length 'n', where the array/list represents the boards and each element of the given array/list represents the length of each board. 
// Some 'k' numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint.

// You are supposed to return the area of the minimum time to get this job done of painting all the ‘n’ boards under a constraint that any painter will only paint the continuous sections of boards.

// Sample Input 1 :
// 4 2
// 10 20 30 40

// Sample Output 1 :
// 60


#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// Function to check if it's possible to paint the boards with the given constraints
bool isPossible(vector<int> &arr, int k, int mid) {
    int painter = 1;
    int sum = 0;
    for(int i = 0; i < arr.size(); i++) {
        // Check if the current board length is within the allowed range
        if (arr[i] > mid) {
            return false;
        }
        
        // Check if the current board can be painted by the current painter
        if (sum + arr[i] <= mid) {
            sum += arr[i];
        } else {
            // If not, allocate a new painter
            painter++;
            sum = arr[i];
        }
        
        // If the number of painters exceeds the allowed limit, it's not possible
        if (painter > k) {
            return false;
        }
    }
    return true;
}

// Function to find the largest minimum distance such that you can paint the boards with at most k painters
int findLargestMinDistance(vector<int> &boards, int k) {
    int left = 0; // Minimum possible minimum distance
    int right = accumulate(boards.begin(), boards.end(), 0); // Maximum possible minimum distance
    int ans = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (isPossible(boards, k, mid)) {
            ans = mid;
            right = mid - 1; // Look for a smaller minimum distance
        } else {
            left = mid + 1; // Increase the minimum distance
        }
    }
    
    return ans;
}

int main() {
    int n, k;
    cout << "Enter the number of boards (n): ";
    cin >> n;
    cout << "Enter the number of painters (k): ";
    cin >> k;
    
    vector<int> boards(n);
    cout << "Enter the lengths of the boards: ";
    for (int i = 0; i < n; i++) {
        cin >> boards[i];
    }
    
    int result = findLargestMinDistance(boards, k);
    cout << "The largest minimum distance is: " << result << endl;
    
    return 0;
}
