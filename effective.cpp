//
// Created by 关智林 on 2019-04-27.
//

#include <iostream>

using namespace std;
class Text{
private:
    mutable int x;

public:
     int length() const;
};
int Text::length() const{   // const 成员函数内不能更改对象内任何non-static成员变量， 解决办法之一，为成员变量增加 mutable 关键字
    x = 5;
    return x;
}

int main(){
    Text text;
    int result = text.length();
    cout<<result;
    return 0;
}
