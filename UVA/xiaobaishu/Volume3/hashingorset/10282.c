#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
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
std::map<std::string,std::string> dict;
int main()
{
    freopen("in.txt", "r", stdin);
    std::string s;
    while (getline(std::cin, s)) {
        if(s.length() == 0)break;
        std::vector<std::string> wrode;
        GetAllWorld(s, &wrode);
        if(wrode.size() != 2)
            while(true);
        dict[wrode[1]]=wrode[0];
        s="";
    }
    while(getline(std::cin, s))
    {
        if(dict.count(s) <= 0)
            std::cout<<"eh"<<std::endl;
        else
            std::cout<<dict[s]<<std::endl;
    }
    return 0;
}