#include <iostream>
using namespace std;
#include <cmath>
#include <string.h>

// A utility function that returns maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }
int Sack(int W, int wt[], int val[], int n)
{
	if (n == 0 || W == 0) // Base Case
		return 0;
	// If weight of the nth item is more than Knapsack capacity W, then this item cannot be included
		// in the optimal solution
		if (wt[n - 1] > W) {
			return Sack(W, wt, val, n - 1);
		}
			
	// Return the maximum of two cases:
	// (1) nth item included
	// (2) not included
		else
			return max(val[n - 1] + Sack(W - wt[n - 1], wt, val, n - 1), Sack(W, wt,
				val, n - 1));
}
// Driver code
int main()
{
	int val[] = { 60, 100, 120 };
	int wt[] = { 10, 20, 30 };
	int W = 50;
	int n = sizeof(val) / sizeof(val[0]);
	cout << Sack(W, wt, val, n);
	return 0;
}
// This code is contributed by rathbhupendra