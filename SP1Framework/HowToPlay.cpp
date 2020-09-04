#include "HowToPlay.h"

HowToPlay::HowToPlay() :
	buttons{ },
	selector(0)
{
	buttons[0] = new Button(3, 39, 0x0F, "Enter/Space to Return to Menu");
}

HowToPlay::~HowToPlay()
{
}

int HowToPlay::getselector()
{
	return selector;
}

void HowToPlay::setselector(int select)
{
	selector = select;
}

void HowToPlay::renderHTP(Console& anotherC)
{
	std::ostringstream ss;
	ss << (char)233 << (char)247;

	//Top
	anotherC.writeToBuffer(85, 4, "Objective", 0x0F);
	anotherC.writeToBuffer(66, 5, "Collect Key & Keycards and advance to next level", 0x0F);
	anotherC.writeToBuffer(72, 6, "Reach Level 6 and activate device", 0x0F);
	anotherC.writeToBuffer(106, 6, ss.str(), 0xF4);
	//Left Col
	COORD left,right;
	left.X = 5;
	left.Y = 10;

	//EQ Floor
	anotherC.writeToBuffer(left, "EarthQuake", 0x0F);
	left.Y += 2;
	anotherC.writeToBuffer(left, "  ", 0x0F); //tile
	left.X += 2;
	anotherC.writeToBuffer(left, "  -  Randomly Disappearing Floor, Cant pass through", 0x0F); //tile
	left.X -= 2;
	left.Y += 3;

	//EQ Boulder
	anotherC.writeToBuffer(left, "굇", 0x68); //tile
	left.X += 2;
	anotherC.writeToBuffer(left, "  -  Moves in one Direction and spawns back. -1HP if hit", 0x0F);
	left.X -= 2;
	left.Y += 5;

	//Lava/Volcano
	anotherC.writeToBuffer(left, "Volcano", 0x0F);
	left.Y += 2;
	anotherC.writeToBuffer(left, "께", 0x44);
	left.X += 2;
	anotherC.writeToBuffer(left, "  -  Slowly Spreads in all 4 directions, -1HP if walked on", 0x0F); 
	left.X -= 2;
	left.Y += 5;

	//Tsuanmi
	anotherC.writeToBuffer(left, "Tsunami", 0x0F);
	left.Y += 2;
	anotherC.writeToBuffer(left, "께", 0x19);
	left.X += 2;
	anotherC.writeToBuffer(left, "  -  Slowly Spreads in all 4 directions, pushes players away", 0x0F); 
	left.X -= 2;
	left.Y += 5;

	//Tornado
	anotherC.writeToBuffer(left, "Tornado", 0x0F);
	left.Y += 2;
	anotherC.writeToBuffer(left, "같", 0x2F);
	left.X += 2;
	anotherC.writeToBuffer(left, "  -  Moves Back and forth in a set path. Pushes player back and -1HP", 0x0F); 
	left.X -= 2;
	left.Y += 5;

	//Right Col
	right.X = 100;
	right.Y = 10;
	
	//Items
	anotherC.writeToBuffer(right, "Items", 0x0F);
	right.Y += 2;

	//HP
	anotherC.writeToBuffer(right, "00", 0xF4);
	right.X += 2;
	anotherC.writeToBuffer(right, "  -  Heals 2 HP", 0x0F);
	right.X -= 2;
	right.Y += 7;

	//Key
	anotherC.writeToBuffer(right, "kk", 0x8E);
	right.X += 2;
	anotherC.writeToBuffer(right, "  -  Unlocks Level 1 Door", 0x0F);
	right.X -= 2;
	right.Y += 2;
	anotherC.writeToBuffer(right, "께", 0xB0);
	right.X += 2;
	anotherC.writeToBuffer(right, "  - Level 1 Door", 0x0F);
	right.X -= 2;
	right.Y += 7;

	//KeyCard
	anotherC.writeToBuffer(right, "CC", 0x8E);
	right.X += 2;
	anotherC.writeToBuffer(right, "  -  Unlocks Level 2 Door", 0x0F);
	right.X -= 2;
	right.Y += 2;
	anotherC.writeToBuffer(right, "께", 0x40);
	right.X += 2;
	anotherC.writeToBuffer(right, "  - Level 2 Door", 0x0F);
	right.X -= 2;
	right.Y += 7;

	buttons[0]->renderButton(anotherC, false);
}
