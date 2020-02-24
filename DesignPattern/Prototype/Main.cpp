#include "Manager.h"
#include "UnderLinePen.h"
#include "MessageBox.h"

int main()
{
	Manager manager;
	std::shared_ptr<UnderLinePen> upen = std::make_shared<UnderLinePen>('~');
	std::shared_ptr<MessageBox> mbox = std::make_shared<MessageBox>('*');
	std::shared_ptr<MessageBox> sbox = std::make_shared<MessageBox>('/');
	manager.Register("strong message", upen.get());
	manager.Register("warning box", mbox.get());
	manager.Register("slash box", sbox.get());

	std::shared_ptr<Product> p1(manager.Create("strong message"));
	p1->Use("test1");
	std::shared_ptr<Product> p2(manager.Create("warning box"));
	p2->Use("test2");
	std::shared_ptr<Product> p3(manager.Create("slash box"));
	p3->Use("test3");
}