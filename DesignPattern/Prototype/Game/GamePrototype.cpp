#include <memory>
#include <iostream>

class Monster
{
public:
	virtual ~Monster(){}
	virtual std::shared_ptr<Monster> Clone() = 0;
	virtual void Print() = 0;
};

class Ghost : public Monster
{
public:
	Ghost(int health, int speed)
		: mHealth(health)
		, mSpeed(speed)
	{}

	std::shared_ptr<Monster> Clone() override
	{
		return std::make_shared<Ghost>(mHealth, mSpeed);
	}

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
	Spawner(std::shared_ptr<Monster> prototype)
		: mPrototype(prototype)
	{}

	auto SpawnMonster()
	{
		return mPrototype->Clone();
	}

private:
	std::shared_ptr<Monster> mPrototype;
};

int main()
{
	std::shared_ptr<Monster> ghostPrototype = std::make_shared<Ghost>(15, 3);
	auto ghostSpowner = std::make_shared<Spawner>(ghostPrototype);

	auto clone = ghostSpowner->SpawnMonster();

	clone->Print();
}