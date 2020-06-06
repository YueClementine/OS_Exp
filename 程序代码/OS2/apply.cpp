#include "storage.h"
int Task::taskNum = 0;
int Task::size = 1000;
list<Task*> Task::tasklist;

void Task::initailize() //设置内存块大小
{
	cout << "请输入内存块大小" << endl;
	cin >> size;
}

Task::Task(int t_size) :length(t_size)			
{
	state = false;									
	this->id = taskNum++;			//ID自增长			

}

bool Task::apply()
{
	int temp_size = 0, fore_end = 0, next_begin = 0;
	list <Task*>::iterator plist;
	for (plist = tasklist.begin(); plist != tasklist.end(); plist++)
	{
		Task* task;
		task = *plist;
		next_begin = task->startingAddress;
		if (next_begin - fore_end >= length)				//如果找到第一个合适的空间大小
		{
			this->state = true;
			this->startingAddress = fore_end;
			this->endingAddress = fore_end + this->length;
			tasklist.push_back(this);				//把作业存入列表
			tasklist.sort(compare);			//按地址顺序进行排序
			return true;
		}
		fore_end = task->endingAddress;
	}
	if (Task::size - fore_end >= length)			//处理最后一个空作业
	{
		this->state = true;
		this->startingAddress = fore_end;
		this->endingAddress = fore_end + this->length;
		tasklist.push_back(this);
		tasklist.sort(compare);
		return true;
	}

	return false;
}

bool Task::compare(const Task* f, const Task* s) //比较作业首地址
{
	return f->startingAddress < s->startingAddress;
}