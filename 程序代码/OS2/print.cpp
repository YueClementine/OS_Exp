#include "storage.h"
void Task::printStorage() //��ӡ�ڴ��
{
	cout << "--------------0"<<endl;
	list <Task*>::iterator tempList;
	int fore_endingAddr = 0, nextBeginingAddr = 0;							//temp_pos������һ����ҵ�Ľ���λ��,pos������һ����ҵ����ʼλ��

	for (tempList = tasklist.begin(); tempList != tasklist.end(); tempList++)
	{
		Task* task;
		task = *tempList;								//��ȡ�б��е�һ����ҵ
		nextBeginingAddr = task->startingAddress;							//��һ����ҵ��ʼ�ڴ�
		if (nextBeginingAddr != fore_endingAddr)							//������ڴ�����ҵ������
		{
			cout << "---����---"<<endl;
			cout << "--------------" << nextBeginingAddr<<endl;
		}
		int i = task->id + 1;
		cout << "     ��ҵ" << i<<endl;
		cout<< "--------------" << task->endingAddress<<endl;
		fore_endingAddr = task->endingAddress;						//temp_pos������һ����ҵ�Ľ���λ��
	}
	if (fore_endingAddr < Task::size)						//��ʾ���һ���ڴ�
	{
		cout << "---����---"<<endl;
		cout << "--------------" << Task::size<<endl;
	}
	cout << endl;
}

int Task::UIprint() {
	int i, tem;
	while (cout << "////////////�����˵�///////////" << endl
		<< "     1:�����������" << endl
		<< "     2:�����������" << endl
		<< "     3:�˳� " << endl
		<< "///////////////////////////////////" << endl
		<<"       ��ѡ�����"<< endl,
		cin >> i)
	{
		switch (i)
		{
		case 1:
		{	cout << "��������ҵ��Ҫ������ռ��С:";
		cin >> tem;
		Task* task = new Task(tem);
		task->apply();						//��������ҵ
		};break;
		case 2:
		{	cout << "��������Ҫ������ҵ���:";
		cin >> tem;
		Task::reclaim(tem-1);					//������ҵ
		};break;
		case 3:return 0;
		default:break;
		}
		Task::printStorage();
	}
	return 0;
}