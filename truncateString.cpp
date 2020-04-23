#include<iostream>
#include<string>
#include<vector>

using std::string;
using std::vector;

//用指定字符截断字符串

int main()
{
    string  str = "123#acv##msdm#";
    string::size_type pos;

    pos = str.find("#");
    vector<string> svec;

    while(pos != str.npos)
    {
        if(pos != 0)
        {
            string result = str.substr(0,pos);
            svec.push_back(result);
        }

        str = str.erase(0,pos + 1);
        pos = str.find("#");
    }

    if(!str.empty())
        svec.push_back(str);

    for(vector<string>::iterator s = svec.begin(); s != svec.end(); ++s)
    {
        std::cout << *s << std::endl;
    }

    return 0;
}
