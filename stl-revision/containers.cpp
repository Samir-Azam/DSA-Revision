// Header file that you can use for using all most every container and algorithms

#include <bits/stdc++.h> // (best for contests/interviews)
using namespace std;

// but in some oa it is not supported in that case you have to add header files individually like for including vectors use #include<vector>

#include<vector>

// some of the common header files are 

#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>


// writing a custom comparator for min heap

struct Compare{
    bool operator()(int a, int b){
        return a>b;
    }
};


int main (){
    // containers -> they are used for efficient data storage and retrieval they are nothing but predefined classes in c++.

    // ---------------------1. Vector ----------------------------------
    //  It is a dynamic array whose size can be change means we can can insert an element as well as delete from a vector . Common methods of vector are as follows

    // vector declaration
    vector<int>v;
    vector<int>v1(5, 100);

    // for iterating over the vector
    // for (int i=0;i<v1.size();i++){
    // cout<<v1[i]<<" ";
    // }
    
    // to insert an element at the end
    v1.push_back(2);
    // to insert an element at any specific position
    v1.insert(v1.begin()+2, 4);

    // cout<<endl;
    // for (int i=0;i<v1.size();i++){
    // cout<<v1[i]<<" ";
    // }

    // to get the size of vector
    // cout<<v1.size()<<endl;

    // to delete the last element
    v1.pop_back();
    // for (int i=0;i<v1.size();i++){
    // cout<<v1[i]<<" ";
    // }

    // some extra methods 
    // v.clear() - to clear the entire the vector
    // v.back() - to get the element present at the end
    // v.erase(position) - to delete an element present at specific position

    // sorting a vector - sort(v.begin(), v.end())
    // since the sorting algo needs position in other words pointers we can also sort an array using sort(a, a+n) like this 

    // soting in ascending 
    // sort(v1.begin(), v1.end());
    // for (int i=0;i<v1.size();i++){
    // cout<<v1[i]<<" ";
    // }
    // cout<<endl;
    // sort(v1.rbegin(), v1.rend());
    // for (int i=0;i<v1.size();i++){
    // cout<<v1[i]<<" ";
    // }

    // --------------------2. map (ordered)-------------------------------
    
    // It is a data structure which is used to store the the data on the basis of key and value 
    // ordered map - arrages the elements on the basis of their keys in sorted order (ascending)

    // declaration
    map<int, int> mp;

    // uses cases - it is used when you have to remember the frequency or store the associative data 

    // ex- creating a frequency array

    int arr[] = {1,3,1,3,4,5,2,4,5};
    // you have to know the counts of each element so that you can return it in a time complexity of lesser then O(n) after processing

    // processing
    for (int i=0;i<9;i++){
        mp[arr[i]]++;
    }

    // for iterating over the map
    // for (auto it : mp){
    //     cout<<it.first <<"->"<< it.second<<endl;
    // }

    // unordered_map - it is also similar to map but in unordered_map the order of elements is not preserved and its time complexity is better than map in avg case the worst tc can be O(n) and avg is O(1) whereas in maps it is logn

    // declaration

    unordered_map<int, int > mp1;

    // note : you can't declare an unordered_map with pair type but you can declare map with pair type map<pair<int, int>>, int>mp this is very important remember that

    // let's create a same unordered_map for the given array and check if the keys are sorted in ascending order or not

    // processing
    for (int i=0;i<9;i++){
        mp1[arr[i]]++;
    }

    // traversal
    // for (auto it : mp1){
    //     cout<<it.first<<"->"<<it.second<<endl;
    // }
    // after traversal you will find out the keys are not sorted for better tc 

    // mp.count(key)  -  it will return 1 if the key is present otherwise 0
    // cout<<mp1.count(100); 

    // mp.erase(key) - to erase a key 
    // mp1.erase(1);

    // mp.find(key) - it is used to find a key in the map it returns a pointer if element is not found it will return mp.end()

    // mp1.size() - to get the size of the map 
    // the methods are common for both map and unordered_map

    // ------------------------3. Set----------------------------------

    // It is used to store elements in sorted and unique manner it is means it will store elements only once and the order will be sorted

    // declaration

    set<int>st;

    // insert and emplace both can be used to insert elements in set
   
    st.insert(3);
    st.emplace(4);
    st.insert(5);

    // for (auto it: st){
    //     cout<<it<< " ";
    // }

    // some common methods
    // st.size(), st.clear(), st.count(key),st.erase(key)

    // set can't be accessed using indexing

    // unordered_set - stores unique elements but in unsorted order for fast lookup

    unordered_set<int>st2;
    
    st2.insert(1);
    st2.insert(2);
    st2.insert(3);
    st2.insert(4);
    st2.insert(5);

    // for (auto it: st2){
    //     cout<< it<< " ";
    // }

    // methods are mostly same in both set and unordered_set 

    // -------------------------4. Stack ---------------------------------

    // stack data structure is based on the LIFO - last in first out , you can consider a real life example of stack of plate in which the plate that is placed at the end will be removed first

    // declaration
    stack<int>s;

    s.push(2);
    s.emplace(5);
    s.push(4);
    s.push(1);


    // iterating over stack 
    // while (!s.empty()){
    //     int top = s.top(); // returns the top most element
    //     s.pop(); // deletes top most element - ele inserted at last
    //     cout<<top<<" ";
    // }

    // --------------------------5. Queue--------------------------------

    // It is based on FIFO (first in first out) consider a real life example of a queue at a grocery shop where the person who comes first will be attended first 



    // declaration
    queue<int>q;

    q.push(1);
    q.push(0);
    q.push(3);
    q.push(5);
    q.push(4);

    // iteration

    // while (!q.empty()){
    //     int ele = q.front();
    //     q.pop();
    //     cout<<ele<<" ";
    // }

    // some common methods used are q.front(), q.back(), q.push(), q.pop(), q.empty(), q.size() 

    //----------------------- 6.Priority Queue---------------------------

    // It stored elements in particular order either in ascending or descending. There are two types of PQ 1. max heap (stores at greater element at the beginning) 2. min heap(stores min element at the beginning)

    // max heap declaration 
    priority_queue<int>pq;
    pq.emplace(1);
    pq.push(3);
    pq.push(5);
    pq.push(100);
    pq.emplace(10);

    // while (!pq.empty()){
    //     cout<<pq.top()<<" -> ";
    //     pq.pop();
    //     cout<<"current size of max heap : "<<pq.size()<<endl;
        
    // }

    // min heap declaration

    priority_queue<int, vector<int>, greater<int>>mh;
    // we can also use our own comparator that we declare above 
    // priority_queue<int, vector<int>, Compare>mh;

    mh.emplace(1);
    mh.push(3);
    mh.push(5);
    mh.push(100);
    mh.emplace(10);

    // while (!mh.empty()){
    //     cout<<mh.top()<<" -> ";
    //     mh.pop();
    //     cout<<"current size of min heap : "<<mh.size()<<endl;
    // }


    // ----------------------------7.Pair---------------------------------

    // A pair stores two values together (can be same or different types)

    // pair<int, int>p;
    // (first, second)
    
    // how to declare and initialize a pair 
    // 1. direct initialization

    pair<int, int> p = {1, 2};

    // 2. Using make_pair()
    // pair<int, int> p = make_pair(1,2);

    // for accessing and modifying values use
    cout<<p.first<<" "<<p.second;

    
    return 0;
}



