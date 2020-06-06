#include <iostream>
#define Add(type) (type*)malloc(sizeof(type)) //定义宏函数


using namespace std;
struct pcb { //PCB结构体定义
	char name[99];
	char state;
	int priority;
	int needtime;
	int passedtime;
	struct pcb* link;
}*ready = NULL, * process;
typedef struct pcb PCB;

