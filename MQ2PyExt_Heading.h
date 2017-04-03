/* MQ2PyExt_Heading.h
* Copyright (c) 2017 Stephen Raub.
*
* Distribution is not allowed without the consent of the author.
*
* Definitions and such for MQ2Py Extension heading component
*/

#pragma once

class PythonHeading
{
public:
	PythonHeading(float RawHeading);

	static void RegisterPythonClass();

	int Clock();
	float Degrees();
	float DegreesCCW();
	std::string ShortName();
	std::string Name();

	std::string __repr__();

private:
	const float rawHeading;
};