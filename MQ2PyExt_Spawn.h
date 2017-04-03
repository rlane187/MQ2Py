/* MQ2PyExt_Spawn.h
 * Copyright (c) 2009 Stephen Raub.
 *
 * Distribution is not allowed without the consent of the author. 
 *
 * Definitions and such for MQ2Py Extension spawn component
 */

#pragma once

class PythonRace;
class PythonHeading;

class PythonSpawn
{
public:
	// Constructors
	PythonSpawn();
	PythonSpawn(int SpawnID);
	PythonSpawn(std::string Name);
	PythonSpawn(PythonSpawn const& Spawn);
	PythonSpawn(PSPAWNINFO pSpawn);
	virtual ~PythonSpawn();

	// Operators
	PythonSpawn& operator= (PythonSpawn const& Spawn);
	bool operator== (PythonSpawn const& right);
	
	// Linked list navigation
	PythonSpawn Next();
	bool HasNext();
	PythonSpawn Prev();
	bool HasPrev();

	// Properties
	std::string Name();
	std::string Surname();
	std::string CleanName();
	std::string DisplayName();
	std::string Title();
	std::string Suffix();

	// General properties
	int Level();
	int ID();
	int CurrentHPs();
	int MaxHPs();
	float PctHPs();
	int AARank();
	float Speed();
	PythonHeading Heading();
	std::string Gender();
	PythonRace Race();
	eSpawnType Type();

	enum PlayerClass Class();

	// Location properties
	boost::python::tuple Position();
	boost::python::tuple Position3D();
	float E();
	float W();
	float X();
	float S();
	float N();
	float Y();
	float D();
	float U();
	float Z();
	float FloorZ();

	// Pet
	bool HasPet();
	int PetID();
	PythonSpawn Pet();
	bool HasMaster();
	int MasterID();
	PythonSpawn Master();

	// Methods
	bool IsGroupMember();
	bool IsRaidMember();
	bool LineOfSight();
	bool IsFleeing();
	void Target();
	void Clear();

	// Helpers Functions (not exported)
	void Invalidate();
	void AssertIsValid();
	virtual bool IsValid();

	std::string __repr__();

public:
	// Events
	boost::python::object OnDeath;
	boost::python::object OnTarget;

	boost::python::object OnMouseOver;
	boost::python::object OnMouseLeave;
	boost::python::object OnMouseEnter;

	boost::python::object OnInvalidate;

	PSPAWNINFO GetSpawn() { return pSpawn; }

protected:
	void SetSpawn(PSPAWNINFO pSpawn);

	PSPAWNINFO pSpawn;
	bool Valid;

private:
	void UpdateDebugCounts();
};
