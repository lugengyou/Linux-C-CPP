/*
 * @Descripttion: Essential C++ ch3 使用 iterator 实现 display() 和 find() 函数
 * @version: 
 * @Author: Lugy
 * @Date: 2023-06-23 19:56:07
 * @LastEditors: Andy
 * @LastEditTime: 2023-06-23 20:53:30
 */

#include <vector>
#include <list>
#include <string>
#include <iostream>

using namespace std;


// template <typename elemType>
// void display(const vector<elemType> &vec, ostream &os);

// template <typename IteratorTpye, typename elemType>
// IteratorTpye find(IteratorTpye first, IteratorTpye last, const elemType &value);

/**
 * @name: 
 * @msg: 使用 iterator 访问容器，实现 display 功能；！！！gcc 不能通过编译
 * @return {*}
 */
// template <typename elemType>
// void display(const vector<elemType> &vec, ostream &os)
// {
//     vector<elemType>::const_iterator iter = vec.begin();
//     vector<elemType>::const_iterator end_it = vec.end();

//     for( ; iter != end_it; iter++)
//         os << *iter << ' ';

//     os << endl;
// }

/**
 * @name: 
 * @msg: 使用 iterator 实现 find() 函数
 * @return {*}
 */
template <typename IteratorTpye, typename elemType>
IteratorTpye find(IteratorTpye first, IteratorTpye last, const elemType &value)
{
    for( ; first != last; first++)
        if(value == *first)
            return first;

    return last;
}

int main(void)
{
    const int asize = 8;
    int ia[asize] = {1, 1, 2, 3, 5, 8, 13, 21};

    vector<int> ivec(ia, ia+asize);
    list<int> ilist(ia, ia+asize);

    int *pia = find(ia, ia+asize, 1024);
    if(pia == ia+asize)
        cout << "Don't find " << 1024 << " in ia" << endl;

    return 0;
}





