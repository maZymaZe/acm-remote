#include <cstdio>
#include <iostream>
#include <string>
bool isvow(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}
int main()
{
    int n;
    scanf("%d", &n);
    std::string str;
    std::cin >> str;
    bool flag1 = 0;//辅音
    bool flag2 = 0;
    int cnt = 0;
    for (int i = 0; i < str.size(); i++)
    {
        flag1 = (!isvow(str[i])) || flag1;
        flag2 = isvow(str[i]) || flag2;
        if (flag1 == 1 && flag2 == 1)
        {
            cnt++;
            flag1 = 0;
            flag2 = 0;
        }
    }
    printf("%d", cnt);
    return 0;
}