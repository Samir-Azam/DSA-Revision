/*
Leetcode 1922: Count Good Numbers

A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).

For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.

A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.

 

Example 1:

Input: n = 1
Output: 5
Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".
Example 2:

Input: n = 4
Output: 400
Example 3:

Input: n = 50
Output: 564908303
 

Constraints:

1 <= n <= 1015
*/

// Approach is very simple you just have to understand the concept of it and then the implementation becomes a little easier, first understand if we have a n length array and how many even indices will be there (it will be (n+1)/2 ) and how many odd indices will be there (there will be n/2 odd indices) now we have to find the count of prime numbers in the odd indices then we have to find the count of even numbers in the even indices then we have to multiply them and then return the answer since even numbers are (0,2,4,6,8) and prime numbers are (2,3,5,7) so we have to multiply them and then return the answer so simply we have find power(5, (n+1)/2) * power(4, n/2) and then return the answer

// Time Complexity - O(logn)
// Space Complexity - O(1)



class Solution {
public:
    long long MOD = 1e9 + 7;

    long long power(long long x, long long n){
        if (n==0) return 1;

        long long half = power(x, n/2);
        long long res = (half*half)%MOD;

        if (n&1) res = (x*res)%MOD;
        return res;

    }

    int countGoodNumbers(long long n) {
        // if n is the length of an integer and it has (n+1)/2 even position and n/2 odd position

        long long even = (n+1)/2;
        long long odd = n/2;

        // options for even indices - 0, 2, 4, 6, 8 (even numbers) - 5 options
        // options for odd indices - 2,3,5,7 (prime numbers) - 4 options

        long long even_ways = power(5, even);
        long long odd_ways = power(4, odd);
        return (even_ways*odd_ways)%MOD;
    }
};