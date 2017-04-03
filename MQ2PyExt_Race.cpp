/* MQ2PyExt_Race.cpp
* Copyright (c) 2017 Stephen Raub.
*
* Distribution is not allowed without the consent of the author.
*
* This module implements the race type
*/

#include "MQ2PyPCH.h"
#include "MQ2Py.h"
#include "MQ2PyExt.h"
#include "MQ2PyExt_Race.h"

using namespace boost;
using namespace boost::python;

void PythonRace::RegisterPythonClass()
{
	class_<PythonRace>("Race", no_init)
		.def(init<int>())
		.def(self == self)
		.add_property("ID", &PythonRace::ID)
		.add_property("Name", &PythonRace::Name)
		.def("__repr__", &PythonRace::__repr__);
}

PythonRace::PythonRace(int RaceID) : id(RaceID)
{
	if (RaceID == NULL)
	{
		PyErr_SetString(PyExc_AssertionError, "Race is Invalid");
		throw_error_already_set();
	}
}

int PythonRace::ID() const
{
	return id;
}

std::string PythonRace::Name()
{
	char buffer[MAX_STRING];
	strcpy_s(buffer, MAX_STRING, pEverQuest->GetRaceDesc(id));
	return buffer;
}

std::string PythonRace::__repr__()
{
	ostringstream ss;
	ss << "Race: " << Name();

	return ss.str();
}

bool PythonRace::operator==(PythonRace const& right)
{
	return right.ID() == ID();
}

void Init_Module_PyMQ2_Race()
{
	PythonRace::RegisterPythonClass();
}

void Shutdown_Module_PyMQ2_Race()
{

}