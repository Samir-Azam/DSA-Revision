/*
Bit Manipulation:

Every Integer that you store in a variable is a collection of 0s and 1s.
Computer understand only bits. So when you store 5 in an integer variable, it is actually stored in binary form as 0101 in memory.

Steps to convert decimal to binary:

1. Find the remainder of the number when it is divided by 2.
2. Store the remainder in a variable.
3. Divide the number by 2.
4. Repeat the above steps until the number becomes 0.
5. And the binary order will be from top to bottom

Eg. 5 = 0101
    4 = 0100
    2 = 0010
    1 = 0001
Step by step example - 5 = 0101
5/2 = 2 with remainder 1
2/2 = 1 with remainder 0
1/2 = 0 with remainder 1
0/2 = 0 with remainder 0

Code to convert decimal to binary :

int n = 5;
int binary = 0;
while(n>0){
    int bit = n%2;
    n = n/2;
    binary = binary*10 + bit;
}

Q. How to convert binary to decimal ?
Ans : We multiply the bits with power of 2 and add it to the variable. (right -> left)

Code :

int n = 101;
int decimal = 0;
int power = 1;
while(n>0){
    int bit = n%10;
    n = n/10;
    decimal = decimal + bit*power;
    power = power*2;
}

Q. How negative numbers are stored in memory ?
Ans : It is stored in 2's complement form.
Steps for storing -5 in memory.
-5 = 1111 1111 1111 1111 1111 1111 1111 1111
+5 = 0000 0000 0000 0000 0000 0000 0000 0010

First the number is converted into 1s complement form.
Then 1 is added to it to convert it into 2's complement.
once the 2's complement form is obtained, it is stored in memory.

while retrieval we check its sign bit (MSB) and if it is 1 then it is negative and if it is 0 then it is positive.
If the sign bit is 1 then it is negative and we have to convert it into 2's complement form.

Eg: Steps for storing retriving back -5 are

1. Since it is negative number it is converted into 2's complement form.
2. 1111 1111 1111 1111 1111 1111 1111 1011
3. Now since the sign bit is 1, we have to convert it into 2's complement form.
4. 0000 0000 0000 0000 0000 0000 0000 0101
5. So, in this way we can get the original number.
*/

// Operators Used in Bit manipulation

/*
& - Bitwise AND
| - Bitwise OR
^ - Bitwise XOR
~ - Bitwise NOT
<< - Bitwise Left Shift
>> - Bitwise Right Shift
*/

// Bitwise AND (&) - Returns 1 if both bits are 1 else 0
// Eg. 101 & 110 = 100

// Bitwise OR (|) - Returns 1 if either of the bits is 1 else 0
// Eg. 101 | 110 = 111

// Bitwise XOR (^) - Returns 1 if both bits are different else 0
// Eg. 101 ^ 110 = 011

// Bitwise NOT (~) - Returns 0 if the bit is 1 else 1
// Eg. ~101 = 010

// Bitwise Left Shift (<<) - Shifts the bits to the left by the specified number of positions
// Eg. 101 << 2 = 10100
// If we left shift a number by k places then the number is multiplied by 2^k
// Eg. 101 << 2 = 10100

// Bitwise Right Shift (>>) - Shifts the bits to the right by the specified number of positions
// Eg. 101 >> 1 = 10
// If we right shift a number by k places then the number is divided by 2^k
// Eg. 101>>2 = 1


