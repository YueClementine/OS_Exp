#include<cstdio>
#include<iostream>

using namespace std;
int bitmap[8][8];

void reclaim()
{
	int cylinderNumber, trackNumber, recordNumber;
	cout<<"�����:";
	cin >> cylinderNumber;
	cout<<"�ŵ���:";
	cin >> trackNumber;
	cout<<"�����¼��:";
	cin >> recordNumber;
	if (bitmap[cylinderNumber-1][4 * trackNumber + recordNumber-1] == 0)
	{
		cout<<"�˿黹δ�����䣬���ɻ���"<<endl;
	}
	else
	{
		int bitnum = 4 * trackNumber + recordNumber;
		bitmap[cylinderNumber-1][4 * trackNumber + recordNumber-1] = 0;
		cout << "�����ֽںţ�" << cylinderNumber <<endl<< "    " << "λ����" << bitnum<<endl;
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
			cout << "����ţ�" << cylinderNumber << endl << "�ŵ���" << trackNumber << endl << "�����¼��" << recordNumber << endl;
		}
		else {
			cout << "���̿ռ䲻��" << endl;
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
		cout << "1.����һ����̿ռ�" << endl;
		cout << "2.�黹һ����̿ռ�" << endl;
		cout << "3.�˳�"<<endl;
		cout << "///////////////////" << endl<<endl;
		cin >> num;
		switch (num)
		{
		case 1:
		{	apply();								//�����´��̿ռ�
		};break;
		case 2:
		{	reclaim();						//�黹���̿ռ�
		};break;
		case 3:return 0;
		default:break;
		}
		display();
	}
	return 0;
}
