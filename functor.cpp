//
// Created by 关智林 on 2019-04-16.
//
#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <deque>
#include <algorithm>
#include <regex>

using namespace std;

/*
 * Function Objects(functors)  Using a class instance as a function
 *
 * Example:
 */
class X{
public:
    void operator()(string str){    //functor
        cout<<"Calling functor X with parameter "<<str<<endl;
    }
    operator string()const{        //type conversion function, don't confuse functor with type conversion function
        return "X";
    }
};
/*
 * Benefits of functor:
 * 1. Smart function: capabilities beyond operator()
 *    It can define its own member data to remember state.
 * 2. It can have its own type.
 */

/*
 * Parameterized Function
 */
class XX{
public:
    XX(int i){}
    void operator()(string str, int i){    //functor
        cout<<"Calling functor XX with parameter "<<str<<" and "<<i<<endl;
    }
};
void add(int i){
    cout<<i+2<<endl;
}
template <int val>
void addVal(int i){
    cout<<val + i<<endl;
}
class AddValue{
    int val;
public:
    AddValue(int j):val(j){}
    void operator()(int i){
        cout<<i+val<<endl;
    }
};
void addVAL(int i, int val){
    cout<< i + val <<endl;
}
// Convert a regular function to a functor
double Pow(double x, double y){
    return pow(x, y);
}

bool needCopy(int x){
    return (x>20)||(x<5);
}

bool lsb_less(int x, int y){
    return (x % 10) < (y % 10);
}

class Lsb_less{
public:
    bool operator()(int x, int y){
        return (x % 10) < (y % 10);
    }
};

class NeedCopy{
public:
    bool operator()(int x){
        return (x > 20) || (x < 5);
    }
};

int main(){
    X foo;
    foo("Hi");       //Using foo as a function

    XX foo2(8);
    foo2("Hi", 5);

    vector<int> vec = {2, 3, 4, 5};
    for_each(vec.begin(), vec.end(), add);   //vec = {4, 5, 6, 7}

    // for_each传入的函数只能接受有一个参数，
    // 当我们想实现add 给定值时，需要重新定义函数add（），或者为add（）添加一个全局变量val
    // 这样很麻烦，并且容易出错，
    // 我们也可以使用template为add（）传进一个参数，但是通过template传参只能是编译期常量，仍然不能传变量
    int x = 3;
    for_each(vec.begin(), vec.end(), addVal<2>);
    //for_each(vec.begin(), vec.end(), addVal<x>);    // can't compile， x is a variable
    // 我们可以借助functor实现上述功能
    for_each(vec.begin(), vec.end(), AddValue(x));
    cout<<endl;
    /*
     * Build-in Functors
     *
     * less（<）, greater(>), greater_equal(>=), less_equal(<=), not_equal_to(!=)
     * logical_and, logical_not, logical_or
     * multiplies（乘）, minus（减）, plus（加）, divide（除）, modulus(取模), negate（取负）
     */
    int a = multiplies<int>()(3, 4);    // a = 3 * 4
    if(not_equal_to<int>()(a, 10)){     // if(a != 10)
        cout<<a<<endl;
    }

    /*
     * Parameter Binding
     */
    set<int> myset = {2, 3, 4, 5};
    vector<int> vec2;

    int b = multiplies<int>()(3, 4);
    // multiplies需要传入两个参数，transform只能向函数传入一个参数，
    // 借助 bind 和 placeholders 可以实现
    // Multiply myset's elements by 10 and save in vec2
    transform(myset.begin(), myset.end(),    // source
            back_inserter(vec2),             // destination
            bind(multiplies<int>(), placeholders::_1, 10)); // functor
            // multiplies<int>() 的第一个参数是 myset 里的元素
            // vec2: {20, 30, 40, 50}
    for(auto it:vec2)
        cout<<it<<" ";
    cout<<endl;
    // 使用 bind（）可以实现我们之前想实现的两个元素相加
    int c = 2;
    for_each(vec.begin(), vec.end(), bind(addVAL, placeholders::_1, c));

    // Convert a regular function to a functor
    set<int> myset2 = {3, 1, 25, 7, 12};
    deque<int> mydeque;
    auto f = function<double (double, double)>(Pow);        // C++ 11   function<返回值类型 （参数类型， 参数类型，...）>（函数名）
    transform(myset2.begin(), myset2.end(),
            back_inserter(mydeque),
            bind(f, placeholders::_1, 2));
            // mydeque: {1, 9, 49, 144, 625}
    for(auto it:mydeque)
        cout<<it<<" ";
    cout<<endl;

    // when(x > 20) || (x < 5), copy from myset2 to mydeque2
    deque<int> mydeque2;

    transform(myset2.begin(), myset2.end(),       // source
            back_inserter(mydeque2),              // destination
            bind(logical_or<bool>(),
                    bind(greater<int>(), placeholders::_1, 20),
                    bind(less<int>(), placeholders::_1, 5))
             );       //代码可读性差，因为只有一个变量，或许重新构造一个函数较好
    for(auto it:mydeque2)
        cout<<it<<" ";
    cout<<endl;

    // when(x > 20) || (x < 5), copy from myset2 to mydeque3
    // 使用函数
    deque<int> mydeque3;
    transform(myset2.begin(), myset2.end(),        // source
            back_inserter(mydeque3),               // destination
            needCopy);
    for(auto it:mydeque3)
        cout<<it<<" ";
    cout<<endl;

    // when(x > 20) || (x < 5), copy from myset2 to mydeque4
    // 使用 lambda function: (c++11)
    deque<int> mydeque4;
    transform(myset2.begin(), myset2.end(),  //source
            back_inserter(mydeque4),         //destination
            [](int x){return (x>20)||(x<5);}
            );
    for(auto it:mydeque4)
        cout<<it<<" ";
    cout<<endl;

    /*
     * Why do we need functor in STL ?
     *
     * set default with a functor less
     */
    set<int> myset3 = {3, 1, 25, 7, 12};      // myset3: {1, 3, 7, 12, 25}
    // same as:
    set<int, less<int>> myset4 =  {3, 1, 25, 7, 12};   // myset4: {1, 3, 7, 12, 25}

//    set<int, lsb_less> myset5 = {3, 1, 25, 7, 12};    //won't compile,
//    set<>的第二个参数类型是一个function type，而不是一个function 或者 function pointer
//    因此我们需要构造一个functor
    set<int, Lsb_less> myset5 = {3, 1, 25, 7, 12};     // myset5: {1, 12, 3, 25, 7} (按照个位数排序)
    for(auto it:myset5)
        cout<<it<<" ";
    cout<<endl;
    /*
     * Predicate    : Predicate is used for comparision or condition check
     *
     * A functor or function that:
     *  1. Returns a boolean
     *  2. Does not modify data
     */
     deque<int> mydeque5;
     transform(myset3.begin(), myset3.end(),
             back_inserter(mydeque5),
             NeedCopy());
     for(auto it:mydeque5)
         cout<<it<<" ";
     cout<<endl;

    return 0;
}


