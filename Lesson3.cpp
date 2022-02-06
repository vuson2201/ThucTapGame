#include <iostream>
#include <list>
using namespace std;
class BaseObject
{
public:
	BaseObject(int ID, string Name, int Position) {
		id = ID;
		name = Name;
		position = Position;
	}
	int getid()
	{
		return id;
	}
	string getName()
	{
		return name;
	}
	int printPosition()
	{
		return position;
	}
protected:
	int id;
	string name;
	int position;
};
class StaticObjcet: public BaseObject
{
public:
	StaticObjcet(int ID, string Name, int Position) :BaseObject(ID, Name,Position) {
		id = ID;
		name = Name;
		position = Position;
	}
	void move()
	{
		cout << "khong di chuyen duoc" << endl<<endl;
	}
private:
};
class DynamicObject:public BaseObject
{
public:
	DynamicObject(int ID, string Name, int Position) :BaseObject(ID, Name, Position) {
		id = ID;
		name = Name;
		position = Position;
	}
	void move()
	{
		cout << "move: " << position + 1 <<endl << endl;
	}
private:

};
class Tree: public StaticObjcet
{
public:
	Tree(int ID, string Name, int Position) :StaticObjcet(ID, Name, Position) {
		id = ID;
		name = Name;
		position = Position;
	}
private:

};
class House: public StaticObjcet
{
public:
	House(int ID, string Name, int Position) :StaticObjcet(ID, Name, Position) {
		id = ID;
		name = Name;
		position = Position;
	}
private:

};
class Motorbike : public DynamicObject
{
public:
	Motorbike(int ID, string Name, int Position) : DynamicObject(ID, Name, Position) {
		id = ID;
		name = Name;
		position = Position;
	}
private:

};
class Car: public DynamicObject
{
public:
	Car(int ID, string Name, int Position) : DynamicObject(ID, Name, Position) {
		id = ID;
		name = Name;
		position = Position;
	}
private:

};
int main()
{
	list<StaticObjcet*> listObj1;
	Tree* a = new Tree(1,"cay",1);
	listObj1.push_back(a);
	House* b = new House(2, "nha", 2);
	listObj1.push_back(b);
	list<DynamicObject*> listObj2;
	Motorbike* c = new Motorbike(3, "xe may", 3);
	listObj2.push_back(c);
	Car* d = new Car(4, "o to", 4);
	listObj2.push_back(d);
	for (auto StaticObjcet : listObj1)
	{
		cout<<"ID: "<< StaticObjcet->getid() << endl;
		cout<<"Name: "<< StaticObjcet->getName() << endl;
		cout <<"Position: "<< StaticObjcet->printPosition() << endl;
		StaticObjcet->move();
	}
	for (auto DynamicObject : listObj2)
	{
		cout << "ID: " << DynamicObject->getid() << endl;
		cout << "Name: " << DynamicObject->getName() << endl;
		cout << "Position: " << DynamicObject->printPosition() << endl;
		DynamicObject->move();
	}
}
