#include "File.h"
#include "Directory.h"
#include <iostream>

int main()
{
	std::cout << "Making root entries..." << std::endl;

	std::shared_ptr<Directory> rootdir(new Directory("root"));
	std::shared_ptr<Directory> binddir(new Directory("bin"));
	std::shared_ptr<Directory> tmpdir(new Directory("tmp"));
	std::shared_ptr<Directory> userdir(new Directory("user"));

	rootdir->Add(binddir.get());
	rootdir->Add(tmpdir.get());
	rootdir->Add(userdir.get());

	std::shared_ptr<File> file1(new File("vi",10000));
	std::shared_ptr<File> file2(new File("latex", 20000));
	binddir->Add(file1.get());
	binddir->Add(file2.get());
	rootdir->PrintList();

	std::cout << "" << std::endl;
	std::cout << "Making user entries..." << std::endl;
	
	std::shared_ptr<Directory> yuki(new Directory("yuki"));
	std::shared_ptr<Directory> hanako(new Directory("hanako"));
	std::shared_ptr<Directory> tomura(new Directory("tomura"));
	userdir->Add(yuki.get());
	userdir->Add(hanako.get());
	userdir->Add(tomura.get());

	std::shared_ptr<File> file3(new File("diary.html", 100));
	std::shared_ptr<File> file4(new File("Composite.h", 200));
	std::shared_ptr<File> file5(new File("memo.tex", 300));
	std::shared_ptr<File> file6(new File("game.doc", 400));
	std::shared_ptr<File> file7(new File("junk.mail", 500));

	yuki->Add(file3.get());
	yuki->Add(file4.get());
	hanako->Add(file5.get());
	tomura->Add(file6.get());
	tomura->Add(file7.get());
	rootdir->PrintList();
}