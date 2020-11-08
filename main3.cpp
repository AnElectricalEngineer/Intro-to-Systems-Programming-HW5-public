//#include "FastDeliveryCompany.H"
//#include "ProfessionalDeliveryCompany.H"
//#include "DeliveryCompany.H"
//#include "DeliveryVehicle.H"
//#include "FastDeliveryVehicle.H"
//#include "ProfessionalDeliveryVehicle.H"
//#include "Parcel.H"
//#include <string.h>
//#include <cstdio>
//#include <math.h>
//#include <iostream>
//using namespace  std;
//char* createNameID(const char* name, int ID)
//{
//	int IDlen = (ID > 1 ? (int)ceil(log10(float(ID + 1))) : 1);
//	char* name_ = new char[strlen(name) + IDlen + 1];
//	char* num = new char[IDlen + 1];
//	strcpy(name_, name);
//	sprintf(num, "%d", ID);
//	strcat(name_, num);
//	delete[] num;
//	return name_;
//}
//
//int main()
//{
//	DeliveryCompany* fedEks = new DeliveryCompany(250);
//	ProfessionalDeliveryCompany* OOPS = new ProfessionalDeliveryCompany(101);
//
//	int vecNum = 4;
//	DeliveryVehicle** proVehicles = new DeliveryVehicle * [vecNum];
//	int i;
//	for (i = 0; i < vecNum; i++)
//	{
//		char* name = createNameID("pro", i);
//		proVehicles[i] = new ProfessionalDeliveryVehicle(name, Quality(3 + i % 3));
//		delete[] name;
//	}
//	DeliveryVehicle* soozooki = new DeliveryVehicle("soozooki", ok);
//	int parcelNum = 8;
//	Parcel** pParcels = new Parcel * [parcelNum];
//	for (i = 0; i < parcelNum; i++)
//	{
//		char* name = createNameID("p", i);
//		pParcels[i] = new Parcel(name, (i * 5) % 6);
//		delete[] name;
//	}
//	for (i = 0; i < 2; i++)
//		OOPS->addVehicle(proVehicles[i]);
//	for (int j = 0; j < 3; j++)
//		OOPS->receiveParcel(pParcels[j]);
//	OOPS->addVehicle(proVehicles[2]);
//	for (i = 3; i < 5; i++)
//		OOPS->receiveParcel(pParcels[i]);
//	OOPS->addVehicle(proVehicles[3]);
//	OOPS->addVehicle(soozooki);
//	for (; i < parcelNum - 1; i++)
//		OOPS->receiveParcel(pParcels[i]);
//	OOPS->performDeliveryDay();
//	OOPS->receiveParcel(pParcels[parcelNum - 1]);
//	OOPS->performDeliveryDay();
//	OOPS->displayFunds();
//	OOPS->displayNumberOfDeliveries();
//	delete OOPS;
//	delete[] pParcels;
//	delete[] proVehicles;
//
//	cout << endl;
//
//	parcelNum = 16;
//	pParcels = new Parcel * [parcelNum];
//	for (i = 0; i < parcelNum; i++)
//	{
//		char* name = createNameID("r", i);
//		pParcels[i] = new Parcel(name, (i * 16) % 9);
//		delete[] name;
//	}
//
//	ProfessionalDeliveryVehicle* feeat = new ProfessionalDeliveryVehicle("feeat", bad);
//	fedEks->addVehicle(feeat);
//	fedEks->receiveParcel(pParcels[0]);
//	FastDeliveryVehicle* korkinet = new FastDeliveryVehicle("korkinet", bad);
//	fedEks->addVehicle(korkinet);
//	fedEks->receiveParcel(pParcels[1]);
//	fedEks->receiveParcel(pParcels[2]);
//	DeliveryVehicle* neesan = new DeliveryVehicle("neesan", good);
//	fedEks->addVehicle(neesan);
//	fedEks->performDeliveryDay();
//
//	cout << endl;
//
//	for (i = 3; i < 7; i++)
//		fedEks->receiveParcel(pParcels[i]);
//	ProfessionalDeliveryVehicle soobaroo = ProfessionalDeliveryVehicle("soobaroo", ok);
//	for (i = 7; i < parcelNum; i++)
//		fedEks->receiveParcel(pParcels[i]);
//
//	fedEks->performDeliveryDay();
//	fedEks->displayNumberOfDeliveries();
//
//	cout << endl;
//
//	fedEks->performDeliveryDay();
//	fedEks->displayFunds();
//	delete fedEks;
//	delete[] pParcels;
//	return 0;
//}
