#include "zone_area_tracker.h"

void ZoneAreaTracker::OnUpdateZone(Player* player, uint32 newZone, uint32 newArea)
{
    if (loggingEnabled)
    {
        stringstream zoneStream;

        auto t = std::time(nullptr);
        auto tm = *std::localtime(&t);

        Group* group = player->GetGroup();

        zoneStream << std::put_time(&tm, "%d-%m-%Y %H-%M-%S") << ", ";
        zoneStream << player->GetName() << ", " << player->GetFaction() << ", " << player->GetLevel() << ", " << player->GetMaxHealth() << ", " << player->GetHealth() << ", ";
        zoneStream << newZone << ", " << newArea << (group != nullptr) << ", ";

        if (group != nullptr)
        {
            zoneStream << group->isRaidGroup();
        }
        else
        {
            zoneStream << "false";
        }

        zoneStream << "\n";

        fullStream << zoneStream.str();
        StringDump();
    }
}

void ZoneAreaTracker::OnUpdateArea(Player* player, uint32 /*oldArea*/, uint32 newArea)
{
    if (loggingEnabled)
    {
        stringstream areaStream;

        auto t = std::time(nullptr);
        auto tm = *std::localtime(&t);

        Group* group = player->GetGroup();

        areaStream << std::put_time(&tm, "%d-%m-%Y %H-%M-%S") << ", ";
        areaStream << player->GetName() << ", " << player->GetFaction() << ", " << player->getLevel() << ", " << player->GetMaxHealth() << ", " << player->GetHealth() << ", ";
        areaStream << "000000" << ", " << newArea << (group != nullptr) << ", ";

        if (group != nullptr)
        {
            areaStream << group->isRaidGroup();
        }
        else {
            areaStream << "false";
        }

        areaStream << "\n";

        fullStream << areaStream.str();
        StringDump();
    }
}
