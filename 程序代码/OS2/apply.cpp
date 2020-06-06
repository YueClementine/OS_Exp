#include "storage.h"
int Task::taskNum = 0;
int Task::size = 1000;
list<Task*> Task::tasklist;

void Task::initailize() //�����ڴ���С
{
	cout << "�������ڴ���С" << endl;
	cin >> size;
}

Task::Task(int t_size) :length(t_size)			
{
	state = false;									
	this->id = taskNum++;			//ID������			

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
		if (next_begin - fore_end >= length)				//����ҵ���һ�����ʵĿռ��С
		{
			this->state = true;
			this->startingAddress = fore_end;
			this->endingAddress = fore_end + this->length;
			tasklist.push_back(this);				//����ҵ�����б�
			tasklist.sort(compare);			//����ַ˳���������
			return true;
		}
		fore_end = task->endingAddress;
	}
	if (Task::size - fore_end >= length)			//�������һ������ҵ
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

bool Task::compare(const Task* f, const Task* s) //�Ƚ���ҵ�׵�ַ
{
	return f->startingAddress < s->startingAddress;
}