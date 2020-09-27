#include <string>
#include <memory>

enum class PLATFORM
{
	PLAYSTATION3,
	WII
};

PLATFORM WORLD_PLAYFORM;

class FileSystem
{
public:
	static FileSystem& Instance() {
		static std::unique_ptr<FileSystem> instance;
		
		if (instance) { return *instance; }

		if (WORLD_PLAYFORM == PLATFORM::PLAYSTATION3)
		{
			instance = std::make_unique<PS3FileSystem>();
		}
		else if(WORLD_PLAYFORM == PLATFORM::WII)
		{
			instance = std::make_unique<WiiFileSystem>();
		}

		return *instance;
	}

	virtual ~FileSystem(){}
	virtual std::string Read(std::string path) = 0;
	virtual void Write(std::string path, std::string text) = 0;
protected:
	FileSystem(){}
};

class PS3FileSystem : public FileSystem
{
public:
	std::string Read(std::string path) override
	{
		//use sony io file API
	}
	void Write(std::string path, std::string text) override
	{
		//use sony io fail API
	}

};

class WiiFileSystem : public FileSystem
{
public:
	std::string Read(std::string path) override
	{
		//use nintendo io file API
	}
	void Write(std::string path, std::string text) override
	{
		//use nintendo io fail API
	}
};