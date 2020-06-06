#include "storage.h"
void Task::printStorage() //打印内存块
{
	cout << "--------------0"<<endl;
	list <Task*>::iterator tempList;
	int fore_endingAddr = 0, nextBeginingAddr = 0;							//temp_pos保存上一个作业的结束位置,pos保存下一个作业的起始位置

	for (tempList = tasklist.begin(); tempList != tasklist.end(); tempList++)
	{
		Task* task;
		task = *tempList;								//获取列表中的一个作业
		nextBeginingAddr = task->startingAddress;							//下一个作业起始内存
		if (nextBeginingAddr != fore_endingAddr)							//如果在内存中作业不连续
		{
			cout << "---空闲---"<<endl;
			cout << "--------------" << nextBeginingAddr<<endl;
		}
		int i = task->id + 1;
		cout << "     作业" << i<<endl;
		cout<< "--------------" << task->endingAddress<<endl;
		fore_endingAddr = task->endingAddress;						//temp_pos保存上一个作业的结束位置
	}
	if (fore_endingAddr < Task::size)						//显示最后一块内存
	{
		cout << "---空闲---"<<endl;
		cout << "--------------" << Task::size<<endl;
	}
	cout << endl;
}

int Task::UIprint() {
	int i, tem;
	while (cout << "////////////操作菜单///////////" << endl
		<< "     1:提出分配请求" << endl
		<< "     2:提出回收请求" << endl
		<< "     3:退出 " << endl
		<< "///////////////////////////////////" << endl
		<<"       请选择操作"<< endl,
		cin >> i)
	{
		switch (i)
		{
		case 1:
		{	cout << "请输入作业需要的主存空间大小:";
		cin >> tem;
		Task* task = new Task(tem);
		task->apply();						//申请新作业
		};break;
		case 2:
		{	cout << "请输入您要回收作业编号:";
		cin >> tem;
		Task::reclaim(tem-1);					//回收作业
		};break;
		case 3:return 0;
		default:break;
		}
		Task::printStorage();
	}
	return 0;
}