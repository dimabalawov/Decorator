#include <iostream>
#include <string>
using namespace std;

class Hero abstract
{
protected:
	string name;
	int attack;
	int speed;
	int health;
	int defense;
public:
	Hero(string n)
	{
		name = n;
	}
	string GetName()
	{
		return name;
	}
	virtual int GetAttack()abstract;
	virtual int GetSpeed()abstract;
	virtual int GetHealth()abstract;
	virtual int GetDefense()abstract;


};

class Human : public Hero
{
public:
	Human() : Hero("Human")
	{ }

	int GetAttack()
	{
		return 20;
	}

	int GetSpeed()
	{
		return 20;
	}

	int GetHealth()
	{
		return 150;
	}

	int GetDefense()
	{
		return 0;
	}
};

class HumanClass abstract : public Human
{
protected:
	Human* human;
public:
	HumanClass(string n, Human* human) : human(human)
	{
		this->name = n;
	}

};

class HumanWarrior : public HumanClass
{
public:
	HumanWarrior(Human* human) : HumanClass("Human-Warrior", human) { }

	int GetAttack()
	{
		return 20;
	}

	int GetSpeed()
	{
		return 10;
	}

	int GetHealth()
	{
		return 50;
	}

	int GetDefense()
	{
		return 20;
	}
};

class Swordsman : public HumanClass {
public:
	Swordsman(HumanWarrior* hw) : HumanClass("Human-Swordsman", hw) {}

	int GetAttack()override {
		return 40;
	}

	int GetSpeed() override {
		return -10;
	}

	int GetHealth()override {
		return 50;
	}

	int GetDefense()override {
		return 40;
	}
};

class Archer : public HumanClass {
public:
	Archer(HumanWarrior* hw) : HumanClass("Human-Archer", hw) {}

	int GetAttack()
	{
		return 20;
	}

	int GetSpeed()
	{
		return 20;
	}

	int GetHealth()
	{
		return 50;
	}

	int GetDefense()
	{
		return 10;
	}
};

class HorseKnight : public HumanClass {
public:
	HorseKnight(Swordsman* sw) : HumanClass("Horse-Knight", sw) {}

	int GetAttack()
	{
		return 20;
	}

	int GetSpeed()
	{
		return 20;
	}

	int GetHealth()
	{
		return 50;
	}

	int GetDefense()
	{
		return 10;
	}
};

class Elf : public Hero
{
public:
	Elf() : Hero("Elf")
	{ }
	int GetAttack()
	{
		return 15;
	}

	int GetSpeed()
	{
		return 30;
	}

	int GetHealth()
	{
		return 100;
	}

	int GetDefense()
	{
		return 0;
	}
};
class ElfClass abstract : public Elf
{
protected:
	Elf* elf;
public:
	ElfClass(string n, Elf* elf) : elf(elf)
	{
		this->name = n;
	}

};

class ElfWarrior : public ElfClass
{
public:
	ElfWarrior(Elf* elf) : ElfClass("Elf-Warrior", elf) {};

	int GetAttack()
	{
		return 20;
	}

	int GetSpeed()
	{
		return -10;
	}

	int GetHealth()
	{
		return 100;
	}

	int GetDefense()
	{
		return 20;
	}
};

class ElfMage : public ElfClass
{
public:
	ElfMage(Elf* elf) : ElfClass("Elf-Mage", elf) {};

	int GetAttack()
	{
		return 10;
	}

	int GetSpeed()
	{
		return 10;
	}

	int GetHealth()
	{
		return -50;
	}

	int GetDefense()
	{
		return 10;
	}
};

class Crossbowman : public ElfClass
{
public:
	Crossbowman(ElfMage* em) : ElfClass("Elf-Archer", em) {};

	int GetAttack()override {
		return 20;
	}

	int GetSpeed() override {
		return 10;
	}

	int GetHealth()override {
		return 50;
	}

	int GetDefense()override {
		return 10;
	}
};

class EvilMage : public ElfClass
{
public:
	EvilMage(ElfMage* em) : ElfClass("Evil Elf-Mage", em) {};

	int GetAttack()
	{
		return 70;
	}

	int GetSpeed()
	{
		return 20;
	}

	int GetHealth()
	{
		return 0;
	}

	int GetDefense()
	{
		return 0;
	}
};

class GoodMage : public ElfClass
{
public:
	GoodMage(ElfMage* em) : ElfClass ("Good Elf-Mage", em) {};

	int GetAttack()
	{
		return 50;
	}

	int GetSpeed()
	{
		return 30;
	}

	int GetHealth()
	{
		return 100;
	}

	int GetDefense()
	{
		return 30;
	}
};



void client(Hero* p)
{
	cout << "Name: " << p->GetName() << endl;
	cout << "Defense: " << p->GetDefense() << endl;
	cout << "Speed: " << p->GetSpeed() << endl;
	cout << "Health: " << p->GetHealth() << endl;
	cout << "Attack: " << p->GetAttack() << endl;
	cout << "--------------" << endl;
}

int main() {
	Hero* hero = new Elf();
	client(hero);

	hero = new ElfWarrior(dynamic_cast<Elf*>(hero));
	client(hero);

	hero = new Crossbowman(dynamic_cast<ElfMage*>(hero));
	client(hero);

	delete hero;

	hero = new Human();
	client(hero);

	hero = new HumanWarrior(dynamic_cast<Human*>(hero));
	client(hero);
}