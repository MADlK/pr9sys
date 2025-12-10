#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
	int count = 0;
	while (true)
	{
		count++;
		Sleep(1000);
		cout << "count = " << count << endl;
	}
	return 0;
}
