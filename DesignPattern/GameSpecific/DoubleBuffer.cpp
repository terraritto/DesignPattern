constexpr int WHITE = 0;
constexpr int BLACK = 255;

class Framebuffer
{
public:
	//construct and method
	void clear()
	{
		for (int i = 0; i < WIDTH * HEIGHT; i++)
		{
			mPixel[i] = WHITE;
		}
	}

	void Draw(int x, int y)
	{
		mPixel[(WIDTH * y) + x] = BLACK;
	}

	//これで画面へデータを送る
	const char* GetPixels()
	{
		return mPixel;
	}
private:
	static constexpr int WIDTH = 160;
	static constexpr int HEIGHT = 120;
	char mPixel[WIDTH * HEIGHT];
};

class Scene
{
public:
	Scene()
		: mCurrent(&mBuffer[0])
		, mNext(&mBuffer[1])
	{}

	void Draw()
	{
		mNext->clear();
		mNext->Draw(1,1);
		//...
		mNext->Draw(4, 3);
		Swap();
	}

	Framebuffer& GetBuffer() { return *mCurrent; }
private:
	void Swap()
	{
		Framebuffer* temp = mCurrent;
		mCurrent = mNext;
		mNext = temp;
	}

	Framebuffer mBuffer[2];
	Framebuffer* mCurrent;
	Framebuffer* mNext;
};

//複数のactorの場合とかでも利用可能!!
class Actor
{
public:
	Actor():mCurrentSwapped(false){}
	virtual ~Actor(){}
	virtual void Update() = 0;
	void Swap()
	{
		mCurrentSwapped = mNextSwapped;
		mNextSwapped = false;
	}
	void slap() { mNextSwapped = true; }
	bool WasSlapped() { return mCurrentSwapped; }
private:
	bool mCurrentSwapped;
	bool mNextSwapped;
};

class Stage
{
public:
	void Add(Actor* actor, int index)
	{
		mActors[index] = actor;
	}

	void Update()
	{
		for (int i = 0; i < NUM_ACTORS; i++)
		{
			mActors[i]->Update();
		}

		for (int i = 0; i < NUM_ACTORS; i++)
		{
			mActors[i]->Swap();
		}
	}
private:
	static constexpr int NUM_ACTORS = 3;
	Actor* mActors[NUM_ACTORS];
};

class Comedian : public Actor
{
public:
	void face(Actor* actor) { mFacing = actor; }
	void Update() override
	{
		if (WasSlapped()) { mFacing->slap(); }
	}
private:
	Actor* mFacing;
};

//更に複数ある場合はoffsetを設けてやればよい
class Actor
{
public:
	static void init() { mCurrent = 0; }
	static void swap() { mCurrent = Next(); }
	void slap() { mSlapped[Next()] = true; }
	bool wasSlapped() { return mSlapped[mCurrent]; }
private:
	static int mCurrent;
	static int Next() { return 1 - mCurrent; }
	bool mSlapped[2];
};