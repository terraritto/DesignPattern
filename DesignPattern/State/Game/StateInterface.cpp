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

//状態遷移の解決策1
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
	//staticで持たせる
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
			heroine.SetState(HeroinState::jumping);//これで設定できる
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

//状態遷移の解決策2
class HeroinState;
class Heroine
{
public:
	void HandleInput(Input input) {
		auto state = mState->HandleInput(*this, input);
		auto equipmentState = mEquipment->HandleInput(*this, input);
		if (state)
		{
			//状態が変わる前に処理を行う
			mState->Exit(*this);

			mState = std::move(state);//変わる度に動的確保,こちらだと複数のheroineに対応できる

			//画像の変更はここで一回呼べばよい
			//毎回行いたい処理があるならここで呼び出してやれば分かりやすくなる
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
	std::unique_ptr<HeroinState> mEquipment;//複雑になりそうなら状態機械自体を分けるのもあり
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

//階層化による表現
class OnGroundState : public HeroinState
{
public:
	std::unique_ptr<HeroinState> HandleInput(Heroine& heroine, Input input) override
	{
		if (input == Input::PRESS_B)//ジャンプ
		{
		}
		else if (input == Input::PRESS_DOWN) //かがむ
		{

		}
	}
};

class DuckingState : public OnGroundState
{
public:
	std::unique_ptr<HeroinState> HandleInput(Heroine& heroine, Input input) override
	{
		if (input == Input::RELEASE_DOWN)//姿勢を戻す
		{ }
		else
		{
			OnGroundState::HandleInput(heroine, input); //入力なしなので遡る
		}

	}
};