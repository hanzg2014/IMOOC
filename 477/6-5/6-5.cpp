#include <vector>
#include <map>
#include <string>
#include <iostream>
using namespace std;

int main(void)
{
    // 使用vector存储数字：3、6、8、4
    vector<int> vec;
    vec.push_back(3);
    vec.push_back(6);
    vec.push_back(8);
    vec.push_back(4);
    //cout<<"vec.size="<<vec.size()<<endl;
    //循环打印数字
    vector<int>::iterator i;
    for(i=vec.begin();i!=vec.end();i++)
    {
        cout<<*i<<endl;
    }
    /*数组方法遍历向量
    for(int j=0;j<vec.size();j++)
    {
        cout<<"vec["<<j<<"]:"<<vec[j]<<endl;
    }
    */
    // 使用map来存储字符串键值对
    map<string, string> m;
    pair<string,string>p1("S","Shang Hai");
    pair<string,string>p2("B","Bei Jing");
    pair<string,string>p3("G","Guang Zhou");
    
    m.insert(p1);
    m.insert(p2);
    m.insert(p3);
   
    map<string,string>::iterator k;
    // 打印map中数据
    for(k=m.begin();k!=m.end();k++)
    {
        cout<<"m["<<k->first<<"] "<<k->second<<endl;
    }
    return 0;
}