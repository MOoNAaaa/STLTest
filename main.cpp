#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <array>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <forward_list>
#include <algorithm>
#include <iterator>

using namespace std;

void foo(const unordered_map<char, string> &m){
//    m['S'] = "SUNDAY";    //error! m is not modified
//    cout<<m['S']<<endl;     //error! wrong access method
    auto itr = m.find('S');     //right way to access a map
    if(itr != m.end())
        cout<<itr->second<<endl;
}
struct Printer
{
    template<typename T> void operator()( T t ) { cout<<t<<" "; }
};
bool isOdd(int x){
    return x % 2;
}

int main() {
    /*
     * vector
     */
//    vector<int> vec;
//    for(int i=5; i>0; i--)
//        vec.push_back(i);
//    for(vector<int>::iterator it=vec.begin(); it != vec.end(); ++it)
//        cout<<*it<<endl;
//    sort(vec.begin(), vec.end());
//    for(auto it=vec.begin(); it != vec.end(); ++it)
//        cout<<*it<<endl;
//    for(int i=0; i<vec.size(); i++)
//        cout<<vec[i]<<" ";
//    for(int i=0; i<vec.size(); i++)
//        cout<<vec.at(i)<<" ";
//    for(auto it:vec)
//        cout<<it<<" ";
//
//    int* p = &vec[0];
//    p[2] = 6;
//    cout<<endl<<vec[2]<<endl;
//
//    vector<int> vec2(vec);
//    for(auto it:vec2)
//        cout<<it<<" ";
//    vec.clear();
//    vec2.swap(vec);
//    cout<<endl<<vec2.size()<<" "<<vec.size()<<endl;
//
//    vector<int> vec3 = {1, 2, 3};
//    for(auto it:vec3)
//        cout<<it<<" ";
//    cout<<endl;
//
//    vector<int>::iterator it1 = find(vec3.begin(), vec3.end(), 1);
//    cout<<*it1<<endl;


    /*
     * deque
     */
//    deque<int> deq;
//    for(int i=0; i<3; i++)
//        deq.push_back(i);
//    for(int i=0; i<3; i++)
//        deq.push_front(i);
//    for(auto it:deq)
//        cout<<it<<" ";

    /*
     * list
     */
//    list<int> mylist = {5, 2, 7, 9};
//    mylist.push_front(1);
//    mylist.push_back(5);
//    for(auto it:mylist)
//        cout<<it<<" ";
//    cout<<endl;
//
//    list<int>::iterator it = find(mylist.begin(), mylist.end(), 7);
//    mylist.insert(it, 0);
//    mylist.insert(it, 4);
//    it++;
//    mylist.erase(it);
//    it++;
//    mylist.erase(it);
//    for(auto it:mylist)
//        cout<<it<<" ";
//    cout<<endl;
//
//    list<int> mylist2(mylist);
//    list<int>::iterator itr = find(mylist2.begin(), mylist2.end(), 0);
//    list<int>::iterator itr_a = find(mylist.begin(), mylist.end(), 1);
//    list<int>::iterator itr_b = ++find(mylist.begin(), mylist.end(), 2);
//    mylist2.splice(itr, mylist, itr_a, itr_b);  //前闭后开
//
//    for(auto it:mylist2)
//        cout<<it<<" ";
//    cout<<endl;

    /*
     * array
     */
//    array<int, 3> a = {1, 2, 3};
//    array<int, 4> b = {1, 2, 3};
//    cout<<a.size()<<endl;
//    cout<<b.size()<<endl;

    /*
     * set
     *
     * -No duplicates
     *
     * value of the elements cannot be modified
     */
//     set<int> myset;
//     for(int i=1; i<7; i+=2){
//         myset.insert(i);
//     }
//     for(auto it:myset)
//         cout<<it<<" ";
//     cout<<endl;
//     set<int>::iterator itr = myset.find(5);    //None of the sequence containers provide this kind of find
//     pair<set<int>::iterator, bool> ret;
//     ret = myset.insert(3);
//     if(ret.second == false)
//         itr = ret.first;
//     myset.insert(itr, 4);
//     myset.erase(itr);
//     myset.erase(5);    //None of the sequence containers provide this kind of erase
//     for(auto it:myset)
//         cout<<it<<" ";
//     cout<<endl;

    /*
     * multiset
     *
     * -a set allows duplicated items
     */

//     multiset<int> mset;
//     for(int i=0; i<5; i++){
//         mset.insert(i);
//     }
//     for(int i=0; i<5; i++){
//         mset.insert(i);
//     }
//     for(auto it:mset)
//         cout<<it<<" ";
//     cout<<endl;

    /*
     * map
     *
     * -No dulplicate keys
     */
//    map<char, int> mymap;
//    mymap.insert(pair<char, int>('a', 100));
//    mymap.insert(make_pair('z', 300));
//
//    map<char, int>::iterator it = mymap.begin();
//    mymap.insert(it, pair<char, int>('b', 200));
//
//    it = mymap.find('z');
//    cout<<(*it).first<<"->"<<(*it).second<<endl;
//
//    for(it = mymap.begin(); it != mymap.end(); ++it){
//        cout<<(*it).first<<"->"<<(*it).second<<endl;
//    }

    /*
     * multimap is a map that allows duplicated keys
     *
     * map/multimap :
     *
     * --keys cannot be modified
     *   multimap<char, int> mymultimap;
     *   multimap<char, int>::iterator it = mymultimap.begin();
     *   type of *it: pair<const char, int>
     *
     */

    /*
     * Unordered Associative Container(c++11)
     *
     * -Implement of Hash Table
     */

    /*
     * unordered set
     */
//    unordered_set<string> myset = {"red", "green", "blue"};
//    unordered_set<string>::const_iterator it = myset.find("green");     //  O（1）
//    if(it != myset.end())   // important check
//        cout<<*it<<endl;
//    myset.insert("yellow");     // O（1）
//
//    vector<string> vec = {"pink", "purple"};
//    myset.insert(vec.begin(), vec.end());
//
//    for(auto it:myset)      //unordered set 底层是hashtable 因此遍历myset的顺序与插入顺序不同
//        cout<<it<<" ";
//    cout<<endl;
//
//    /*
//     * Hash Table specific APIs
//     */
//    cout<<"load_factor = "<<myset.load_factor()<<endl;
//    string x = "red";
//    cout<<x<<" is in bucket #"<<myset.bucket(x)<<endl;
//    cout<<"Total bucket #"<<myset.bucket_count()<<endl;


// unordered multiset: unordered set allows duplicated elements
// unordered map: unordered set of pairs
// unordered multimap: unordered map allows duplicated elements

// hash collision => performance degrade

/*
 * Properties of Unordered Containers:
 *
 * 1. Fastest search/insert at any place: O(1)
 *      Associative container takes O(log(n))
 *      vector, deque takes O(n)
 *      list takes O(1) to insert, O(n) to search
 * 2. Unordered set/multiset: element value cannot be changed
 *    Unordered map/multimap: element key cannot be changed
 */

/*
 * Associative array
 *
 * - map and unordered map
 *
 */

//    unordered_map<char, string> week = {{'S', "Sunday"}, {'M', "Monday"}};
//
//    cout<<week['S']<<endl;  // No range check
//    cout<<week.at('S')<<endl;   // Has range check
//    cout<<endl;
//    vector<int> vec = {1, 2, 3};
////    vec[5] = 5;     //compile error
////    for(auto it:vec)
////        cout<<it<<" ";
//
//    week['W'] = "Wednesday";    //Inserting {'W', "Wedensday"} without compile error
//    week.insert(pair<char, string>('F', "Friday"));     //Inserting {'F', "Friday"}
//    week.insert(make_pair('T', "Tuesday"));
//
//    for(auto it:week)
//        cout<<it.first<<"=>"<<it.second<<endl;
//    cout<<endl;
//
//    week.insert(make_pair('M', "MONDAY"));  // Fail to modify, it's an unordered_map
//
//    week['M'] = "MONDAY";   // Success to modify
//    for(auto it:week)
//        cout<<it.first<<"=>"<<it.second<<endl;
//    cout<<endl;
//
//    foo(week);

    /*
     * Notes about Associative Array:
     * 1. Search time: unordered_map, O(1); map, O(log(n))
     * 2. unordered_map may degree to O(n)
     * 3. can't use multimap and unordered_multimap to achieve associative array, because they don't have [] operator
     */

    /*
     * Container Adaptor
     * - Provide a restricted interface to meet special needs
     * - Implemented with fundamental container classes
     *
     * 1. stack: LIFO, push(), pop(), top(), size(), empty()
     * 2. queue: FIFO, push(), pop(), front(), back(), size(), empty()
     * 3. priority queue: first item always has the grearest priority, push(), pop(), top()
     */

    /*
     * Another way of cateforizing containers
     *
     * 1. Array based containers: vector, deque
     * 2. Node based containers: list, associative containers, unordered containers
     *
     * Array based containers invalidates pointers:
     *      - Native pointers, iterators, references
     */

//    vector<int> vec = {1, 2, 3, 4};
//    int* p = &vec[2];
//    vec.insert(vec.begin(), 0);
//    cout<<*p<<endl;     //result in undefined behavior; everytime you insert or delete an element from vector,
    // the pointer previous pointed to the current element might be invaild
    // sometimes it will happend, but sometimes not
    // so it is dangerous to assume those pointers are still valid
    // so we should stop using the pointer p anymore because of the insert()
    // but Node based containers doesn't have that problem
    /*
     * Iterators
     */
    // 1. Random Access Iterator: vector, deque, array
//    vector<int> vec = {5, 4, 3, 2, 1};
//    vector<int>::iterator itr1 = vec.begin();
//    vector<int>::iterator itr2 = itr1 + 2;
//    itr1 = itr1 + 3;
//    cout<<*(itr1)<<endl;
//    cout<<*(itr2)<<endl;
//    if(itr1 < itr2)     // itr1 在 itr2 的后方
//        cout<<"itr1 < itr2";
//    else
//        cout<<"itr1 > itr2";
//    ++itr1;     // 不需返回旧值，faster than itr1++
//    --itr1;

    // 2. Bidirectional Iterator: list, set/multiset, map/multimap
    // 该类迭代器是在Forward Iterator的基础上提供了单步向后迭代元素的能力
    // 能做 ++ -- 运算；不能对iterator做 +a -a ； 不能做比较运算

//    list<int> mylist;
//    list<int>::iterator itr = mylist.begin();
//    ++itr;
//    --itr;

    // 3. Forward Iterator: forward_list
    // 该类迭代器可以在一个正确的区间中进行读写操作，它拥有Input Iterator的所有特性，和Output Iterator的部分特性，以及单步向前迭代元素的能力
    // 只能做 ++ 运算
//    forward_list<int> flist;
//    forward_list<int>::iterator itr = flist.begin();
//    ++itr;

    // Unordered containers provide "at least" forward iterators, other operations depends on the implement of the container

    // 4. Input Iterator: read and process values while iterating forward
    // 只能单步向前迭代元素，不允许修改由该类迭代器引用的元素
//    int x = *itr;

    // 5. Output Iterator: output values while iterating forward
    // 该类迭代器和Input Iterator极其相似，也只能单步向前迭代元素，不同的是该类迭代器对元素只有写的权力。
//    *itr = 100;


    // Every container has a iterator and a const_iterator
//    set<int>::iterator itr;
//    set<int>::const_iterator citr;  // Read_only access to container elements
//    set<int> myset = {2, 4, 5, 1, 9};
//    for(citr = myset.begin(); citr != myset.end(); ++citr){
//        cout<<*(citr)<<" ";
////        *citr = 3;  // error! won't compile
//    }

    // for_each是一个模板函数，将for循环语句封装起来，
    // 前面两个参数都是迭代器，第三个参数是使用一个函数指针（或仿函数），
    // 其功能是对每一个迭代器所指向的值调用仿函数。
//    for_each(itrb, itre, Printer());
//    cout<<endl;

    // Iterator Functions:
//    advance(itrb, 3);   // Move itr forward 3 spots. itrb += 3
//    cout<<distance(itrb, itre);   // Measure the distance between itrb and itre

    /*
    * Iterator Adaptor (Predefined Iterator)
    * - A special, more powerful Iterator
    * 1. Insert iterator
    * 2. Stream iterator
    * 3. Reverse iterator
    * 4. Move iterator(c++ 11)
    */

    // 1. Insert iterator:
//    vector<int> vec1 = {3, 4};
//    vector<int> vec2 = {1, 2, 5, 6};
//    vector<int>::iterator itr = find(vec2.begin(), vec2.end(), 5);
//    insert_iterator<vector<int>> i_itr(vec2, itr);
//    copy(vec1.begin(), vec1.end(), i_itr);
//
//    for(auto it:vec2)
//        cout<<it<<" ";
//    cout<<endl;
    // Other insert iterators: back_insert_iterator, front_insert_iterator

    // 2. Stream iterator
    // iterate through the data to and from the stream
//    vector<string> vec3;
//    copy(istream_iterator<string>(cin), istream_iterator<string>(), back_inserter(vec3));
//    copy(vec3.begin(), vec3.end(), ostream_iterator<string>(cout, " "));

    // Make it terse: 上面代码可整合如下。
//    copy(istream_iterator<string>(cin), istream_iterator<string>(), ostream_iterator<string>(cout, " "));


    // 3. Reverse Iterator:
//    vector<int> vec = {4, 5, 6, 7};
//    reverse_iterator<vector<int>::iterator> r_itr;
//    for(r_itr = vec.rbegin(); r_itr != vec.rend(); ++r_itr){    //prints: 7 6 5 4
//        cout<<*r_itr<<" ";
//    }

    /*
    * Algorithms
    * - mostly loops
    * 大多数algorithms是含有loop的，当使用for循环时，
    * 考虑能否使用algorithm代替循环，这样使代码简洁并增加代码效率
    */
//    vector<int> vec = {4, 2, 5, 1, 3, 9};
//    vector<int>::iterator itr = min_element(vec.begin(), vec.end());    //itr->1
//    cout<<*itr<<endl;

    // Note1: Algorithms always process ranges in a half-open way: [begin, end)
//    sort(vec.begin(), itr);  // vec: {2, 1, 5, 1, 3, 9}
//    reverse(itr, vec.end());    // vec: {2, 1, 5, 9, 1, 3}

    // Node2:
//    vector<int> vec2(3);
//    copy(vec.begin(), vec.end(), // Sourcr(range1)
//         vec2.begin());     //Destination(range2)
    // vec2 needs to have at least space for 3 elements; be careful to use this kind of function(range1, range2)!

    // Node3: insert safe but not efficient, because it insert only one element one time
//    vector<int> vec3;
//    copy(vec.begin(), vec.end(),
//         back_inserter(vec3));
    // return a back_insert_iterator

    // both efficient and safe way
//    vec3.insert(vec3.end(), vec.begin(), vec.end());

    // Note4: Algorithm with function
//    vector<int> vec = {2, 4, 5, 6, 7};
//    vector<int>::iterator itr= find_if(vec.begin(), vec.end(), isOdd);  //itr->5
//    cout<<*itr<<endl;
//
//    // Note5: Algorithm with native C++ Array
//    int arr[4] = {6, 3, 7, 4};
//    sort(arr, arr+4);
//    for(int i=0; i<end(arr)-begin(arr); ++i){   //获取数组长度两种写法
//        cout<<arr[i]<<" ";
//    }
//    cout<<endl;
//    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); ++i){
//        cout<<arr[i]<<" ";
//    }
//    cout<<endl;









    return 0;
}


//int main() {
//    int N;
//    cin>>N;
//    for(int k=0; k<N; k++){
//        vector<int> value(3);
//        map<int, vector<int>>  mymap;
//        int framenums;
//        int maxkey;
//        int max = 0;
//        cin>>framenums;
//        for(int curframe=0; curframe<framenums; curframe++){
//            int featurenums;
//            cin>>featurenums;
//            for(int j=0; j<featurenums; j++){
//                int feature[2];
//                cin>>feature[0]>>feature[1];
//                int feature_int = feature[0]*10 + feature[1];
//
//                map<int, vector<int>>::iterator it = mymap.find(feature_int);
//                if(it != mymap.end()){
//                    if(it->second.at(2) == curframe-1){
//                        it->second.at(1)++;
//                    }
//                    else{
//                        it->second.at(1) = 1;
//                    }
//                    it->second.at(2) = curframe;
//                    if(it->second.at(1) > it->second.at(0)){
//                        it->second.at(0) = it->second.at(1);
//                    }
//                }
//                else{
//                    value.at(0) = 1;
//                    value.at(1) = 1;
//                    value.at(2) = curframe;
//                    mymap.insert(make_pair(feature_int, value));
//                }
//            }
//        }
//        for(auto it:mymap){
//            if(it.second.at(0)>max){
//                max = it.second.at(0);
//            }
//        }
//        cout<<max<<endl;
//    }
//
//
//    return 0;
//}