//
// Created by 关智林 on 2019-04-28.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

/*
 *
 * STL Algorithms #2:
 *
 *      修改数据的算法（Modifying Algorithms）
 *      copy, move, transform, swap, fill, replace, remove
 *
 */
int main(){
    vector<int> vec = {9, 60, 70, 8, 45, 87, 90};   // 7 items
    vector<int> vec2 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};   // 11 items
    vector<int>::iterator itr, itr2;
    pair<vector<int>::iterator, vector<int>::iterator> pair_of_itr;

    /*
     * 1. Copy
     */

    // 拷贝所有元素
    copy(vec.begin(), vec.end(),  // source
            vec2.begin());        // destination
    // vec2: 9 60 70 8 45 87 90 0 0 0 0

    cout<<"vec2: ";
    for(itr2 = vec2.begin(); itr2 != vec2.end(); ++itr2){
        cout<<*itr2<<" ";
    }
    cout<<endl;

    memset(vec2.data(), 0, sizeof(int)*vec2.size());    // vec2 中所有元素置 0

    // 拷贝满足条件的元素
    copy_if(vec.begin(), vec.end(),    // source
            vec2.begin(),              // destination
            [](int x){ return x>80;}); // condition
    // vec2: 87 90 0 0 0 0 0 0 0 0 0

    cout<<"vec2: ";
    for(itr2 = vec2.begin(); itr2 != vec2.end(); ++itr2){
        cout<<*itr2<<" ";
    }
    cout<<endl;

    memset(vec2.data(), 0, sizeof(int)*vec2.size());

    // 拷贝 n 个元素
    copy_n(vec.begin(), 4, vec2.begin());
    // vec2: 9 60 70 8 0 0 0 0 0 0 0

    cout<<"vec2: ";
    for(itr2 = vec2.begin(); itr2 != vec2.end(); ++itr2){
        cout<<*itr2<<" ";
    }
    cout<<endl;

    memset(vec2.data(), 0, sizeof(int)*vec2.size());

    // 从后往前拷贝元素
    copy_backward(vec.begin(), vec.end(),
                    vec2.end());
    // vec2: 0 0 0 0 9 60 70 8 45 87 90

    cout<<"vec2: ";
    for(itr2 = vec2.begin(); itr2 != vec2.end(); ++itr2){
        cout<<*itr2<<" ";
    }
    cout<<endl;

    /*
     * 2. Move
     */





    return 0;
}
