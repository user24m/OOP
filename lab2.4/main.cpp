#include <iostream>
#include <ctime>

using namespace std;

string timeToString(long milisecs){
    time_t defaultDate = time(NULL);
    defaultDate = defaultDate + milisecs;

    string cc = ctime(&defaultDate);

    return cc;
}

int main()
{
    cout<<timeToString(0);
    return 0;
}
