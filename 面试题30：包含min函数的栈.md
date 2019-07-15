```cpp
#include<iostream>
#include<string>
#include<vector>
#include<malloc.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<math.h>

#include<stdio.h>
using namespace std;
template<typename T> void StackWithMin<T>::push(const T& value)
{
    m_data.push(value);
    if(m_min.size() == 0 || value<m_min.top())
        m_min.push(value);
    else
        m_min.push(m_min.top());
}
template<typename T>void StackWithMin<T>::pop()
{
    assert(m_data.size()>0 && m_min.size()>0);
    m_data.pop();
    m_min.pop();
}
template<typename T>const T& StackWithMin<T>::min() const{
    assert(m_data.size()>0 && m_min.size()>0);
    return m_min.top();
}
int main(){
    int num[]={1,2,3,4,5,6,7};
    RecorderOddEven(num,7);
    for(int ii=0;ii<7;ii++)
        cout<<num[ii]<<" ";
    return 0;
}

```