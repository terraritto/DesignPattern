#pragma once
#include <array>

constexpr int WIDTH = 100;
constexpr int Height = 100;

class Mesh {};
class Texture {};
class Vector {};
class Color {};

// common data
class TreeModel
{
private:
	Mesh mMesh;
	Texture mBark;
	Texture mLeaves;
};

class Tree
{
private:
	// model specific
	TreeModel* mModel;

	// object specific
	Vector mPos;
	double mHeight;
	double mThickness;
	Color mBarkTint;
	Color mLeafTint;
};

/*
enum class Terrain
{
	TERRAIN_GRASS,
	TERRAIN_HILL,
	TERRAIN_RIVER
};

class World
{
public:
	int GetMovementCost(int x, int y)
	{
		switch (mTiles[x][y])
		{
			case Terrain::TERRAIN_GRASS: return 1;
			case Terrain::TERRAIN_HILL: return 3;
			case Terrain::TERRAIN_RIVER: return 2;
		}
	}

	bool IsWater(int x, int y)
	{
		switch (mTiles[x][y])
		{
		case Terrain::TERRAIN_RIVER: return true;
		default: return false;
		}
	}

private:
	std::array<std::array<Terrain, WIDTH>, Height> mTiles;

};
*/

Texture GrassTexture;
Texture HillTexture;
Texture RiverTexture;

class Terrain
{
public:
	Terrain(int moveCost, bool isWater, Texture texture)
		: mMoveCost(moveCost)
		, mIsWater(isWater)
		, mTexture(texture)
	{}

	int GetMoveCost() const { return mMoveCost; }
	bool IsWater() const { return mIsWater; }
	const Texture& GetTexture() const
	{
		return mTexture;
	}
private:
	int mMoveCost;
	bool mIsWater;
	Texture mTexture;
};

class World
{
public:
	World()
		: mGrass(1, false, GrassTexture)
		, mHill(3, false, HillTexture)
		, mRiver(2, true, RiverTexture)
	{}

	void GenerateTerrain() {
		for (int i = 0; i < WIDTH; i++)
		{
			for (int j = 0; j < Height; j++)
			{
				if ((i * j) % 2 == 0)
				{
					mTiles[i][j] = &mHill;
				}
				else
				{
					mTiles[i][j] = &mGrass;
				}
			}
		}

		int  x = 10;
		for (int y = 0; y < Height; y++)
		{
			mTiles[x][y] = &mRiver;
		}
	}

	const Terrain& GetTile(int x, int y) const
	{
		return *mTiles[x][y];
	}
private:
	Terrain mGrass;
	Terrain mHill;
	Terrain mRiver;
	std::array<std::array<Terrain*, WIDTH>, Height> mTiles;
};

int main()
{
	World world;
	world.GenerateTerrain();

	int cost = world.GetTile(2, 3).GetMoveCost();
}