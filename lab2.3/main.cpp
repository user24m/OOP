#include <iostream>
using namespace std;
struct student{
float grade;
char name[21];


};
int Max(int a, int b) {

return a < b ? b : a;
}
student Max(student a, student b) {

return a.grade < b.grade ? b  : a;
}

int main()
{
student a;
    cin>>a.grade;
    cin.get(a.name,21);

    student b;
    cin>>b.grade;
    cin.get(b.name,21);
    cout<<Max(a,b).name;

    return 0;
}
