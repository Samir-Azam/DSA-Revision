
#include<iostream>
using namespace std;


int main(){

    // Q 1. Swap two numbers->
    int a = 10;
    int b = 11;
    // core logic to swap using third variable 
    // cout<<a<<" "<<b<<endl;

    // int temp = b;
    // b = a;
    // a = temp;

    // swapping without using a third variable;
    /*
    a = a^b; // a = a ^ b
    b = a^b; // b = a ^ b -> a ^ b ^ b -> a
    a = a^b; // a = a ^ b -> a ^ b ^ a-> b
    */
    // cout<<a<<" "<<b<<endl;


    // Q 2 -> Check if ith bit is set or not 

    a = 10; // binary - 1010
    // check if 0th bit is set or not 

    // for (int i = 0;i<32;i++){
    //     cout<< bool(a & (1<<i))<< " ";
    //     // cout<< bool(a>>i&1)<< " ";
    // }

    // Q 3 -> Set the ith bit 

    a = 10; // 1010

    // setting the 0th bit -> 1011 -> 11
    a = (a|(1<<0));
    // cout<<a<<endl;

    // generalized form to set ith bit -> (a | (1<<i))

    // Q 4-> Clear the ith bit -> just think opposite to set for setting the ith bit you do something like this (a | (1<<i)) so for clearing it you need something that is 1's complement of (1<<i) -> ~(1<<i) and just do an and with the given number. So the generalized form will be something like (a & ~(1<<i))

    a = 13; // 1101

    // clear 2nd bit 

    // cout<<(a & ~(1<<2)); // 1001 -> 9

    // Q 6 -> Toggle the ith bit -> If it is one turn it to 0, if it 0 turn it to one

    // Generalized form -> (a ^ (1<<i));

    a = 10; //1010
    // if we toggle the first bit it will become 8 let's try it 

    // cout<< (a ^ (1<<1)); 

    // Q 7 - Remove the last set bit 

    // It is also very simple just do and of the given number with n-1

    a = 10; // 1010
    // after removing last set bit it will be 1000 -> 8 
    
    a = a & (a-1);
    // Dry run -> a: 1010 -> (a-1): 1001 after performing bitwise and 1000 last bit is clear -> it becomes 8 


    // Q 8 -> Check if a number is power of 2 or not 

    // fact: power of 2 will have only 1 set bit . Eg : 2 -> 10, 4: 100, 8: 1000 and a number down to power of 2 will have the set bit in power of 2 as 0 and all the remaining bit right to it as 1 . Eg: 8-> 1000, 7: 0111

    // conclusion : for power of two n&(n-1) will always be 0

    a = 10; // 1010 -> 9: 1001 -> after and operation  1000 -> 8 -> not power of two
    // cout<<(a&(a-1))<<endl;



    a = 8; // 1000 -> 7: 0111 -> after and operation 0000 -> 0 (power of two)
    // cout<<(a&(a-1))<<endl;


    // Q 9 -> Counting number of set bits 

    /*
    a = 13;

    int count = 0;
    for (int i=31;i>=0;i--){
        cout<<bool(a&(1<<i))<<" ";
        if ((a&(1<<i))) count++;
    }
    cout<<endl<<count<<endl;
    */

    /*
    Better alternative
    
    a = 10; //1010
    int count = 0;
    while (a!=0){
        a = a & (a-1); // to remove the rightmost set bit
        count++;
        
    }
    cout<<count;
    */

    return 0;
}