#ifndef PARCEL_H_
#define PARCEL_H_

class Parcel {
public:
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
	Parcel(const char* ID, int dest);

	//************************************************************************************* 
	// Function name : ~Parcel
	//
	// Description : Destructor for Parcel class
	//
	// Parameters:  none
	//
	// Return value : none
	//*************************************************************************************
	~Parcel();

	char* ID_;
	int dest_;
};

#endif /* PARCEL_H_ */