#include "InitializingTheList.h"

std::vector<int> InitializingTheList::GetValue() const
{
    return vec;
}

InitializingTheList::InitializingTheList(std::initializer_list<int> list)
{
    for (auto &it : list)
    {
        vec.push_back(it);
    }
}

InitializingTheList::~InitializingTheList()
{
}

void InitializingTheList::Initializer(std::initializer_list<int> list)
{
    for (auto& it : list)
    {
        vec.push_back(it);
    }
}
