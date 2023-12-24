/* STL - Standard Template Library
       - STL is basically a compilation of algorithms, containers, iterators,
         functions in a minimized version, so that we don't to write lengthy 
         lines of codes to perform algorithms, containers.
        */

#include<iostream>
using namespace std;

/*
void print()        //void function will not return anything
{
    cout << "vasu";
}

int sum(int a, int b)   // 'int' have a return type
{
    return a + b;
}

int main()
{
    print();

    int s = sum(4, 5);
    cout << "S: " << s;     // prints '9'
}
*/


/*
    C++ STL is divided into 4 parts-
    1. Algorithms
    2. Containers     <- Vector, Queue, Set, Map etc.
    3. Functions
    4. Iterators      <- begin(), end(), advance(), next(), prev(), inserter()
*/



//                                          CONTAINERS (with ITERATORS)
/*
        Pairs  - is a part of utility library
               - used to store couple of integers

#include<utility>

void explainPair()
{
    pair<int, int> p = {1, 3};      //variable 'p' contains {1, 3}, and Data Type can be anything

    cout << p.first << " " << p.second;

    pair<int, pair<int, int>> p = {1, {2, 6}};      //to store more than 2 variables, we can use nested pair

    cout << p.first << " " << p.second.second << " " << p.second.first;

    pair<int, int> arr[] = {{1, 2}, {2, 5}, {5, 1}};

    cout << arr[1].second;      // <- is going to print '5'
}

// CPP program to illustrate Pair in STL
#include <iostream>
#include <utility>
using namespace std;

// Driver Code
int main()
{
    // defining a pair
    pair<int, char> PAIR1;

    // first part of the pair
    PAIR1.first = 100;
    // second part of the pair
    PAIR1.second = 'G';

    cout << PAIR1.first << " ";
    cout << PAIR1.second << endl;

    return 0;
}
*/



/*
        Vectors  - if we define an array(for ex arr[5]), we can't change it's
                   size, also we can't modify it's element later in the code.
                   This is where 'Vector'comes into action. Vector is a 
                   container which is dynamic by it's nature. we can always
                   change it's size. Vector contains variable in similar fashion
                   as array does.

#include<vector>
void explainVector()
{
    vector<int> v;  // <- it will create a empty container, like array with empty curly braces. v is vectorname.  v = { };

    v.push_back(1);     // v = {1};  push_back() adds a copy of the object to the end of the list.
    v.emplace_back(2);  // v = {1, 2};  emplace_back is similar to push_back but potentially improving performance by avoiding a copy operation
    
    vector<pair<int, int>>vec;  // here we defined pair in vector

    v.push_back({1, 2});
    v.emplace_back(1, 2);   //these two lines shows the difference in push_back and emplace_back syntaxes, both syntaxes are valid

    vector<int> v(5, 100);  // v = {100, 100, 100, 100, 100};  vector<int> vectorName(size, variable);

    vector<int> v(5);   // v = {garbage value of size 5};  garbage value depends on the compiler

    vector<int> v1(5, 20);  // {20, 20, 20, 20, 20};
    vector<int> v2(v1);     // v2 is copy of v1 i.e {20, 20, 20, 20, 20};

    v.push_back(1);     //we can increase the size of a vector even after declaring it {20, 20, 20, 20, 20, 1};

    // How to access elements in a vector
    // we can also access the elements as we do in array i.e v(5) = {1, 2, 3, 4, 5} => v[1] = 2
    // the other way to access elements is by using 'iterator', iterator points to the memory address

    vector<int>::iterator it = v.begin();   // <- means iterator 'it' is pointing to the memory location of 0th index, it is vectorName

    it++;       // to move the memory location right next memory  location
    cout << *(it) << " ";   // to access the value of the memory location, here we got '2' as cout

    it = it + 2;    // shifting 2 places i.e '4'
    cout << *(it) << " ";   // o/p-> '4'

    vector<int>::iterator it = v.end();     // in here 'it' will points the memory location "right after the last element"
                                            // so to print the memory location of last element we have to use -  it--;

    vector<int>::iterator it = v.rend();    // it will reverse the whole vector and then points to right after last element's memory location
                                            // {5, 4, 3, 2, 1} it will point after 1's memory location

    vector<int>::iterator it = v.rbegin();  // it will also reverse the vector (i.e {5, 4, 3, 2, 1}) and will point to '5'
                                            // doing "it++" will give us '4'
                                            // rend() and rbegin() are rarely used iterators

    cout << v[0] << " " << v.at[0];     // both are the same thing

    cout << v.back() << " ";    // prints the last element i.e 5


    //we can print a vector directly by using loop, but also we can use iterator as below
    
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) 
        {
        cout << *(it) << " ";
        }

    // another simpler way

    for (auto it = v.begin(); it != v.end(); it++)          // 'auto' automatically assigns 'it' to the vector iterator
        {                                                   // 'auto' automatically defines the Data Type, if we write "auto a = 5;" ->'a' will be assigned as int
        cout << *(it) << " ";
        }

    // another way 

    for (auto it : v)
        {
        cout << it << " ";
        }


    // deletion of vector

        // {10, 20, 12, 23}
    v.erase(v.begin() + 1);     // we get {10, 12, 23}

        // {10, 20, 30, 40, 50}
    v.erase(v.begin() + 1, v.begin() + 3);      // we get {10, 40, 50} -> (start, end + 1)


    // insert function
    vector<int>v(2, 100);       // <- {100, 100}
    v.insert(v.begin(), 300);       // <- {300, 100, 100}
    v.insert(v.begin() + 1, 2, 10);     // <- {300, 10, 10, 100, 100}

    vector<int> copy(2, 50);    // {50, 50}         this line and below are rarely used
    v.insert(v.begin(), copy.begin(), copy.end());      // {50, 50, 300, 10, 10, 100, 100}

        // {10, 20, 30}
    cout << v.size();   // <- 2

        // {10, 20, 30}
    v.pop_back();   // {10, 20}     pops out the last element

        // v1 -> {10, 20}
        // v2 -> {80, 90}
    v1.swap(v2);    // v1 -> {80, 90}, v2 -> {10, 20}

    v.clear();  // erases the entire vector

    cout << v.empty();      // returns 'true' if vector is empty otherwise returns 'false'
}
*/



/*
           List  -  Lists are sequence containers that allow non-contiguous 
                    memory allocation. As compared to the vector, the list has 
                    slow traversal, but once a position has been found, insertion 
                    and deletion are quick (constant time).
                    We can perform front operations in List.

#include<list>

void explainList()
{
    list<int> ls;           // same way of declaration as vector

    ls.push_back(2);        // {2}
    ls.emplace_back(4);     // {2, 4}

    ls.push_front(5);       // {5, 2, 4}

    ls.emplace_front(1);    // {1, 5, 2, 4}

    // rest functions same as vector
    // begin, end, rbegin, rend, clear, insert, size, swap
}
*/



/*
            Deque  -  Double-ended queues are sequence containers with the feature 
                      of expansion and contraction on both ends. They are similar 
                      to vectors, but are more efficient in case of insertion and 
                      deletion of elements. Unlike vectors, contiguous storage 
                      allocation may not be guaranteed. 
                      Double Ended Queues are basically an implementation of the 
                      data structure double-ended queue. A queue data structure 
                      allows insertion only at the end and deletion from the front.
                      This is like a queue in real life, wherein people are removed 
                      from the front and added at the back. Double-ended queues are 
                      a special case of queues where insertion and deletion 
                      operations are possible at both the ends.
        The functions for deque are same as vector, with an addition of push and pop 
        operations for both front and back.  

        The time complexities for doing various operations on deques are-

        Accessing Elements- O(1)
        Insertion or removal of elements- O(N)
        Insertion or removal of elements at start or end- O(1)

#include<deque>

void explainDeque()
{
    deque<int>dq;
    dq.push_back(1);        // {1}
    dq.emplace_back(2);     // {1, 2}
    dq.push_front(4);       // {4, 1, 2}
    dq.emplace_front(3);    // {3, 4, 1, 2}

    dq.pop_back();      // {3, 4, 1}
    dq.pop_front();     // {4, 1}

    dq.back();

    dq.front();

    // rest functions same as vector
    // begin, end, rbegin, rend, clear, insert, size, swap
}
*/



/*
            Stack  -  Stacks are a type of container adaptors with 
                      LIFO(Last In First Out) type of working, where a new 
                      element is added at one end (top) and an element is 
                      removed from that end only.  Stack uses an encapsulated 
                      object of either vector or deque (by default) or list 
                      (sequential container class) as its underlying container, 
                      providing a specific set of member functions to access 
                      its elements. 

                      If there is confusion in remembering the basic difference 
                      between stack and queue, then just have a real life 
                      example for this differentiation, for stack, stacking 
                      of books we can take the top book easily and for queue 
                      remember when you have to stand in queue front of ATM 
                      for taking out the cash, then first person near to ATM 
                      has the first chance to take out the money from ATM. 
                      So, queue is the FIFO (First In First Out) type working.

            The functions associated with stack are: 
            empty() – Returns whether the stack is empty – Time Complexity : O(1) 
            size() – Returns the size of the stack – Time Complexity : O(1) 
            top() – Returns a reference to the top most element of the stack – Time Complexity : O(1) 
            push(g) – Adds the element ‘g’ at the top of the stack – Time Complexity : O(1) 
            pop() – Deletes the most recent entered element of the stack – Time Complexity : O(1) 

#include<stack>

void explainStack()
{
    stack<int> st;
    st.push(1);     // {1}
    st.push(2);     // {2, 1}
    st.push(3);     // {3, 2, 1}
    st.push(3);     // {3, 3, 2, 1}
    st.emplace(5);  // {5, 3, 3, 2, 1}

    cout << st.top();   // prints '5'  "st[2] is invalid, indexing is not valid"

    st.pop();       // {3, 3, 2, 1}

    cout << st.top();   // prints '3'

    cout << st.size();  // prints '4'

    cout << st.empty();     // 'false'

    stack<int>st1, st2;
    st1.swap(st2);
}
*/



/*
        Queue  -  Queues are a type of container adaptors that operate in a 
                  (FIFO) first in first out type of arrangement. Elements are 
                  inserted at the back (end) and are deleted from the front. 
                  Queues use an encapsulated object of deque or list 
                  (sequential container class) as its underlying container, 
                  providing a specific set of member functions to access its 
                  elements.

        The time complexity and definition of the following functions are 
        as follows:

        queue::empty()   -	O(1)
        queue::size()    -	O(1)
        queue::emplace() -	O(1)
        queue::front()   -	O(1)
        queue::back()    -	O(1)
        queue::push(g)   - 	O(1)
        queue::pop()     - 	O(1)

#include<queue>

void explainQueue()
{
    queue<int> q;
    q.push(1);      // {1}
    q.push(2);      // {1, 2}
    q.emplace(4);   // {1, 2, 4}

    q.back() += 5;      // it will add into the last element
    cout << q.back();   // prints '9', "q" is {1, 2, 9}

    cout << q.front();  // prints '1'

    q.pop();        // {2, 9}

    cout << q.front();  // prints '2'

    // size, swap, empty same as stack
}
*/



/*
        Priority Queue  -  A C++ priority queue is a type of container adapter, 
                           specifically designed such that the first element of 
                           the queue is either the greatest or the smallest of 
                           all elements in the queue, and elements are in 
                           non-increasing or non-decreasing order (hence we can 
                           see that each element of the queue has a priority 
                           {fixed order}).

                           In C++ STL, the top element is always the greatest by 
                           default. We can also change it to the smallest element 
                           at the top. Priority queues are built on the top of the 
                           max heap and use an array or vector as an internal 
                           structure. In simple terms, STL Priority Queue is the 
                           implementation of Heap Data Structure.

        Complexities Of All The Operations:
        Methods                     Time Complexity     Auxiliary Space

        priority_queue::empty()         O(1)                O(1)

        priority_queue::size()          O(1)                O(1)

        priority_queue::top()           O(1)                O(1)

        priority_queue::push()          O(logN)             O(1)

        priority_queue::pop()           O(logN)             O(1)

        priority_queue::swap()          O(1)                O(N)

        priority_queue::emplace()       O(logN)             O(1)

        priority_queue value_type       O(1)                O(1)

#include<queue>

void explainPriorityQueue()
{
    priority_queue<int>pq;

    pq.push(5);     // {5},     mind the places of the elements in every steps
    pq.push(2);     // {5, 2}
    pq.push(8);     // {8, 5, 2}
    pq.emplace(10); // {10, 8, 5, 2}

    cout << pq.top();   // prints '10'

    pq.pop();       // {8, 5, 2}

    cout << pq.top();   // prints '8'

    // size, swap, empty functions same as others

    // Minimum Heap
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(5);     // {5}
    pq.push(2);     // {2, 5}
    pq.push(8);     // {2, 5, 8}
    pq.emplace(10); // {2, 5, 8, 10}

    cout << pq.top();   // prints '2'
}
*/



/*
        Set  -  Set stores everything in sorted order and unique

#include<set>

void explainSet()
{
    set<int>st;
    st.insert(1);       // {1}
    st.emplace(2);      // {1, 2}
    st.insert(2);       // {1, 2},      <- sort and unique(no repeatition)
    st.insert(4);       // {1, 2, 4}
    st.insert(3);       // {1, 2, 3, 4} <- sorted

    // Functionality of insert in vector can be used too, that only increases efficiency

    // begin(), end(), rbegin(), rend(), size(), empty(), swap() as same as above

    // {1, 2, 3, 4}
    auto it = st.find(3);   // returns the iterator which points to'3' (points to the address)

    // {1, 2, 3, 4}
    auto it = st.find(6);   // returns "st.end()", if an element is not on the set then it will returns the iterator which points to 'right after the end'

    // {1, 2, 3, 4}
    st.erase(4);        // erases '4' and maintain the sorted order, takes logrithmic time

    int cnt = st.count(1);  // returns 1 or 0 based on whether the element is present in the set or not

    auto it = st.find(3);
    st.erase(it);       // erase the element by its iterator, also it takes constant time

    // {1, 2, 3, 4, 5}
    auto it1 = st.find(2);
    auto it2 = st.find(4);
    st.erase(it1, it2);     // {1, 4, 5}, erases 'first' to '(last - 1)'

    // lower_bound() and upper_bound() function works in the same way as in vector does
    auto it = st.lower_bound(2);

    auto it = st.upper_bound(3);    // search about these two in google and there is a link in the description
}
*/



/*
        MultiSet  -   it only obey sorted, does not obey unique

#include<set>

void explainMultiSet()
{
    // Everything is same as set, stores duplicate elements also

    multiset<int>ms;
    ms.insert(1);       // {1}
    ms.insert(1);       // {1, 1}
    ms.insert(1);       // {1, 1, 1}

    ms.erase(1);        // erases all the '1's

    int cnt = ms.count(1);      // returns '3'

    ms.erase(ms.find(1));   // {1, 1},  erases first '1', bcz we are pointing to address of first '1'. If we erase element(instead of memory address), it will delete all the '1's

    ms.erase(ms.find(1), ms.find(1) + 2);   // {1},  erases first two '1's

    // rest all functions same as set
}
*/



/*
        Unordered Set  -   it only obey uniqueness, does not store in sorted order

        unordered_set take constant time O(1) on an average which can go up to linear 
        time O(n) in the worst case which depends on the internally used hash function, 
        but practically they perform very well and generally provide a constant time 
        lookup operation.

#include<set>

void explainUSet()
{
    unordered_set<int> st;

    // lower_bound() and upper_bound function does not work
    // rest all the dunctions are same as above
    // it does not stores in any particular order, it has a better complexity than set in most cases, except some when collision happens
}
*/



/*
        Map  -  Maps are associative containers that store elements in a mapped fashion. 
                Each element has a key value and a mapped value. No two mapped values 
                can have the same key values(key values are unique).
                Keys and Values can be of any Data Type.
                Map stores unique keys in 'sorted' order.
                
#include<map>

void explainMap()
{
    map<int, int> mpp;              // map<key, value> mapName;

    map<int, pair<int, int>> mpp;   // map<key, pair of values> mapName;

    map< pair<int, int>, int> mpp;  // map<pair of keys, value> mapName;


    mpp[1] = 2;             // it stores as {key '1', value '2'}
    mpp.emplace({3, 1});    // it stores as {key '3', value '1'}
    mpp.insert({2, 4});     // it stores as {key '2', value '4'}
    // we can say above 3 lines are the same
    // they will be stored in pair as  [{1, 2}, {2, 4}, {3, 1}]         ----eq1

    mpp[{2, 3}] = 10;       // it stores as {key '{2, 3}', value '10'}


    // if we want to iterate on the map(eq1) then we can do similar as we have done in the vector(i.e iterate the first element and then ++)
    // or we can also do the below

    for (auto it : mpp)                             //it will plot in sorted order of keys
        {
        cout << it.first << " " << it.second << endl;
        }


    cout << mpp[1];         // prints '2', bcz value at key '1' is '2' (eq1)
    cout << mpp[5];         // prints '0' or 'NULL', bcz key '5' does not exist

    auto it = mpp.find(3);
    cout << *(it).second;   // prints '1'

    auto it = mpp.find(5);  // prints "mpp.end()", which is after the map

    auto it = mpp.lower_bound(2);

    auto it = mpp.upper_bound(3);

    // erase, swap, size, empty are same as above
}
*/



/*
        Multimap  -  Multimap is similar to a map with the addition that multiple 
                     elements can have the same keys. Also, it is NOT required that 
                     the key-value and mapped value pair have to be unique in this 
                     case. One important thing to note about multimap is that 
                     multimap keeps all the keys in sorted order always.

#include<map>

void explainMultimap()
{
    // everything same as map, but it can store multiple keys
    // only "mpp[key]" cannot be used here
}
*/



/*
        Unordered Map  -  unordered_map is an associated container that stores elements 
                          formed by the combination of a key value and a mapped value. 
                          The key value is used to uniquely identify the element and the 
                          mapped value is the content associated with the key. Both key 
                          and value can be of any type predefined or user-defined. In 
                          simple terms, an unordered_map is like a data structure of 
                          dictionary type that stores elements in itself. It contains 
                          successive pairs (key, value), which allows fast retrieval of 
                          an individual element based on its unique key.

                          1. Unique keys
                          2. No Duplicate key
                          3. No sorted order
                          4. Random order

         In the worst case, its time complexity can go from "O(1)" to "O(n)", especially for 
         big prime numbers. In this situation, it is highly advisable to use a map instead to 
         avoid getting a TLE(Time Limit Exceeded) error.

#include<unordered_map>

void explainUnorderedMap()
{
    //same as set and unordered_set's difference
}
*/



//                                  ALGORITHM
/*
void explainExtra()         // as in the video(4th episode)
{
    // a[] = {1, 5 , 3, 2}; 
    sort(a, a + n);     // sort(a, a + 4), size is 4 but "a + 4" is loation after '2' in the array which also means 'start' is included but 'last' is not included   <- sorting in ascending order
    // above line will give -> a[] = {1, 2, 3, 5};
    sort(v.begin(), v.end());

    // {1, 3, 5, 2} we want to sort last 2 elements (i.e 5, 2)
    sort(a + 2, a + 4);     // returns {1, 3, 2, 5}

    // {1, 3, 5, 2} we want to sort them in descending order
    sort(a, a + n, greater<int>);   // {5, 3, 2, 1},  'greater<int>' is comparitor, which automatically sorts

    pair<int, int> a[] = {{1, 2}, {2, 1}, {4, 1}};
    // sort it acording to second element in ascending(increasing 2nd element), if 
    // second element is same then sort according to first element but in descending
    // we do as below

    sort(a, a + n, comp);       // 'comp' is self written comparitor, and this 'comp' is a "boolean" function
    // now we are going to write this 'boolean' function(like how we write before after "#include<>" and before "int main()" and invoke it under "int main()")

    // we just have to take only two pairs in every problem
    bool comp(pair<int, int> p1, pair<int, int> p2)         // we are taking only 'two' pairs(i.e {1, 2}, {2, 1}), we don't need to take all the pairs in 'any this type of the problems'
        {
        if(p1.second < p2.second)                           // 1st condition, second elelment of the pairs p1 is greater than p2's then return 'true', we want the pairs to remain that way(i.e in ascending according to the second element) 
            return true;

        if(p1.second > p2.second)                           // 2nd condition, second elelment of the pairs p1 is lesser than p2's then return 'false' and swap it internally
            return false;

        // 3rd condition, second elelment of the pairs p1 and p2's are equal, then
        if(p1.first > p2.first)                             // condition where p1's first element is greater than p2's then return true, we want the pairs to remain that way(i.e in desending according to the first element if second's are same)
            return true;

        // otherwise of the 3rd condition
        return false;                                       // condition where p1's first element is lesser than p2's then return 'false' and swap them internally
        }
        // returns {{4, 1}, {2, 1}, {1, 2}}; ,  as we wanted


        // another STL
        int num = 7;
        int cnt = _builtin_popcount();      // this '_builtin_popcount()' STL will return the count of '1' present in binary form of '7'
        // returns '3', 7 in binary -> 111, which is 3 counts of '1'

        long long num = 156378783663897;
        int cnt = _builtin_popcountll();    // ll is for 'long long'


        // permutation of string variable
        string s = "123";       // we want to find all the permutations of '123' which is '132', '213', '231', '312', '321'

        do {
            cout << s << endl;
        } while (next_permutation(s.begin(), s.end()));     // after '321' the permutation will get to 'NULL' and return false, by this we will get all the permutations

        // if the string is '231' then it will only print '312' and '321' then returns false
        // to get all the permutations first we have to sort the string and then apply the "do while" loop 
        // like below

        string s = "231"'
        sort(s.begin(), s.end());
        do {
            cout << s << endl;
        } while (next_permutation(s.begin(), s.end()));


        // we have an array {1, 10, 6, 5}
        int maxi = *max_element(a, a + n);  // prints '10', a->start iterator, a + n-> end iterator
        int mini = *min_element(a, a + n);  // prints '1'
}
*/