//
//  main.cpp
//  TestApp
//
//  Created by Andy A on 6/13/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <time.h>

using namespace std;

class stek
{
	int size;
	int * arr;
	int top;
public:
	stek();
	~stek();
	void push(int value);//добавление элемента
	void print();//распечатка всех элементов
	void pop();//извлечение и удаление элемента

	bool stek_pustoy();
	bool stek_zapolnen();
	void tekushiy_size_steka();
};

stek::stek()
{
	size=10;
	top=0;
	arr=new int[size];
	for(int i=0;i<size;i++)
		arr[i]=0;
}
stek::~stek()
{
	delete [] arr;
}
//методы :

void stek::push(int value)
{
	if (stek_zapolnen()==false)
	{
		arr[top]=value;
		top++;
		tekushiy_size_steka();
		print();
	}
	
	else cout<<"Stek zapolnen!!\n";
}
void stek::pop()
{
	if (stek_pustoy()==false)
	{
		arr[top]=0;
		top--;
		tekushiy_size_steka();
		print();
	}
	else cout<<"Stek pustoy!!\n";
}

bool stek::stek_pustoy()
{
	if(top==0)
		return true;
	else return false;
}
bool stek:: stek_zapolnen()
{
	if(top==size)return true;
	else return false;
}
void stek::tekushiy_size_steka()
{
	cout<<"Tekushiy size steka = "<<top<<endl;
}
void stek::print()
{
	for(int i=0;i<top;i++)
		cout<<arr[i]<<" ";
	cout << endl;
}

int main(int argc, const char * argv[])
{

	// insert code here...
	std::cout << "Hello, World!\n";

	srand(time(0));
	
	stek probniy;
	for(int i=0;i<15;i++)
		probniy.push(rand()%11);
	
	for(int i=0;i<20;i++)
		probniy.pop();

    return 0;
}

