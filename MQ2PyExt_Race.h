/* MQ2PyExt_Race.h
* Copyright (c) 2017 Stephen Raub.
*
* Distribution is not allowed without the consent of the author.
*
* Definitions and such for MQ2Py Extension race component
*/

#pragma once

class PythonRace
{
public:
	// Constructor
	PythonRace(int RaceID);

	static void RegisterPythonClass();

	// Operators
	bool operator== (PythonRace const& right);

	// Properties
	int ID() const;
	std::string Name();

	std::string __repr__();

private:
	const int id;

};
