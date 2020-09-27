#include <memory>
#include <iostream>

class Monster
{
public:
	virtual ~Monster() {}
	virtual void Print() = 0;
};

class Ghost : public Monster
{
public:
	Ghost()
		: mHealth(0), mSpeed(0){}

	Ghost(int health, int speed)
		: mHealth(health)
		, mSpeed(speed)
	{}

	void Print() override
	{
		std::cout << "Ghost" << std::endl;
	}
private:
	int mHealth;
	int mSpeed;
};

class Spawner
{
public:
	virtual ~Spawner(){}
	virtual std::shared_ptr<Monster> SpawnMonster() = 0;
};

template<class T>
class SpawnFor : public Spawner
{
public:
	std::shared_ptr<Monster> SpawnMonster() override { return std::make_shared<T>(); }
};

int main()
{
	auto sp = std::make_shared<SpawnFor<Ghost>>();
	auto monster = sp->SpawnMonster();
	monster->Print();
}