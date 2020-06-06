#include<iostream>
#include<cstdio>
#include<list>
using namespace std;

class Task {
public:
	int startingAddress=0;								
	int length=0;									
	int endingAddress=0;								
	int id=0;										
	bool state=0;	// «∑Ò∑÷≈‰							
	static int size;								
	static list<Task*> tasklist;					
	static int taskNum;												
	Task(int t_size);							
	bool apply();									
	static bool reclaim(int id);					
	static void printStorage();							
	static int UIprint();
	static bool compare(const Task* f, const Task* s);
	static void initailize();					
};

