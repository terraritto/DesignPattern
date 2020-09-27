#include <memory>
#include <iostream>
#include <functional>

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
		:mHealth(0),mSpeed(0)
	{}

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

//make Ghost
auto spownLambdaGhost = []() {return std::make_shared<Ghost>(); };

std::function<std::shared_ptr<Ghost>()> f;


template<class Func>
class Spawner
{
public:
	Spawner(Func spawn)
		: mSpawn(spawn)
	{
	}

	auto SpawnMonster()
	{
		return mSpawn();
	}

private:
	Func mSpawn;
};

int main()
{
	auto sp = std::make_shared<Spawner<decltype(spownLambdaGhost)>>(spownLambdaGhost);
	std::shared_ptr<Monster> monster = sp->SpawnMonster();
	monster->Print();
}