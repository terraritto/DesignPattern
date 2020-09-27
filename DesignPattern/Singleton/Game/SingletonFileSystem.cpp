#include <memory>

class FileSystem
{
public:
	static FileSystem& instance()
	{
		static auto instance = std::make_unique<FileSystem>();
		return *instance;
	}
private:
	FileSystem(){}
};

// not global access
//‚Æ‚Ä‚à•Ö—˜
class FileSystem
{
public:
	FileSystem() {
		assert(!mInstantiated);
		mInstantiated = true;
	}

	~FileSystem()
	{
		mInstantiated = false;
	}

private:
	static bool mInstantiated;
};

bool FileSystem::mInstantiated = false;