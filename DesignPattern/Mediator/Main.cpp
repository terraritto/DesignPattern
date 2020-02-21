#include "ConcreteMediator.h"

int main()
{
	ConcreteMediator mediator;

	mediator.CreateColleagues();

	mediator.ChangeMode("a");

	mediator.ChangeMode("b");
}