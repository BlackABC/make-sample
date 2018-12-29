#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//int main()
//{
//	fstream fp;
//	fp.open("PeopleSample.txt", ios::app);
//
//	for (int i = 1; i < 601; i++)
//	{
//		char buff[7] = { 0 };
//		sprintf(buff, "%06d", i);
//		fp << buff << ".jpg" << endl;
//	}
//
//	return 0;
//}

int MakeSampleTestmain()
{
	fstream fp;
	fp.open("PositiveSample.txt");

	string str;

	while (getline(fp, str))
	{
		cout << str << endl;
	}
	system("pause");
	return 0;
}