#include<cstdio>
#include<iostream>

using namespace std;
int bitmap[8][8];

void reclaim()
{
	int cylinderNumber, trackNumber, recordNumber;
	cout<<"柱面号:";
	cin >> cylinderNumber;
	cout<<"磁道号:";
	cin >> trackNumber;
	cout<<"物理记录号:";
	cin >> recordNumber;
	if (bitmap[cylinderNumber-1][4 * trackNumber + recordNumber-1] == 0)
	{
		cout<<"此块还未被分配，不可回收"<<endl;
	}
	else
	{
		int bitnum = 4 * trackNumber + recordNumber;
		bitmap[cylinderNumber-1][4 * trackNumber + recordNumber-1] = 0;
		cout << "回收字节号：" << cylinderNumber <<endl<< "    " << "位数：" << bitnum<<endl;
	}
}
void apply()
{
	int i, j;
	int change = 0;
	int cylinderNumber, trackNumber, recordNumber;
	for (i = 0;i < 8 && !change;i++)
	{
		for (j = 0;j < 8 && !change;j++) {
			if (bitmap[i][j] == 0)
			{
				bitmap[i][j] = 1;
				change = 1;
			}
		}
	}
		if (change == 1)
		{
			cylinderNumber = i;
			trackNumber = j / 4;
			recordNumber = j % 4;
			cout << "柱面号：" << cylinderNumber << endl << "磁道号" << trackNumber << endl << "物理记录号" << recordNumber << endl;
		}
		else {
			cout << "磁盘空间不足" << endl;
		}
	
}
void display()
{
	for (int i = 0;i < 8;++i)
	{
		for (int j = 0;j < 8;++j)
		{
			cout << bitmap[i][j];
		}
		cout << endl;
	}
}

int main(void)
{
	int num;
	display();
	while (true)
	{
		cout << "///////////////////" << endl;
		cout << "1.申请一块磁盘空间" << endl;
		cout << "2.归还一块磁盘空间" << endl;
		cout << "3.退出"<<endl;
		cout << "///////////////////" << endl<<endl;
		cin >> num;
		switch (num)
		{
		case 1:
		{	apply();								//申请新磁盘空间
		};break;
		case 2:
		{	reclaim();						//归还磁盘空间
		};break;
		case 3:return 0;
		default:break;
		}
		display();
	}
	return 0;
}
