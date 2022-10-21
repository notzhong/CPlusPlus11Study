#include <iostream>

#define LEN 10

int len_foo() {
    int i = 2;
    return i;
}

constexpr int len_foo_constexpr() {
    return 5;
}



constexpr int fibonacci(const int n)
{
    return n == 1 || n == 2 ? 1 : fibonacci(n - 1) + fibonacci(n - 2);
}


int main() {
    //legal_合法 C++标准，数组的长度必须是一个常量表达式
    char arr_1[10];
    char arr_2[LEN];

    int len = 10;
    //illegal_非法的
    //char arr_3[len];

    const int len_2 = len + 1;
    constexpr int len_2_constexpr = 1 + 2 + 3;

    //illegal
    //char arr_4[len_2];
    
    //legal
    char arr_5[len_2_constexpr];

    //illegal
    //char arr_6[len_foo() + 1];
    
    //legal
    char arr_6[len_foo_constexpr() + 1];


    std::cout << fibonacci(LEN) << std::endl;


    return 0;
}