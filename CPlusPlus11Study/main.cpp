#include<iostream>


int main(int agv, char** ags)
{
    if (agv != 2)
    {
        printf_s("�����ʽ��%s name, �뽫name�滻Ϊ������֣�����", *ags);
        return agv;
    }
    printf_s("%s��ʼѧϰC++11", *(ags + 1));
    return 0;
}