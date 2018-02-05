#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stdlib.h>
void GetAllWorld(std::string& str, std::vector<std::string>* output)
{
    int len = str.length();
    for(int i = 0; i < len; ++ i)
    {
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            std::string ans = "";
            for( ; i < len; )
                if(str[i] > 'z' || str[i] < 'a')
                    break;
                else
                {
                    ans += str[i];  
                    ++ i;
                }
            (output)->push_back(ans);
        }
    }
}

void ChangeWorldToInterget(std::vector<std::string>& output, std::vector<int>* array)
{
    for(size_t i = 0; i < output.size(); ++ i)
    {
        int ans = 0;
        for(size_t j = 0; j < output[i].length(); ++ j)
        {
            ans = (ans << 5) | (output[i][j] -'a' + 1);
        }
        (array)->push_back(ans);
    }
}

int PerfectHash(std::vector<int>& array)
{
    int ans = 2147483647;
    size_t length = array.size();
    for(size_t i = 0; i < length; ++ i)
        if(ans > array[i])
            ans = array[i];
    while(true)
    {
        bool find = true;
        for (size_t i = 0; i < length; i++)
            for (size_t j = i + 1; j < length; j++)
                if ( (ans/array[i])%length == (ans/array[j])%length) {
                    ans = std::min(  (ans / array[i] + 1) * array[i], (ans / array[j] + 1) * array[j]);
                    find = false;
                    break;
                }
        if(find)
            break;
    }
    return ans;
}
int main()
{
    std::string s;
    while (getline(std::cin, s)) {
        std::vector<int> array;
        std::vector<std::string> world;
        GetAllWorld(s, &world);
        ChangeWorldToInterget(world, &array);
        
        std::cout << s << std::endl << PerfectHash(array) << std::endl << std::endl;
        s="";
    }
}