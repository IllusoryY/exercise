#include<iostream>

using std::cout;
using std::endl;

int cube(int& x)
{
    return x * x * x;
}

int main()
{
    //打印水仙花数
    for(int i = 100; i < 1000; ++i)
    {
        int bit = i;
        int hundredBit = i / 100;
        bit = bit % 100;

        int decade = bit / 10;
        bit = bit % 10;

        int sum = cube(hundredBit) + cube(decade) + cube(bit);
        if(sum == i)
        {
            cout << i << "是一个水仙花数" << endl;
        }
    }

    //打印n个星星
   int x = 1;
   int target = 7;
   while(x <= target)
   {
       for(int y = 1; y <= x; ++y)
       {
           cout << "*";
       }
       cout << endl;
       x += 2;
   }

   x -= 4;
   while(x >= 1)
   {
       for(int y = 1; y <= x; ++y)
       {
           cout << "*";
       }
       cout << endl;
       x -= 2;
   }

   return 0;
}
