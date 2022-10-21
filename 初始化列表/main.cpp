#include "InitializingTheList.h"
using namespace std;

int main(int agv, char** ags) {
    
    InitializingTheList Initlist { 1,2,3,4,5 };

    cout << "Initlist:";
    for (auto& it : Initlist.GetValue())
    {
        cout << it << endl;
    }
    
    Initlist.GetValue().clear();

    Initlist.Initializer({ 9,8,7,6,5 });

    cout << "Initlist:";
    for (auto& it : Initlist.GetValue())
    {
        cout << it << endl;
    }
    return agv;
}