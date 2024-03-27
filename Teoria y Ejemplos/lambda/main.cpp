#include <iostream>
using namespace std;

int main()
{
    /*
    int multiplier = 3;
    auto times = [multiplier](int a)
    {
        return a * multiplier;
    };
    int result = times(2);
    cout << result << endl;
    */ 

    int expiresInDays = 45;
    auto updateDays = [&expiresInDays](int newDays)
    {
        expiresInDays = newDays;
    };
    updateDays(30); // expiresInDays = 30
    cout << expiresInDays << endl;

    return 0;
}