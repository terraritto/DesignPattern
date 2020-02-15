#include "NoSupport.h"
#include "LimitSupport.h"
#include "OddSupport.h"
#include "SpecialSupport.h"
#include "Trouble.h"
#include <memory>

int main()
{
	std::shared_ptr<Support> alice(new NoSupport("Alice"));
	std::shared_ptr<Support> Bob(new LimitSupport("Bob", 100));
	std::shared_ptr<Support> charlie(new SpecialSupport("Charlie", 429));
	std::shared_ptr<Support> diana(new LimitSupport("Diana", 200));
	std::shared_ptr<Support> elmo(new OddSupport("Elmo"));
	std::shared_ptr<Support> fred(new LimitSupport("Fred", 300));

	alice->SetNext(Bob.get())->SetNext(charlie.get())->SetNext(diana.get())->SetNext(elmo.get())->SetNext(fred.get());

	for (int i = 0; i < 500; i += 33)
	{
		std::shared_ptr<Trouble> temp(new Trouble(i));
		alice->support(temp.get());
	}
}