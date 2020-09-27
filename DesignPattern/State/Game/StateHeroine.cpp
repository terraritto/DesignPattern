
constexpr int JUMP_VELOCITY = 5;

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

void SetGraphics(Image im){}

class Heroine
{
public:
	void HandleInput(Input input) {
		switch (mState)
		{
		case State::STATE_STANDING:
			if (input == Input::PRESS_B)
			{
				mState = State::STATE_JUMPING;
				mY_Velocity = JUMP_VELOCITY;
				SetGraphics(Image::IMAGE_JUMP);
			}
			else if (input == Input::PRESS_DOWN)
			{
				mState = State::STATE_DUCKING;
				SetGraphics(Image::IMAGE_DUCK);
			}
			break;
		
		case State::STATE_JUMPING:
			if (input == Input::PRESS_DOWN)
			{
				mState = State::STATE_DIVING;
				SetGraphics(Image::IMAGE_DIVE);
			}
			break;

		case State::STATE_DUCKING:
			if (input == Input::RELEASE_DOWN)
			{
				mState = State::STATE_STANDING;
				SetGraphics(Image::IMAGE_STAND);
			}
			break;
		}
	}
private:
	State mState;
	int mY_Velocity;
};