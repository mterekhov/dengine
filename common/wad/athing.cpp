#include "athing.h"
#include "autilities.h"
#include "asprite.h"
#include <map>

//=============================================================================

namespace spcWAD
{

//=============================================================================

std::map<int, std::string> ThingsMap =
{
	{1, "play"},    //  Player
	{2, "play"},    //  Player
	{3, "play"},    //  Player
    {4, "play"},    //  Player
    {5, "BKEY"},
    {6, "YKEY"},
    {8, "BPAK"},
    {9, "SPOS"},    //  Monster: ShotgunGuy
	{10, "play"},   //  Player
	{11, "CELP"},
    {12, "play"},    //  Player
    {13, "AMM1"},
	{15, "play"},    //  Player
	{24, "POL5"},
    {34, "CAND"},
    {35, "CBRA"},
    {46, "TRED"},
    {48, "ELEC"},
    {58, "sarg"},   //  Monster: Pinky Invisible
	{2001, "SHOT"},
	{2002, "MGUN"},
    {2003, "LAUN"},
    {2005, "CSAW"},
	{2007, "CLIP"},
	{2008, "SHEL"},
    {2010, "ROCK"},
    {2011, "STIM"},
    {2012, "MEDI"},
    {2013, "SOUL"},
	{2014, "BON1"},
	{2015, "BON2"},
	{2018, "ARM1"},
	{2019, "ARM2"},
    {2024, "PINS"},
    {2025, "SUIT"},
    {2026, "PMAP"},
    {2028, "COLU"},
    {2035, "bar1"},
    {2045, "PVIS"},
	{2046, "brok"},
	{2048, "ammo"},
	{2049, "SBOX"},
    {3001, "TROO"}, //  Monster: Imp
    {3002, "SARG"}, //  Monster: Pinky
    {3003, "BOSS"}, //  Monster: Hell Knight
    {3004, "POSS"},
};

    std::list<std::string> MonstersIdsList =
    {
        "BOSS",
        "SARG",
        "TROO",
        "SPOS"
    };
    
//=============================================================================

AThing::AThing(unsigned char *thingData)
{
	if (!thingData)
	{
		return;
	}
	
	int bytesOffset = 0;
	memcpy(&xPosition, &thingData[bytesOffset], 2);
	bytesOffset += 2;
	memcpy(&yPosition, &thingData[bytesOffset], 2);
	bytesOffset += 2;
	memcpy(&angle, &thingData[bytesOffset], 2);
	bytesOffset += 2;
	memcpy(&type, &thingData[bytesOffset], 2);
	bytesOffset += 2;
	memcpy(&options, &thingData[bytesOffset], 2);
}

//=============================================================================

AThing::AThing(const AThing& thing) : xPosition(thing.xPosition), yPosition(thing.yPosition), type(thing.type), angle(thing.angle), options(thing.options)
{
    
}
    
//=============================================================================

AThing& AThing::operator=(const AThing& rv)
{
    if (this == &rv)
    {
        return *this;
    }
    
    xPosition = rv.xPosition;
    yPosition = rv.yPosition;
    type = rv.type;
    angle = rv.angle;
    options = rv.options;

    return *this;
}

//=============================================================================
    
AThing::~AThing()
{
}

//=============================================================================

bool AThing::hasSprite() const
{
    if (ThingsMap[type].length() != 0)
    {
        return true;
    }
    
    return false;
}

//=============================================================================

std::string AThing::spritePrefix() const
{
    if (!hasSprite())
    {
        return "";
    }
    
    return ThingsMap[type];
}

//=============================================================================

TThingList AThing::checkThingUnique(const TThingList& thingsList)
{
	TThingList thingsListSorted(thingsList);
	
	//	sort by type
	std::sort(thingsListSorted.begin(), thingsListSorted.end());
	
	//	delete doubles
	thingsListSorted.erase(std::unique(thingsListSorted.begin(), thingsListSorted.end()) , thingsListSorted.end());
	
	return thingsListSorted;
}

//=============================================================================

TSpriteList AThing::findMonsters(const TSpriteList& thingsList)
{
    TSpriteList monstersList;

    for (TSpriteListConstIter iter = thingsList.begin(); iter != thingsList.end(); iter++)
    {
        for (std::list<std::string>::const_iterator monsterIdIter = MonstersIdsList.begin(); monsterIdIter != MonstersIdsList.end(); monsterIdIter++)
        {
            if (AUtilities::stringCompare(iter->spritesPrefix, *monsterIdIter))
            {
                monstersList.push_back(*iter);
            }
        }
    }
    
    return monstersList;
}

//=============================================================================

bool AThing::operator ==(const AThing & obj) const
{
	if (type == obj.type)
	{
		return true;
	}

	return false;
}

//=============================================================================

bool AThing::operator <(const AThing & obj) const
{
	if (type < obj.type)
	{
		return true;
	}

	return false;
}

//=============================================================================

};  //  namespace spcWAD
