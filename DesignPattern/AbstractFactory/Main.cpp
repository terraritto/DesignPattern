#include "Factory.h"
#include "ListFactory.h"
#include "Link.h"
#include "Page.h"
#include "Tray.h"
#include <memory>

int main()
{
	std::shared_ptr<Factory> factory(Factory::GetFactory<ListFactory>());

	std::shared_ptr<Link> asahi(factory->CreateLink("asahi", "http://www.asahi.com/"));
	std::shared_ptr<Link> yomiuri(factory->CreateLink("yomiuri", "http://www.yomiuri.co.jp/"));
	std::shared_ptr<Link> us_yahoo(factory->CreateLink("Yahoo!", "http://www.yahoo.com/"));
	std::shared_ptr<Link> jp_yahoo(factory->CreateLink("Yahoo!Japan", "http://www.yahoo.co.jp"));
	std::shared_ptr<Link> excite(factory->CreateLink("Excite", "http://www.excite.com/"));
	std::shared_ptr<Link> google(factory->CreateLink("Google", "http://www.google.com/"));

	std::shared_ptr<Tray> traynews(factory->CreateTray("paper"));
	traynews->Add(asahi.get());
	traynews->Add(yomiuri.get());

	std::shared_ptr<Tray> trayyahoo(factory->CreateTray("Yahoo!"));
	trayyahoo->Add(us_yahoo.get());
	trayyahoo->Add(jp_yahoo.get());
	
	std::shared_ptr<Tray> traysearch(factory->CreateTray("search engine"));
	traysearch->Add(trayyahoo.get());
	traysearch->Add(excite.get());
	traysearch->Add(google.get());

	std::shared_ptr<Page> page(factory->CreatePage("LinkPage", "var"));
	page->Add(traynews.get());
	page->Add(traysearch.get());
	page->Output();

	return 0;
}