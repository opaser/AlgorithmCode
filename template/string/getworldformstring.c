/************************************
空格串中获得小写字母的单词以空格分开
************************************/
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