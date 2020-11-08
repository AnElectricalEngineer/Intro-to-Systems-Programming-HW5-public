#include "Parcel.H"
#include <cstring>

//************************************************************************************* 
// Function name : Parcel
//
// Description : Constructor for Parcel class
//
// Parameters:  1) ID of the Parcel
//				2) destination of the Parcel
//
// Return value : none
//*************************************************************************************
Parcel::Parcel(const char* ID, int dest) : dest_(dest)
{
	ID_ = new char[strlen(ID) + 1];
	strcpy(ID_, ID);
}

//************************************************************************************* 
// Function name : ~Parcel
//
// Description : Destructor for Parcel class
//
// Parameters:  none
//
// Return value : none
//*************************************************************************************
Parcel::~Parcel()
{
	delete[] ID_;
}