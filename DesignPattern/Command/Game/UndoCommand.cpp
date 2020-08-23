#include <iostream>
#include <memory>

void jump() { std::cout << "execute jump" << std::endl; }
void fireGun() { std::cout << "execute fireGun" << std::endl; }
void swapWeapon() { std::cout << "execute swapWeapon" << std::endl; }
void lurchIneffectovely() { std::cout << "execute lurchIneffctively" << std::endl; }

enum class Input
{
	ButtonX,
	ButtonY,
	ButtonA,
	ButtonB
};

bool isPressed(Input in)
{
	return true; //pass all command.
}

//Actor
class GameActor
{
public:
	virtual void MoveTo(int x,int y) = 0;
	virtual void print() const = 0;
};


class Unit : public GameActor
{
public:
	Unit(int x,int y)
		: mx(x),my(y){}

	int x() { return mx; }
	int y() { return my; }

	void MoveTo(int x, int y) override
	{
		mx = x;
		my = y;
	}

	void print() const
	{
		std::cout << "x:" << mx << std::endl;
		std::cout << "y:" << my << std::endl;
	}
private:
	int mx, my;
};

//now make an unit.
std::unique_ptr<Unit> chara = std::make_unique<Unit>(10, 10);

Unit* GetSelectedUnit()
{
	return chara.get();
}

// make command
class Command
{
public:
	virtual ~Command() {}
	virtual void execute() = 0;
	virtual void undo() = 0;
};


class MoveUnitCommand : public Command
{
public:
	MoveUnitCommand(Unit* unit, int x, int y)
		: mUnit(unit), mx(x), my(y), mxBefore(0), myBefore(0)
	{}

	void execute() override { 
		mxBefore = mUnit->x();
		myBefore = mUnit->y();
		mUnit->MoveTo(mx, my);
		mUnit->print();
	}

	void undo() override
	{
		mUnit->MoveTo(mxBefore, myBefore);
		mUnit->print();
	}

private:
	Unit* mUnit;
	int mx;
	int my;
	int mxBefore, myBefore;
};

// input handle
class InputHandler
{
public:
	//make command
	auto handleInput()
	{
		Unit* unit = GetSelectedUnit();

		if (isPressed(Input::ButtonX)) {
			// move unit up +1
			int destY = unit->y() - 1;
			return std::make_unique<MoveUnitCommand>(unit, unit->x(), destY);
		}

		if (isPressed(Input::ButtonY))
		{
			int destY = unit->y() + 1;
			return std::make_unique<MoveUnitCommand>(unit, unit->x(), destY);
		}

		//equal nullptr
		return std::unique_ptr<MoveUnitCommand>();
	}
};

int main()
{
	InputHandler input;
	auto command = input.handleInput();

	if (command)
	{
		command->execute();
		command->undo();
	}
}