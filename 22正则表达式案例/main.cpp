#include <iostream>
#include <vector>
#include <algorithm>
#include <initializer_list>
#include <tuple>
#include <string>
#include <map>
#include<array>
#include <functional>
#include<memory>
#include<unordered_map>
#include<regex>

using namespace std;


int main(int argv, char** args) {
    string fnames[] = { "foo.txt","bar.txt","test","a0.txt","AAA.txt" };
    //在C++中‘\’会被视为字符串内的转义符，为使‘\.’作为正则表达式传递进去生效，需要对 '\.'写为'\\.'
    regex txt_regex("[a-z]+\\.txt");
    for (const auto& fname : fnames)
        cout << fname << ": " << regex_match(fname, txt_regex) << endl;
    cout << "\n...............\n" << endl;
    regex base_regex("[a-z]+\\.txt");
    std::smatch base_match;
    for (const auto& fname : fnames) {
        if (regex_match(fname, base_match, base_regex)) {
            //sub_match 的第一个元素匹配整个字符串
            //sub_match 的第二个元素匹配了第一个括号表达式
            if (base_match.size())
            {
                string base = base_match[1].str();
                cout << "sub-match[0]: " << base_match[0].str() << endl;
                cout << fname << "sub-match[1]: " << base << endl;
            }
        }
    }



    return  argv;
}