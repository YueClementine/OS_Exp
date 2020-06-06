#include"storage.h"
#include<iostream>
using namespace std;

int main(void)
{
	Task::initailize();			//初始化内存大小
	Task::printStorage();
	Task::UIprint();
	return 0;
}
