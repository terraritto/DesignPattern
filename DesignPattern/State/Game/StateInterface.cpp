#include <memory>

constexpr int JUMP_VELOCITY = 5;
constexpr int MAX_CHARGE = 5;

enum class State
{
	STATE_STANDING,
	STATE_JUMPING,
	STATE_DUCKING,
	STATE_DIVING
};

enum class Input
{
	PRESS_B,
	PRESS_DOWN,
	RELEASE_DOWN
};

enum class Image
{
	IMAGE_JUMP,
	IMAGE_DUCK,
	IMAGE_DIVE,
	IMAGE_STAND
};

/*
class Heroine
{
public:
	void HandleInput(Input input) {
		mState.HandleInput(*this,input);
	}

	void Update() { mState.Update(*this); }

	void SetGraphics(Image im) {}

	void SuperBomb(){}
private:
	HeroinState mState;
};

class HeroinState
{
public:
	virtual ~HeroinState() {}
	virtual void HandleInput(Heroine& heroine, Input input) {}
	virtual void Update(Heroine& heroine){}
};

class DuckingState : public HeroinState
{
public:
	DuckingState():mChargeTime(0){}
	void HandleInput(Heroine& heroine, Input input) override 
	{
		if (input == Input::RELEASE_DOWN)
		{
			heroine.SetGraphics(Image::IMAGE_STAND);
		}
	}
	void Update(Heroine& heroine) override
	{
		mChargeTime++;
		if (mChargeTime > MAX_CHARGE)
		{
			heroine.SuperBomb();
		}
	}
private:
	int mChargeTime;
};
*/

//ó‘Ô‘JˆÚ‚Ì‰ğŒˆô1
/*
class Heroine
{
public:
	friend HeroinState;
	void HandleInput(Input input) {
		mState.HandleInput(*this, input);
	}

	void Update() { mState.Update(*this); }

	void SetGraphics(Image im) {}
	void SetState(HeroinState& state) { mState = state; }

	void SuperBomb() {}
private:
	HeroinState mState;
};

class HeroinState
{
public:
	//static‚Å‚½‚¹‚é
	static StandingState standing;
	static DuckingState ducking;
	static JumpingState jumping;
	static DivingState diving;

	virtual ~HeroinState() {}
	virtual void HandleInput(Heroine& heroine, Input input) {}
	virtual void Update(Heroine& heroine) {}
};

class DuckingState : public HeroinState
{
public:
	DuckingState() :mChargeTime(0) {}
	void HandleInput(Heroine& heroine, Input input) override
	{
		if (input == Input::RELEASE_DOWN)
		{
			heroine.SetState(HeroinState::jumping);//‚±‚ê‚Åİ’è‚Å‚«‚é
			heroine.SetGraphics(Image::IMAGE_STAND);
		}
	}
	void Update(Heroine& heroine) override
	{
		mChargeTime++;
		if (mChargeTime > MAX_CHARGE)
		{
			heroine.SuperBomb();
		}
	}
private:
	int mChargeTime;
};

class StandingState : public HeroinState{};
class JumpingState : public HeroinState {};
class DivingState : public HeroinState {};
*/

//ó‘Ô‘JˆÚ‚Ì‰ğŒˆô2
class HeroinState;
class Heroine
{
public:
	void HandleInput(Input input) {
		auto state = mState->HandleInput(*this, input);
		auto equipmentState = mEquipment->HandleInput(*this, input);
		if (state)
		{
			//ó‘Ô‚ª•Ï‚í‚é‘O‚Éˆ—‚ğs‚¤
			mState->Exit(*this);

			mState = std::move(state);//•Ï‚í‚é“x‚É“®“IŠm•Û,‚±‚¿‚ç‚¾‚Æ•¡”‚Ìheroine‚É‘Î‰‚Å‚«‚é

			//‰æ‘œ‚Ì•ÏX‚Í‚±‚±‚Åˆê‰ñŒÄ‚×‚Î‚æ‚¢
			//–ˆ‰ñs‚¢‚½‚¢ˆ—‚ª‚ ‚é‚È‚ç‚±‚±‚ÅŒÄ‚Ño‚µ‚Ä‚â‚ê‚Î•ª‚©‚è‚â‚·‚­‚È‚é
			mState->Enter(*this);
		}

		if (state) {
			//...
		}
	}

	void Update() { mState->Update(*this); }

	void SetGraphics(Image im) {}

	void SuperBomb() {}
private:
	std::unique_ptr<HeroinState> mState;
	std::unique_ptr<HeroinState> mEquipment;//•¡G‚É‚È‚è‚»‚¤‚È‚çó‘Ô‹@ŠB©‘Ì‚ğ•ª‚¯‚é‚Ì‚à‚ ‚è
};

class HeroinState
{
public:
	virtual ~HeroinState() {}
	virtual std::unique_ptr<HeroinState> HandleInput(Heroine& heroine, Input input) {}
	virtual void Update(Heroine& heroine) {}
	virtual void Enter(Heroine& heroine){}
	virtual void Exit(Heroine&heroine){}
};

class StandingState : public HeroinState {};
class JumpingState : public HeroinState {};
class DivingState : public HeroinState {};

class DuckingState : public HeroinState
{
public:
	DuckingState() :mChargeTime(0) {}
	std::unique_ptr<HeroinState> HandleInput(Heroine& heroine, Input input) override
	{
		if (input == Input::RELEASE_DOWN)
		{
			return std::make_unique<StandingState>();
		}
	}
	void Update(Heroine& heroine) override
	{
		mChargeTime++;
		if (mChargeTime > MAX_CHARGE)
		{
			heroine.SuperBomb();
		}
	}

	void Enter(Heroine& heroine) override
	{
		heroine.SetGraphics(Image::IMAGE_DUCK);
	}
private:
	int mChargeTime;
};

//ŠK‘w‰»‚É‚æ‚é•\Œ»
class OnGroundState : public HeroinState
{
public:
	std::unique_ptr<HeroinState> HandleInput(Heroine& heroine, Input input) override
	{
		if (input == Input::PRESS_B)//ƒWƒƒƒ“ƒv
		{
		}
		else if (input == Input::PRESS_DOWN) //‚©‚ª‚Ş
		{

		}
	}
};

class DuckingState : public OnGroundState
{
public:
	std::unique_ptr<HeroinState> HandleInput(Heroine& heroine, Input input) override
	{
		if (input == Input::RELEASE_DOWN)//p¨‚ğ–ß‚·
		{ }
		else
		{
			OnGroundState::HandleInput(heroine, input); //“ü—Í‚È‚µ‚È‚Ì‚Å‘k‚é
		}

	}
};