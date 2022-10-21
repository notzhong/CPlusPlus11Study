#include<iostream>


int main(int agv, char** ags)
{
    if (agv != 2)
    {
        printf_s("输入格式：%s name, 请将name替换为你的名字！！！", *ags);
        return agv;
    }
    printf_s("%s开始学习C++11", *(ags + 1));
    return 0;
}