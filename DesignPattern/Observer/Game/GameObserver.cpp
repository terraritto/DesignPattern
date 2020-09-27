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
public:
	virtual ~Observer(){}
	virtual void OnNotify(const Entity& entity, Event eve) = 0;
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
	// manage Observer
	// many class can add observer.
	void AddObserver(std::unique_ptr<Observer> observer)
	{

	}

	void RemoveObserver(std::unique_ptr<Observer> observer)
	{

	}
protected:
	// send nitification from only Subject class
	void notify(const Entity& entity, Event eve)
	{
		for (int i = 0; i < mNumObservers; i++)
		{
			mObservers[i]->OnNotify(entity, eve);
		}
	}
private:
	std::array<std::unique_ptr<Observer>, MAX_OBSERVERS> mObservers;
	int mNumObservers;
};

class Physics : public Subject
{
public:
	void UpdateEntity(Entity& entity){}
};