////
//// Created by 关智林 on 2019-04-20.
////
//
#include <iostream>
#include <bitset>
#include <fstream>
//
using namespace std;
//
int main(){
    // C++ Input / Output Library -- Stream
    cout<<"stream1"<<endl;
    // cout : a global object of ostream ( typedef basic_ostream<char> ostream)
    // << : ostream& ostream::operator<< (string v);
    // endl : '\n' + flush

    // what is stream ? Serial IO Interface to external devices (file, stdin/stdout, network, etc.)
    string s("Hello");
    s[3] = 't';   // Random access
//    cout[3] = 't';    // Error, serial object can't be random accessed

    {
        ofstream of("Mylog.txt");   // create a new file for write, if the file doesn't exist.

        of << "Experience is the mother of wisdom" << endl;     // 向文件写入字符串
        of << 234 << endl;                                      // 向文件写入整数
        of << 2.3 << endl;                                      // 向文件写入浮点数

        of << bitset<8>(14) << endl;                            // 00001110; 用8位二进制数表示14
       // of << complex<int>(2, 3) << endl;                       // 向文件写入复数
    }   // RAII（Resource Acquisition is Initialization）c++会在代码块结束后自动运行RAII机制，对ofstream进行资源回收
           // 直译过来是“资源获取即初始化”，也就是说在构造函数中申请分配资源，在析构函数中释放资源
           // 是c++等编程语言常用的管理资源、避免内存泄露的方法。它保证在任何情况下，使用对象时先构造对象，最后析构对象。

    /*
     * IO Operation:
     * formatting the data <-----> communicating the data with external devices
     * 一个模块负责标准化数据，一个模块负责与外设进行数据通信
     * 两个模块间尽可能低耦合
     * Software Engineer Principle: Low Coupling -> Reusability(低耦合 提升 重用性)
     * (one module hands on formatting data; one module hands on communicating data with external devices)
     * (the two module are decoupled with each other as much as possible)
     *
     */
    /*
     * 从文件尾写入文件
     */
    {
//        ofstream of("Mylog.txt");   // Open file for write, clear the content of the file （输入会覆盖文件内容，即输入指针指向文件开头）
        ofstream of("Mylog.txt", ofstream::app);     // Move the output pointer to the end of the file
        of << "Honexty is the best policy." << endl;

    }
    /*
     * 从文件指定位置写入文件
     */
    {
        ofstream of("Mylog.txt", ofstream::in | ofstream::out);
        of.seekp(10, ios::beg);// 从文件头第10个字符位置写入文件
        of << "12345";
        of.seekp(-5, ios::end);// 从文件尾倒数第5个字符位置写入文件
        of << "Nothing ventured, nothing gained.";
        of.seekp(-5, ios::cur);// move the output pointer 5 chars before current position
    }
    /*
     * 输入文件流
     */
    ifstream inf("Mylog.txt");
    char i;
    inf >> i;   // read one word to i;
    cout<< i;
    // 错误状态： goodbit, badbit, failbit, eofbit
    inf.good(); // if return true, everything is OK (goodbit == 1)
    inf.bad(); // if return true, 不可恢复的错误 (badbit == 1)
    inf.fail(); // if return true, 失败的流操作，往往可恢复 （badbit == 1， failbit == 1）
    inf.eof(); // if return true, 到达文件尾 (eofbit == 1)

    inf.clear(); // 清除所有错误状态， 相当于 inf.clear(ios::goodbit)
    inf.clear(ios::badbit); //将错误标志 badbit 设置为 1 ， 将其他所有错误状态设置为 0

    inf.rdstate(); //读当前状态flag
    inf.clear(inf.rdstate() & ~ios::failbit);   //只清除failbit位, 其他保留

    return 0;
}