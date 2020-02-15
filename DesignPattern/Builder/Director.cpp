#include "Director.h"

Director::Director(Builder* build)
	: mBuilder(build)
{
}

void Director::Construct()
{
	mBuilder->MakeTitle("Greeting");

	mBuilder->MakeString("from morning to afternoon");
	mBuilder->MakeItems({"hello","good afternoon"});
	
	mBuilder->MakeString("at night");
	mBuilder->MakeItems({"good evening","good night","goodby"});

	mBuilder->Close();
}
