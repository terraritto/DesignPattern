#include "Display.h"
#include "StringDisplay.h"
#include "SideBorder.h"
#include "FullBorder.h"

int main()
{
	std::shared_ptr<Display> b1(new StringDisplay("Hello, world"));
	std::shared_ptr<Display> b2(new SideBorder(b1.get(), '#'));
	std::shared_ptr<Display> b3(new FullBorder(b2.get()));
	
	b1->Show();
	b2->Show();
	b3->Show();

	//warning:
	//I don't think memory for this process,
	//so if you want to write safe,
	//you must write destructer or use smart pointer.
	Display* b4
	(new SideBorder
		(new FullBorder
			(new FullBorder
				(new SideBorder
					(new FullBorder
						(
							new StringDisplay("konkon.")
						), '*'
					)
				)
			),'/'
		)
	);
	b4->Show();
}