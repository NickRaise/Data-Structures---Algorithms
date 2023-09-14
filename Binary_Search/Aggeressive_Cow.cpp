// Problem: Aggressive Cows

// You are given an array 'arr' consisting of 'n' integers which denote the position of a stall.
// You are also given an integer 'k' which denotes the number of aggressive cows.
// You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.
// Print the maximum possible minimum distance.

// Sample Input 1 :
// 5 2
// 4 2 1 3 6

// Sample Output 1 :
// 5



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to check if it's possible to place 'k' cows in stalls with minimum distance 'mid' between them
bool isPossible(vector<int> &stalls, int k, int mid) {
    int cow = 1; // Initialize the number of cows placed as 1 (starting with the first stall)
    int position = stalls[0]; // Initialize the position of the first cow

    for(int i = 1; i < stalls.size(); i++) {
        // If the current stall distance from the previous cow is greater than or equal to 'mid'
        if(stalls[i] - position >= mid) {
            cow++; // Place a cow in the current stall
            position = stalls[i]; // Update the position of the cow
        }

        if(cow == k) {
            return true; // If 'k' cows are placed successfully with 'mid' distance, return true
        }
    }

    return false; // If 'k' cows cannot be placed with 'mid' distance, return false
}

// Function to find the maximum minimum distance to place 'k' cows
int aggressiveCows(vector<int> &stalls, int k) {
    sort(stalls.begin(), stalls.end()); // Sort the stalls in ascending order
    int left = 0; // Initialize the left boundary of the search space
    int right = stalls.back() - stalls[0]; // Initialize the right boundary of the search space
    int mid;
    int ans = -1; // Initialize the answer to -1

    // Binary search for the maximum minimum distance
    while(left <= right) {
        mid = left + (right - left) / 2; // Calculate the middle distance to check

        // If it's possible to place 'k' cows with distance 'mid', search in the right half
        if(isPossible(stalls, k, mid)) {
            left = mid + 1; // Move the left boundary to 'mid + 1'
            ans = mid; // Update the answer to the current 'mid'
        }
        else {
            right = mid - 1; // Otherwise, search in the left half
        }
    } 
    
    return ans; // Return the maximum minimum distance
}

int main() {
    int n, k;
    cout << "Enter the number of stalls: ";
    cin >> n; // Input the number of stalls
    cout << "Enter the number of cows: ";
    cin >> k; // Input the number of cows
    vector<int> stalls(n);

    cout << "Enter the positions of stalls: ";
    for(int i = 0; i < n; i++) {
        cin >> stalls[i]; // Input the positions of the stalls
    }

    int maxMinDistance = aggressiveCows(stalls, k); // Find the maximum minimum distance

    cout << "The maximum minimum distance to place " << k << " cows is: " << maxMinDistance << endl;

    return 0;
}
