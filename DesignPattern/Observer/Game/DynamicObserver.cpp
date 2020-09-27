#include <array>
#include <memory>

constexpr int MAX_OBSERVERS = 100;

class Entity {
public:
	bool IsHero()const { return true; }
};

enum class Event
{
	EVENT_ENTITY_FELL
};

enum class Complete
{
	ACHIVEMENT_FELL_OFF_BRIDGE
};

class Observer
{
	friend class Subject;
public:
	Observer() : mNext(nullptr){}
	virtual ~Observer() {}
	virtual void OnNotify(const Entity& entity, Event eve) = 0;
private:
	std::shared_ptr<Observer> mNext;
};

class Achivement : public Observer
{
public:
	void OnNotify(const Entity& entity, Event eve) override
	{
		switch (eve)
		{
		case Event::EVENT_ENTITY_FELL:
			if (entity.IsHero() && mHeroIsOnBridge)
			{
				unlock(Complete::ACHIVEMENT_FELL_OFF_BRIDGE);
			}
			break;

			//other event process...

			//update mHeroIsOnBridge...
		}
	}

private:
	void unlock(Complete comp)
	{
		// give badge if this event haven't never been occured.
	}

	bool mHeroIsOnBridge;
};

class Subject
{
public:
	Subject()
		: mHead(nullptr){}

	void AddObserver(std::shared_ptr<Observer> observer)
	{
		observer->mNext = mHead;
		mHead = observer;
	}

	void RemoveObserver(std::shared_ptr<Observer> observer)
	{
		if (mHead == observer)
		{
			mHead = observer->mNext;
			observer->mNext = nullptr;
			return;
		}

		auto current = mHead;
		while (current != nullptr)
		{
			if (current->mNext == observer)
			{
				current->mNext = observer->mNext;
				observer->mNext = nullptr;
				return;
			}

			current = current->mNext;
		}
	}
protected:
	// send nitification from only Subject class
	void notify(const Entity& entity, Event eve)
	{
		auto observer = mHead;
		while (observer != nullptr)
		{
			observer->OnNotify(entity, eve);
			observer = observer->mNext;
		}
	}

private:
	//list node
	std::shared_ptr<Observer> mHead;
};

