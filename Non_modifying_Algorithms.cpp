//
// Created by 关智林 on 2019-04-27.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 *
 * STL Algorithms #1:
 *
 *      不修改数据的算法（Non-modifying Algorithms）
 *      count, min an max, compare, linear search, attribute
 */

bool lessThan10(int  x){
    return x<10;
}
int main(){
    // C++ 11 Lambda Function: a function without name
    vector<int> vec = {9, 60, 90, 8, 45, 87, 90, 69, 69, 55, 7};
        // doing the same thing as lessThan10(int x)
    int num = count_if(vec.begin(), vec.end(), [](int x){ return x<10;});
    cout<<"num: "<<num<<endl;

    /*
     * 1. 计数（Counting）
     */

    // Algorithm 的基本结构：Algorithm    Data    Operation
    // Algorithm：count_if
    // Data：vec.begin(), vec.end()
    // Operation：[](int x){return x<10;}
    // 大多数算法有一个简单形式和一个更通用的形式
    // 通用形式:    count()    count_if()

        // 2， 对vector下标从[vec.begin()+2，vec.end()-1）中等于'69'的元素进行计数，返回个数。
    int n = count(vec.begin()+2, vec.end()-1, 69);
        // 2，same as previous row
    int n1 = count_if(vec.begin()+2, vec.end()-1, [](int x){ return x==69;});
        // 3，对所有小于10对元素计数
    int m = count_if(vec.begin(), vec.end(), [](int x){return x<10;});

    /*
     * 2. Min and Max
     */

    // 通用形式:     max_element()      min_element()        minmax_element()
    vector<int>::iterator itr = max_element(vec.begin(), vec.end());    // 90
        // 9，自定义比较函数
    vector<int>::iterator itr2 = max_element(vec.begin(), vec.end(),
                                             [](int x, int y){ return (x%10) < (y%10);});

    cout<<"itr: "<<*itr<<endl;
    cout<<"itr2: "<<*itr2<<endl;
    vector<int>::iterator itr3 = min_element(vec.begin(), vec.end());   // 7
        // 9，自定义比较函数
    vector<int>::iterator itr4 = min_element(vec.begin(), vec.end(),
                                             [](int x, int y){ return (x%10) > (y%10);});
    cout<<"itr3: "<<*itr3<<endl;
    cout<<"itr4: "<<*itr4<<endl;

    pair<vector<int>::iterator, vector<int>::iterator> pair_of_itr = minmax_element(vec.begin(), vec.end());    // {7, 69}
        // 返回一个pair, 包含第一个最小值和最后一个最大值
    pair<vector<int>::iterator, vector<int>::iterator> pair_of_itr2 = minmax_element(vec.begin(), vec.end(),
                                          [](int x, int y){ return (x%10)<(y%10);});        // {60, 69}

    cout<<"pair_of_itr: "<<*pair_of_itr.first<<" "<<*pair_of_itr.second<<endl;
    cout<<"pair_of_itr2: "<<*pair_of_itr2.first<<" "<<*pair_of_itr2.second<<endl;

    /*
     * 3. 线性搜索（数据未排序时使用）（Linear Searching（used when data is not sorted））
     */

    // 通用形式:    find()      find_if()
    //  Returns the first match data
    //  vector<int> vec = {9, 60, 90, 8, 45, 87, 90, 69, 69, 55, 7};
    vector<int>::iterator itr5 = find(vec.begin(), vec.end(), 55);
    vector<int>::iterator itr6 = find_if(vec.begin(), vec.end(), [](int x){ return x>80;});
    vector<int>::iterator itr7 = find_if_not(vec.begin(), vec.end(), [](int x){ return x>80;});

    cout<<"itr5: "<<*itr5<<endl;
    cout<<"itr6: "<<*itr6<<endl;
    cout<<"itr7: "<<*itr7<<endl;

    // 通用形式: search_n()
        // 连续（consecutive）2个等于69的元素
    vector<int>::iterator itr8 = search_n(vec.begin(), vec.end(), 2, 69);
    cout<<"itr8: "<<*itr8<<" itr8+1: "<< *(itr8+1)<<endl;

    // 搜索子串(Search subrange)
    // 通用形式:    search()    find_end()
    vector<int> sub = {45, 87, 90};
        // 搜索第一个匹配的子串 search first subrange（ *itr9: 45 87 90 69 69 55 7 ）
    vector<int>::iterator itr9 = search(vec.begin(), vec.end(),
                                        sub.begin(), sub.end());
    cout<<"*itr9: ";
    for(; itr9 != vec.end(); ++itr9)
        cout<<*itr9<<" ";
    cout<<endl;

        // 搜索最后一个匹配的子串（ *itr10: 45 87 90 69 69 55 7 ）
    vector<int>::iterator itr10 = find_end(vec.begin(), vec.end(),
                                        sub.begin(), sub.end());
    cout<<"*itr10: ";
    for(; itr10 != vec.end(); ++itr10)
        cout<<*itr10<<" ";
    cout<<endl;

    //  搜索任意一个（Search any of）
    vector<int> items = {87, 2};
        // 搜索任意一个在items中的元素（ *itr11: 87 90 69 69 55 7 ）
    vector<int>::iterator itr11 = find_first_of(vec.begin(), vec.end(),
                                                items.begin(), items.end());
    cout<<"*itr11: ";
    for(; itr11 != vec.end(); ++itr11)
        cout<<*itr11<<" ";
    cout<<endl;
        // 搜索任意一个在items中的元素，且满足谓词"x==y*4"（ *itr12: 8 45 87 90 69 69 55 7  ）
    vector<int>::iterator itr12 = find_first_of(vec.begin(), vec.end(),     // x
                                                items.begin(), items.end(), // y
                                                [](int x, int y){ return x==y*4;});
    cout<<"*itr12: ";
    for(; itr12 != vec.end(); ++itr12)
        cout<<*itr12<<" ";
    cout<<endl;

    // 搜索相邻（Search Adjacent）
        // 搜索相邻两个相同的元素( find two adjacent items that are same )（ *itr13: 69 69 55 7 ）
    vector<int>::iterator itr13 = adjacent_find(vec.begin(), vec.end());
    cout<<"*itr13: ";
    for(; itr13 != vec.end(); ++itr13)
        cout<<*itr13<<" ";
    cout<<endl;
        // find two adjacent items that satisfy: x==y*4（ *itr14: 60 90 8 45 87 90 69 69 55 7 ）
    vector<int>::iterator itr14 = adjacent_find(vec.begin(), vec.end(),
                                                 [](int x, int y){ return y==x*1.5;});
    cout<<"*itr14: ";
    for(; itr14 != vec.end(); ++itr14)
        cout<<*itr14<<" ";
    cout<<endl;

    /*
     * 4. 范围比较（Comparing Ranges）
     */
    // 通用形式：equal()     is_permutation()    mismatch()      lexicographical_compare()
    vector<int> vec2 = {60, 9, 90, 8, 45, 87, 90, 69, 69, 55, 7};
    if(equal(vec.begin(), vec.end(), vec2.begin())){
        cout<<"vec and vec2 are same.\n";
    }else{
        cout<<"vec and vec2 are not same.\n";
    }
    if(is_permutation(vec.begin(), vec.end(), vec2.begin())){
        cout<<"vec and vec2 have same items, but in different order.\n";
    }else{
        cout<<"vec and vec2 have different items.\n";

    }

        // 找到第一个不同的元素
        // pair_of_itr3.first是vec的迭代器
        // pair_of_itr3.second是vec2的迭代器
    pair<vector<int>::iterator, vector<int>::iterator> pair_of_itr3 = mismatch(vec.begin(), vec.end(), vec2.begin());
    cout<<"pair_of_itr3.first: "<<*pair_of_itr3.first<<endl<<"pair_of_itr3.second: "<<*pair_of_itr3.second<<endl;

        // 按字典序比较: 用"less than"逐元素比较
        // {1,2,3,5} < {1,2,4,5}
        // {1,2} < {1,2,3}
    if(lexicographical_compare(vec.begin(), vec.end(), vec2.begin(), vec2.end())){
        cout<<"vec is less than vec2.\n";

    } else{
        cout<<"vec2 is less than vec.\n";

    }

    /*
     * 检查属性（Check Attributes）
     */
    // 通用形式: is_sorted(), is_sorted_until(), is_heap(), is_heap_until()

    // vector<int> vec = {9, 60, 90, 8, 45, 87, 90, 69, 69, 55, 7};
    // 检查vec是否有序
    if(is_sorted(vec.begin(), vec.end())){
        cout<<"vec is sorted.\n";
    }else{
        cout<<"vec is not sorted.\n";

    }
        // itr指向第一个不满足排序的元素（ *itr15: 8 ）
    vector<int>::iterator itr15 = is_sorted_until(vec.begin(), vec.end());
    cout<<"*itr15: "<<*itr15<<endl;

        // 检查vec是否由谓词的条件分成了两个部分(x>80)
    if(is_partitioned(vec.begin(), vec.end(), [](int x){ return x<80;})){
        cout<<"vec can parted according to the condition of x>80.\n";
    }else{
        cout<<"vec can not parted according to the condition of x>80.\n";

    }

        // 检查vec是否是一个堆，heap（default：大根堆）
    if(is_heap(vec.begin(), vec.end())){
        cout<<"vec is a heap.\n";
    }else{
        cout<<"vec is not a heap.\n";

    }
        // 返回第一个不是堆的元素位置
    vector<int>::iterator itr16 = is_heap_until(vec.begin(), vec.end());
    cout<<"*itr16: "<<*itr16<<endl;

    // all, any, none
        // 所有的元素都满足
    if(all_of(vec.begin(), vec.end(), [](int x){ return x<99;})){
        cout<<"all of items in vec are less than 99.\n";
    }else{
        cout<<"not all of items in vec are less than 99.\n";
    }
        // 任意一个元素满足
    if(any_of(vec.begin(), vec.end(), [](int x){ return x>89;})){
        cout<<"vec has at least one items that are greater than 89.\n";
    }else{
        cout<<"vec has not even one items that are greater than 89.\n";
    }
        // 所有元素都不满足
    if(none_of(vec.begin(), vec.end(), [](int x){ return x>89;})){
        cout<<"vec has not even one items that are greater than 89.\n";
    }else{
        cout<<"vec has at least one items that are greater than 89.\n";
    }
    return 0;
}
