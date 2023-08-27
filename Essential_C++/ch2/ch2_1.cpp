/*
 * @Descripttion: 编写计算 Fibonacci 数列函数，并设计输入输出程序
 * @version: 
 * @Author: Lugy
 * @Date: 2023-06-04 20:41:07
 * @LastEditors: Andy
 * @LastEditTime: 2023-06-04 20:52:20
 */

#include <iostream>

using namespace std;


bool fibon_elem(int pos, int &elem);

int main(void)
{
    int pos = 0;

    cout << "Please enter a position:";
    cin >> pos;

    int elem = 0;

    if(fibon_elem(pos, elem))
        cout << "element # " << pos << " is " << elem << endl;
    else
        cout << "Sorry. Could not calculate element # " << pos << endl;
        
    return 0;
}


bool fibon_elem(int pos, int &elem)
{
    if(pos <= 0 || pos >1024)
    {
        elem = 0;
        return false;
    }

    elem = 1;
    
    int n_1 = 1, n_2 = 1;

    for(int ix = 3; ix <= pos; ix++)
    {
        elem = n_1 + n_2;
        n_1 = n_2;
        n_2 = elem;
    }

    return true;
}

