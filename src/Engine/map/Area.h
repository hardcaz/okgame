//------------------------------------------------------------------------------
//Copyright Robert Pelloni.
//All Rights Reserved.
//------------------------------------------------------------------------------

#pragma once
#include "oktypes.h"
class Logger;


class AreaData;

class Area : public EnginePart
{
public:

	static Logger log;

protected:
	sp<AreaData> data = nullptr;

public:
	long long ticksSinceSpawnTry = 0;

	bool spawned = false;
	bool triedSpawn = false;

	float mapX = 0;
	float mapY = 0;

	bool showActionIcon = true;

	sp<Map> map = nullptr;

	Area();
	Area(sp<Engine> g, sp<Map> m);

	Area(sp<Engine> g, sp<AreaData> a, sp<Map> m);

	sp<Event> event = nullptr;

	sp<Map> getMap();

	bool fadingInOut = false;
	float fadeAlpha = 0.0f;

	void renderActionIcon();

	virtual void update();

	void renderDebugBoxes();

	virtual void renderDebugInfo();

	/// <summary>
	/// This gets called repeatedly in events, until it returns a non-null value, at which point the event continues and does not ask again.
	/// This function will continue asking the server for the value, returning null until the server has set the response value.
	/// Upon finding a non-null response value set by the networking thread by a server response, we reset it to null and return that value, ensuring that it is always a fresh copy from the server.
	/// </summary>
	sp<OKBool> checkServerTalkedToTodayValueAndResetAfterSuccessfulReturn();

	void tellServerTalkedToToday();

	bool isWithinScreenBounds();

	bool inRangeOfEntityByAmount(sp<Entity> e, int amt);

	float getDistanceFromEntity(sp<Entity> e);

	bool isEntityHitBoxTouchingMyBoundary(sp<Entity> e);

	bool isAreaCenterTouchingMyBoundary(sp<Area> a);

	bool isAreaBoundaryTouchingMyBoundary(sp<Area> a);

	bool isXYTouchingMyBoundary(float x, float y);

	bool isXYXYTouchingMyBoundary(float left, float top, float right, float bottom);

	bool isAreaBoundaryTouchingMyCenter(sp<Area> a);

	bool isEntityMiddleXYTouchingMyCenter(sp<Entity> e);

	bool isAreaCenterTouchingMyCenter(sp<Area> a);

	bool isXYTouchingMyCenter(float x, float y);

	bool isXYXYTouchingMyCenter(float left, float top, float right, float bottom);

	bool isEntityHitBoxTouchingMyBoundaryByAmount(sp<Entity> e, int amt);

	bool isAreaCenterTouchingMyBoundaryByAmount(sp<Area> a, int amt);

	bool isAreaBoundaryTouchingMyBoundaryByAmount(sp<Area> a, int amt);

	bool isXYTouchingMyBoundaryByAmount(float x, float y, int amt);

	bool isXYXYTouchingMyBoundaryByAmount(float left, float top, float right, float bottom, int amt);

	bool isAreaBoundaryTouchingMyCenterByAmount(sp<Area> a, int amt);

	bool isEntityMiddleXYTouchingMyCenterByAmount(sp<Entity> e, int amt);

	bool isAreaCenterTouchingMyCenterByAmount(sp<Area> a, int amt);

	bool isXYTouchingMyCenterByAmount(float x, float y, int amt);

	bool isXYXYTouchingMyCenterByAmount(float left, float top, float right, float bottom, int amt);

	float getTop();

	float getLeft();

	float getRight();

	float getBottom();

	float middleX();

	float middleY();
	float roundedMiddleX();

	float roundedMiddleY();

private:
	float screenX();

	float screenY();

public:
	float screenLeft();

	float screenRight();

	float screenTop();

	float screenBottom();

	sp<AreaData> getData();

	float getX();
	float getY();

	int getWidth();
	int getHeight();

	string& getName();
	string& getComment();
	int getID();

	//int mapID();

	float arrivalXPixelsHQ();
	float arrivalYPixelsHQ();

	bool isWarpArea();
	bool randomPointOfInterestOrExit();
	bool randomNPCSpawnPoint();
	int standSpawnDirection();
	int waitHereTicks();
	bool randomWaitTime();
	bool onlyOneAllowed();
	bool randomNPCStayHere();
	float randomSpawnChance();
	bool randomSpawnOnlyTryOnce();
	bool randomSpawnOnlyOffscreen();
	int randomSpawnDelay();
	bool randomSpawnKids();
	bool randomSpawnAdults();
	bool randomSpawnMales();
	bool randomSpawnFemales();
	bool randomSpawnCars();
	bool autoPilot();
	bool playerFaceDirection();
	bool suckPlayerIntoMiddle();
	sp<EventData> getEventData();
	sp<vector<string>> connectionTYPEIDList();

	string getTYPEIDString();

	string& destinationTYPEIDString();
};

