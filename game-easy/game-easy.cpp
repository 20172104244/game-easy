// game-easy.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;
class CWolf;//前向说明前向声明即在定义之前先声明，其主要作用在于，避免了当两个类相互调用时include出现循环导致的编译错误
			//在类很多时，我们并不能确保某两个类一定不会互相调用，为了避免这种潜在的错误，最好使用前向声明
class CGhost;
class CDragon;
class CCreature
{
protected:
	int nPower; //代表攻击力
	int nLifeValue; //代表生命值
	string name;
public:
	void display()
	{
		cout << name << "nPower=" << nPower << "  nLifeValue=" << nLifeValue << endl;
	}
	void setvalue(string name_, int p, int l)
	{
		nPower = p;
		nLifeValue = l;
		name = name_;
	}
	void Hurted(int nPower)
	{
		//．．．．表现受伤动作的代码
		cout << name << "受伤害" << endl;
		nLifeValue -= nPower;
	}
	void Attack(CCreature * pobj)//CCreature * pobj是派生类，还有基类指针可以指向派生类对象
	{
		//．．．表现攻击动作的代码
		cout << name << "攻击" << endl;
		pobj->Hurted(nPower);
		pobj->FightBack(this);
	}
	// void Hurted( int nPower);
	void FightBack(CCreature * pobj)
	{
		//．．．．表现反击动作的代码
		cout << name << "反击" << endl;
		pobj->Hurted(nPower / 2);
	}

};
class CDragon :public CCreature
{
public:
	//龙特有的属性和方法
};
class CWolf :public CCreature
{
public:
	//狼特有的属性和方法

};
class CGhost :public CCreature
{
public:
	//幽灵特有的属性和方法

};
int main()
{
	CDragon oDragon;
	oDragon.setvalue("龙", 20, 100);
	CWolf oWolf;
	oWolf.setvalue("狼", 4, 100);
	CGhost oGhost;
	oGhost.setvalue("幽灵", 10, 100);
	oDragon.display();
	oWolf.display();
	oGhost.display();
	oDragon.Attack(&oWolf);
	oDragon.Attack(&oWolf);
	oGhost.Attack(&oDragon);
	oDragon.display();
	oWolf.display();
	oGhost.display();
	return 0;
}

