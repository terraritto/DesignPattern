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
	virtual void ActorJump(){}

	virtual void ActorFire(){}

	virtual void ActorSwap(){}

	virtual void ActorLurch(){}
};

class Charactor : public GameActor
{
public:
	void ActorJump() override { jump(); }
};

// make command
class Command
{
public:
	virtual ~Command() {}
	virtual void execute(GameActor& actor) = 0;
};

class JumpCommand : public Command
{
public:
	void execute(GameActor& actor) override { actor.ActorJump(); }
};

class FireCommand : public Command
{
public:
	void execute(GameActor& actor) override { actor.ActorFire(); }
};

class SwapCommand : public Command
{
public:
	void execute(GameActor& actor) override { actor.ActorSwap(); }
};

class LurchCommand : public Command
{
public:
	void execute(GameActor& actor) override { actor.ActorLurch(); }
};

// input handle
class InputHandler
{
public:
	InputHandler()
		: mButtonX(std::make_unique<JumpCommand>())
		, mButtonY(std::make_unique<FireCommand>())
		, mButtonA(std::make_unique<SwapCommand>())
		, mButtonB(std::make_unique<LurchCommand>())
	{}

	//make command
	Command* handleInput()
	{
		if (isPressed(Input::ButtonX)) { return mButtonX.get(); } // return first for isPressed's definition
		if (isPressed(Input::ButtonY)) { return mButtonY.get(); }
		if (isPressed(Input::ButtonA)) { return mButtonA.get(); }
		if (isPressed(Input::ButtonB)) { return mButtonB.get(); }

		return nullptr;
	}

private:
	std::unique_ptr<Command> mButtonX;
	std::unique_ptr<Command> mButtonY;
	std::unique_ptr<Command> mButtonA;
	std::unique_ptr<Command> mButtonB;
};

int main()
{
	std::unique_ptr<GameActor> chara = std::make_unique<Charactor>();
	InputHandler input;
	auto command = input.handleInput();

	if (command)
	{
		command->execute(*chara);
	}
}