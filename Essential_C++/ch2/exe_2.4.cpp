/*
 * @Descripttion: Essencial C++ execise 2.4
 * @version: 
 * @Author: Lugy
 * @Date: 2023-06-18 19:04:46
 * @LastEditors: Andy
 * @LastEditTime: 2023-06-18 19:27:21
 */


#include <iostream>
#include <vector>
#include <string>

using namespace std;


inline bool check_validity(int pos);

bool pentagonal_elem(int pos, int &elem);

const vector<int>* pentagonal_series(int pos);


int main(void)
{
    int elem;

    if(pentagonal_elem(8, elem))
        cout << "element 8 is " << elem << '\n';

    if (pentagonal_elem(88, elem))
        cout << "element 88 is " << elem << '\n';

    if (pentagonal_elem(64, elem))
        cout << "element 64 is " << elem << '\n';

    cout << endl;

    return 0;
}


/**
 * @name: 
 * @msg: 检测位置是否合法
 * @return {*}
 */
inline bool check_validity(int pos)
{
    return (pos <=0 || pos >64) ? false : true;
}

/**
 * @name: 
 * @msg: 获取元素
 * @return {*}
 */
bool pentagonal_elem(int pos, int &elem)
{
    if (!check_validity(pos))
    {
        cout << "sorry. Invalid position:" << pos << endl;
        elem = 0;
        return false;
    }

    const vector<int> *pent = pentagonal_series(pos);
    elem = (*pent)[pos-1];

    return true;
}

/**
 * @name: 
 * @msg: 计算 pentagonal 数列
 * @return {*}
 */
const vector<int>* pentagonal_series(int pos)
{
    static vector<int> _elems;

    if (check_validity(pos) && (pos > _elems.size()))
        for (int ix = _elems.size() + 1; ix <= pos; ix++)
            _elems.push_back( (ix*(3*ix-1))/2 );    

    return &_elems;
}












