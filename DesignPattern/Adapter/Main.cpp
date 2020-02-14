#include "PrintBanner.h"
#include "Print.h"
#include <memory>

int main()
{
	std::shared_ptr<Print> p = std::make_shared<PrintBanner>("test");
	p->PrintWeak();
	p->PrintStrong();

	return 0;
}