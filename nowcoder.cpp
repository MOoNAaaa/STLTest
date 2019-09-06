//
// Created by 关智林 on 2019-04-20.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <climits>

using namespace std;
/*
 * 包含min函数的栈
 *
 * 定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
 */
class minStack{
private:
    stack<int> datastack;
    stack<int> minstack;
public:
    void push(int value) {
        datastack.push(value);
        if(minstack.empty())
            minstack.push(value);
        else if(value <= minstack.top())    // 栈空时对栈调用 top（）函数会出错！！
            minstack.push(value);

    }
    void pop() {
        if(minstack.top() == datastack.top())
            minstack.pop();
        datastack.pop();
    }
    int top() {
        return datastack.top();
    }
    int min() {
        return minstack.top();
    }
};
/*
 * 二叉树节点
 */
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
/*
 * 复杂链表节点
 */
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solusion{
public:
    /*
     * 旋转数组的最小数字(给出所有元素都大于0)
     *
     * 旋转数组分为两部分，前一半数组中的元素永远大于等于后一半数组
     * 设头指针指向前一半数组的元素， 设尾指针指向后一半数组的元素
     */
//    int minNumberInRotateArray(vector<int> array) {
//        if(array.size() <= 0)
//            return 0;
//        int pre = 0, tail = array.size() - 1;
//        int result = array[pre];
//
//        result = minNumberInRotateArray(array, pre, tail);
//        return result;
//
//    }
    /*
     * 旋转数组的最小数字：递归的方法
     */
    int minNumberInRotateArray(vector<int> array, int pre, int tail){
        if(pre > tail)
            return 0;

        int mid = (pre + tail) / 2;

        if(array[pre] < array[tail])    // 顺序数组直接返回array[pre]
            return array[pre];

        if(pre == tail - 1)     // 两个指针相邻， 即找到min
            return array[pre] < array[tail] ? array[pre] : array[tail];

        if(array[mid] == array[pre] && array[mid] == array[tail])   //特殊情况：如果下标为mid、pre和tail指向的三个数字相等，则只能顺序查找
            return *min_element(array.begin(), array.end());    // 使用stl，就不用自己写啦
//            return getMinInOrder(array, pre, tail);

        if(array[mid] <= array[tail]){      //缩小查找范围
            tail = mid;
        }
        if(array[mid] >= array[pre]){
            pre = mid;
        }

        return minNumberInRotateArray(array, pre, tail);
    }
    // 顺序查找
    int getMinInOrder(vector<int> array, int pre, int tail){
        int result = array[pre];
        for(int i=pre+1; i<=tail; i++){
            if(array[i] < result)
                result = array[i];
        }
        return result;
    }
    /*
     * 旋转数组的最小数字：迭代的方法
     */
    int minNumberInRotateArray(vector<int> rotateArray){
        if(rotateArray.size()<=0)
            return 0;
        int pre = 0, tail = rotateArray.size() - 1;
        int mid = pre;
        int result = rotateArray[mid];
        while (pre < tail){
            mid = (pre + tail) / 2;
            if(rotateArray[mid] == rotateArray[pre] && rotateArray[mid] == rotateArray[tail]){
                result =  getMinInOrder(rotateArray, pre, tail);
                break;
            }
            if(pre == tail - 1){
                result = rotateArray[pre] < rotateArray[tail] ? rotateArray[pre] : rotateArray[tail];
                break;
            }
            if(rotateArray[mid] <= rotateArray[tail]){
                tail = mid;
            }
            if(rotateArray[mid] >= rotateArray[pre]){
                pre = mid;
            }
        }
        return result;
    }

    /*
     * 斐波那契数列
     */
    int Fibonacci(int n) {
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        int fn_1 = 1;
        int fn_2 = 0;
        int result;
        for(int i=2; i<=n; i++){
            result = fn_1 + fn_2;   // f2 = f1 + f0 = 1 + 0 = 1
                                    // f3 = f2 + f1 = 1 + 1 = 2
                                    // f4 = f3 + f2 = 2 + 1 = 3
            fn_2 = fn_1;
            fn_1 = result;

        }
        return result;
    }

    /*
     * 变态跳台阶
     *
     * 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
     * 解答：也可以用逆推的思路去想，跳n级台阶，可以从n-1级直接跳上来，也可以从n-2级直接跳上来，从n-3级直接跳上来，...，从第1级直接跳上去，从第0级直接跳上去，
     * 所以，跳n级台阶的方法数相当于其它所有台阶数的方法的总和再加上从0级跳上去，
     * 表达式为
     * f(n) = f(n-1) + f(n-2) +...+ f(2) + f(1) + 1
     * f(n-1) = f(n-2) +...+ f(2) + f(1) + 1
     * f(n) - f(n-1) = f(n-1)
     * f(n) = 2 * f(n-1)
     */
    int jumpFloorII(int number) {
        if(number <= 0)
            return 0;
        int result = 1;
        for(int i=2; i<=number; i++){
            result = 2 * result;
        }
        return result;
    }
    /*
     * 矩形覆盖
     *
     * 我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
     */
    int rectCover(int number) {
        if(number <= 0)
            return 0;
        if(number == 1)
            return 1;
        if(number == 2)
            return 2;
        int result;
        int f_1 = 2;
        int f_2 = 1;
        for(int i=3; i<=number; i++){
            result = f_1 + f_2;
            f_2 = f_1;
            f_1 = result;
        }
        return result;
    }

    /*
     * 二进制中1的个数
     *
     * 输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
     *
     * 为了避免死循环，我们可以不右移输入的数字i：
     *    （1）首先把i和1做与运算，判断i的最低位是不是为1。
     * 　　（2）接着把1左移一位得到2，再和i做与运算，就能判断i的次低位是不是1。
     * 　　（3）这样反复左移，每次都能判断i的其中一位是不是1。
     *
     * PS：这个解法中循环的次数等于整数二进制的位数，32位的整数需要循环32次。
     */
    int  NumberOf1(int n) {
        int flag = 0x1;
        int count = 0;
        while(flag){
            if(n & flag)
                count++;
            flag = flag << 1;
        }
        return count;
    }
    /*
     * 二进制中1的个数
     *
     * 输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
     *
     * 把一个整数减去1，再和原整数做与运算，会把该整数最右边一个1变成0。
     * 那么一个整数的二进制表示中有多少个1，就可以进行多少次这样的操作。
     *
     */
    int  NumberOf1II(int n) {
        int count = 0;
        while (n){
            n = (n-1) & n;
            count++;
        }
        return count;
    }
    /*
     * 顺时针打印矩阵
     *
     * 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
     * 例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
     * 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
     */
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> result;
        int row = matrix.size()-1;
        int column = matrix[0].size()-1;
        printMatrix(matrix, result, 0, row, 0, column);
        return result;
    }
    void printMatrix(vector<vector<int> > matrix, vector<int> &result, int row1, int row2, int column1, int column2) {
        int rows = row2 - row1;
        int columns = column2 - column1;
        if(rows < 0 || columns < 0)
            return;
        if(rows == 0){
            for(int i=column1; i<=column2; i++){
                result.push_back(matrix[row1][i]);
            }
            return;
        }
        if(columns == 0){
            for(int i=row1; i<=row2; i++){
                result.push_back(matrix[i][column1]);
            }
            return;
        }
        for(int i=column1; i<column2; i++){
            result.push_back(matrix[row1][i]);
        }
        for(int i=row1; i<row2; i++){
            result.push_back(matrix[i][column2]);
        }
        for(int i=column2; i>column1; i--){
            result.push_back(matrix[row2][i]);
        }
        for(int i=row2; i>row1; i--){
            result.push_back(matrix[i][column1]);
        }
        if(rows > 1 && columns > 1){
            printMatrix(matrix, result, row1+1, row2-1, column1+1, column2-1);
        }

    }

    /*
     * 从上往下打印二叉树（层序遍历二叉树）
     *
     * 从上往下打印出二叉树的每个节点，同层节点从左至右打印。
     */
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> result;
        if(root == NULL)
            return result;
        queue<TreeNode*> q;

        q.push(root);
        while (!q.empty()){
            TreeNode* p = q.front();
            result.push_back(q.front()->val);
            q.pop();
            if(p->left){
                q.push(p->left);
            }
            if(p->right){
                q.push(p->right);
            }
        }
        return result;
    }
    /*
     * 二叉搜索树的后序遍历序列
     *
     * 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
     */
    bool VerifySquenceOfBST(vector<int> sequence) {
        bool result = false;
        if(sequence.size()<=0)
            return result;
        int begin = 0, end = sequence.size()-1;
        result = VerifySquenceOfBST(sequence, begin, end);
        return result;

    }
    bool VerifySquenceOfBST(vector<int> sequence, int begin, int end){
        bool flag = true;
        if(begin >= end || begin <0 || end < 0)
            return flag;
        int lb = begin;
        int le = lb;
        int rb = 0, re = end-1;
        int rootval = sequence.at(re+1);
        for(int i=lb; i<=re; i++){
            if(sequence.at(i) < rootval){
                le++;
            }
            else
                break;

        }
        le--;
        rb = le+1;
        for(int i=rb; i<=re; i++){
            if(sequence.at(i) <= rootval){
                flag = false;
                return flag;
            }
        }
        return VerifySquenceOfBST(sequence, lb, le) && VerifySquenceOfBST(sequence, rb, re);
    }
    /*
     * 二叉树中和为某一值的路径(没过)
     *
     * 输入一颗二叉树的根节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
     * 路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
     * (注意: 在返回值的list中，数组长度大的数组靠前)
     *
     */
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int> > result;
        vector<int> path;
        int currentSum = 0;
        FindPath(root, expectNumber, result, path, currentSum);
        return result;
    }
    void FindPath(TreeNode* root, int expectNumber, vector<vector<int>> result, vector<int> path, int currentSum) {
        if(root == NULL)
            return;
        currentSum += root->val;
        path.push_back(root->val);
        bool isLeaf = root->left==NULL && root->right==NULL;
        if(currentSum == expectNumber){
            if(result.size()<=0){
                result.push_back(path);
            }
            else{
                for(int i=0; i<result.size(); i++){
                    if(path.size() <= result[i].size()){
                        result.insert(result.begin()+i, path);
                    }
                }
            }
        }
        if(isLeaf)
            return;
        if(root->left){
            FindPath(root->left, expectNumber, result, path, currentSum);
        }
        if(root->right){
            FindPath(root->right, expectNumber, result, path, currentSum);
        }
    }
    /*
     * 复杂链表的复制
     *
     * 输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
     * 返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
     */
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == NULL)
            return NULL;
        RandomListNode* result;
        RandomListNode* cur = pHead;    // 待复制节点指针
        // 先复制头节点
        RandomListNode* node = (RandomListNode*)malloc(sizeof(RandomListNode));
        node->label = cur->label;
        node->next = cur->next;
        node->random = cur->random;

        result = node;
        RandomListNode* temp = result;  // 拷贝链表的尾节点
        cur = cur->next;
        while (cur){
            RandomListNode* node = (RandomListNode*)malloc(sizeof(RandomListNode));
            node->label = cur->label;
            node->next = cur->next;
            node->random = cur->random;

            temp->next = node;
            temp = temp->next;
            cur = cur->next;
        }
        return result;
    }
    RandomListNode* Create(){
        int n;
        int val;
        cin>>n;
        RandomListNode* head;
        cin>>val;
        RandomListNode* node = (RandomListNode*)malloc(sizeof(RandomListNode));
        node->label = val;
        node->next = NULL;
        node->random = NULL;
        head = node;
        RandomListNode* cur = head;
        for (int i = 1; i < n; ++i) {
            cin>>val;
            RandomListNode* node = (RandomListNode*)malloc(sizeof(RandomListNode));
            node->label = val;
            node->next = NULL;
            node->random = NULL;

            cur->next = node;
            cur->random = node;

            cur = cur->next;

        }
        return head;
    }
    void PrintRandomList(RandomListNode* head){
        RandomListNode* cur = head;
        while (cur){
            cout<<cur->label<<endl;
            cur = cur->next;
        }
    }
    /*
     * 数组中出现次数超过一半的数字
     *
     * 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
     * 例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
     * 由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
     *
     */
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.size() <= 0)
            return 0;
        int result = numbers[0];
        int count = 1;
        for(int i=1; i<numbers.size()-1; ++i){
            if(numbers[i] == result){
                if(count>=1){
                    count++;
                }
            } else{
                if(count==1){
                    result = numbers[i];
                } else if(count>1){
                    count--;
                }
            }
        }
        if(count>1 || (count==1 && numbers.back() == result))
            return result;
        return 0;
    }
    /*
     * 连续子数组的最大和
     *
     * 注意考虑数组中全是负数的情况
     */
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.size() <= 0)
            return 0;
        int result = 0;
        int temp = 0;
        int curi = -1;
        bool hasPositiveNumber = false;
        int max = array.at(0);
        for (int i = 0; i < array.size(); ++i) {
            if(array.at(i) > 0){
                hasPositiveNumber = true;
            }
            if(array.at(i) > max){
                max = array.at(i);
            }
            if(temp + array.at(i) > 0){     // 6,-3,-2,7,-15,1,2,2
                if(curi == i-1){
                    temp += array.at(i);
                    curi++;
                } else{
                    temp = array.at(i);
                    curi = i;
                }
            }
            if(temp > result){
                result = temp;
            }
        }
        if(hasPositiveNumber == false)
            return max;
        return result;
    }
    int FindGreatestSumOfSubArrayII(vector<int> array) {
        if(array.size() <= 0)
            return 0;
        int result = INT_MIN;
        vector<int> sum(array.size(), INT_MIN);
        sum.at(0) = array.at(0);
        for (int i=1; i<array.size(); ++i){
            if(sum.at(i-1) < 0){
                sum.at(i) = array.at(i);
            } else{
                sum.at(i) = sum.at(i-1) + array.at(i);
            }
        }
        for (int j = 0; j < sum.size(); ++j) {
            if(sum.at(j) > result)
                result = sum.at(j);
        }
        return result;
    }
    /*
     * 最小的K个数
     *
     * 输入n个整数，找出其中最小的K个数。
     * 例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
     *
     */
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> result;
        multiset<int, greater<int> > minK;
        if(input.size() < k){
            return result;
        }
        else{
            for(int i=0; i<k; ++i){
                minK.insert(input.at(i));
            }
            for(int i=k; i<input.size(); ++i){
                if(input.at(i) < *minK.begin()){
                    minK.erase(*minK.begin());
                    minK.insert(input.at(i));
                }
            }
            multiset<int>::iterator it = minK.begin();
            for(; it != minK.end(); ++it){
                result.push_back(*it);
            }
        }
        return result;
    }
    /*
     * 整数中1出现的次数（从1到n整数中1出现的次数）
     *
     * 求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
     * 为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。
     * ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）。
     *
     */
    int NumberOf1Between1AndN_Solution(int n)
    {
        int result = 0;

    }
    };

int main(){
//    vector<int> vec;
//    int n;
//    int val;
//    while(cin>>n){
//        for(int i=0; i<n; i++){
//            cin>>val;
//            vec.push_back(val);
//        }
//        Solusion solusion;
//        int result = solusion.minNumberInRotateArray(vec);
//        cout<<"result: "<<result<<endl;
//    }

//    int n;
//    Solusion solusion;
//    while (cin>>n){
//        cout<<solusion.Fibonacci(n)<<endl;
//    }

//    int n;
//    Solusion solusion;
//    while (cin>>n){
//        cout<<solusion.jumpFloorII(n)<<endl;
//    }

//    int n;
//    Solusion solusion;
//    while (cin>>n){
//        cout<<solusion.rectCover(n)<<endl;
//    }

//    int n;
//    Solusion solusion;
//    while (cin>>n){
//        cout<<solusion.NumberOf1(n)<<endl;
//    }

//    int n;
//    Solusion solusion;
//    while (cin>>n){
//        cout<<solusion.NumberOf1II(n)<<endl;
//    }

//    Solusion solusion;
//
//    int m, n;
//    int val;
//    while (cin>>m>>n){
//        vector<vector<int>> vec(m, vector<int>(n));
//        for(int i=0; i<m; i++){
//            for(int j=0; j<n; j++){
//                cin>>val;
//                vec[i][j] = val;
//            }
//        }
//        vector<int> result;
//        result = solusion.printMatrix(vec);
//        for(auto it:result){
//            cout<<it<<" ";
//        }
//        cout<<endl;
//    }

//    minStack minstack;
//    int n;
//    int val;
//    while (cin>>n){
//        for(int i=0; i<n; i++){
//            cin>>val;
//            minstack.push(val);
//            cout<<minstack.min()<<endl;
//        }
//
//    }

//    Solusion solusion;
//    int n;
//    int val;
//    while (cin>>n){
//        vector<int> vec;
//        for(int i=0; i<n; i++){
//            cin>>val;
//            vec.push_back(val);
//        }
//        bool result = solusion.VerifySquenceOfBST(vec);
//        cout<<result<<endl;
//
//    }

//    Solusion solusion;
//    RandomListNode* head = solusion.Create();
//    solusion.PrintRandomList(head);
//    RandomListNode* result = solusion.Clone(head);
//    solusion.PrintRandomList(result);

//    Solusion solusion;
//    int n;
//    int val;
//    while (cin>>n){
//        vector<int> vec;
//        for(int i=0; i<n; ++i){
//            cin>>val;
//            vec.push_back(val);
//        }
//        int result = solusion.MoreThanHalfNum_Solution(vec);
//        cout<<result<<endl;
//    }

//    Solusion solusion;
//    int n;
//    int val;
//    while (cin>>n){
//        vector<int> vec;
//        for (int i = 0; i < n; ++i) {
//            cin>>val;
//            vec.push_back(val);
//        }
//        int result = solusion.FindGreatestSumOfSubArray(vec);
//        cout<<result<<endl;
//    }

//    Solusion solusion;
//    int n;
//    int val;
//    while (cin>>n){
//        vector<int> vec;
//        for (int i = 0; i < n; ++i) {
//            cin>>val;
//            vec.push_back(val);
//        }
//        int result = solusion.FindGreatestSumOfSubArrayII(vec);
//        cout<<result<<endl;
//    }

    Solusion solusion;
    int n, k;
    int val;
    while (cin>>n>>k){
        vector<int> vec;
        for (int i = 0; i < n; ++i) {
            cin>>val;
            vec.push_back(val);
        }
        vector<int> result = solusion.GetLeastNumbers_Solution(vec, k);
        for(auto it:result){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    return 0;
}