/*
 * @Descripttion: Essencial C++ execise 2.3
 * @version: 
 * @Author: Lugy
 * @Date: 2023-06-13 21:50:08
 * @LastEditors: Andy
 * @LastEditTime: 2023-06-14 20:18:28
 */

#include <vector>
#include <string>
#include <iostream>

using namespace std;


inline bool calc_elements(vector<int> &vec, int pos);

void really_calc_elems( vector<int> &vec, int pos );

void display_elems(vector<int> &vec, const string &title, ostream &os=cout, int iNum=0);


int main(void)
{
    vector<int> pent;
    const string title("Pentagonal Numeric Series");

    if(calc_elements(pent, 0))
        display_elems(pent, title);
    
    if(calc_elements(pent, 10))
        display_elems(pent, title);
    
    if(calc_elements(pent, 5))
        // display_elems(pent, title); // 上一次已经计算了数列的 10 个元素
        display_elems(pent, title, cout, 5); // 赋值后面的默认参数，其前面的默认参数需要都指定

    return 0;
}


inline bool calc_elements(vector<int> &vec, int pos) // inline 函数
{
    if(pos <= 0 || pos >64)
    {
        cerr << "Sorry. Invalid position: " << pos << endl; // 使用 ceer 标准错误输出，无缓冲，清空缓存
        return false;
    }

    if(vec.size() < pos)
        really_calc_elems(vec, pos);
    
    return true;
}


void really_calc_elems( vector<int> &vec, int pos )
{
    for(int ix = vec.size()+1; ix <= pos; ix++)
        vec.push_back( ix*(3*ix-1)/2 );
}


void display_elems(vector<int> &vec, const string &title, ostream &os, int iNum) // 默认参数只能在定义或声明时指定一次
{
    os << '\n' << title << "\n\t";

    if(iNum) // 添加指定输出元素个数选项
        for(int ix = 0; ix < iNum; ix++)
            os << vec[ix] << ' ';
    else
        for(int ix = 0; ix < vec.size(); ix++)
            os << vec[ix] << ' ';
            
    os << '\n' << endl;
}


