/* MQ2PyExt_Heading.cpp
* Copyright (c) 2017 Stephen Raub.
*
* Distribution is not allowed without the consent of the author.
*
* This module implements the heading type
*/

#include "MQ2PyPCH.h"
#include "MQ2Py.h"
#include "MQ2PyExt.h"
#include "MQ2PyExt_Heading.h"

using namespace boost;
using namespace boost::python;

void PythonHeading::RegisterPythonClass()
{
	class_<PythonHeading>("Heading", no_init)
		.def(init<float>())
		.add_property("Clock", &PythonHeading::Clock)
		.add_property("Degrees", &PythonHeading::Degrees)
		.add_property("DegreesCCW", &PythonHeading::DegreesCCW)
		.add_property("ShortName", &PythonHeading::ShortName)
		.add_property("Name", &PythonHeading::Name)
		.def("__repr__", &PythonHeading::__repr__);
}

PythonHeading::PythonHeading(float RawHeading) : rawHeading(RawHeading)
{
	if (RawHeading == NULL)
	{
		PyErr_SetString(PyExc_AssertionError, "Heading is Invalid");
		throw_error_already_set();
	}
}

int PythonHeading::Clock()
{
	int a = Degrees() + 15;
	DWORD b = (a / 30) % 12;
	return b != 0 ? b : 12;
}

float PythonHeading::Degrees()
{
	return 360.0f - rawHeading;
}

float PythonHeading::DegreesCCW()
{
	return rawHeading;
}

std::string PythonHeading::ShortName()
{
	char buffer[MAX_STRING];
	strcpy_s(buffer, MAX_STRING, szHeadingNormalShort[(int)(Degrees() / 22.5f + 0.5f) % 16]);
	return buffer;
}

std::string PythonHeading::Name()
{
	char buffer[MAX_STRING];
	strcpy_s(buffer, MAX_STRING, szHeadingNormal[(int)(Degrees() / 22.5f + 0.5f) % 16]);
	return buffer;
}

std::string PythonHeading::__repr__()
{
	ostringstream ss;
	ss << "Heading: " << Name();

	return ss.str();
}

void Init_Module_PyMQ2_Heading()
{
	PythonHeading::RegisterPythonClass();
}