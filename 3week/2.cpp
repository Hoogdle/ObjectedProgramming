#include <iostream>
using std::cout;
using std::endl;

bool average(int a[], int size, int &avg)
{
    if (size <= 0)
        return false;
    avg = 0;
    for (int i = 0; i < size; ++i)
    {
        avg += a[i];
    }
    avg /= size;
    return true;
}
int main()
{
    int x[] = {0, 1, 2, 3, 4, 5};
    int avg;
    if (average(x, 6, avg))
        cout << "평균은 " << avg << endl;
    else
        cout << "매개 변수 오류" << endl;
    if (average(x, -1, avg))
        cout << "평균은 " << avg << endl;
    else
        cout << "매개 변수 오류 " << endl;
}