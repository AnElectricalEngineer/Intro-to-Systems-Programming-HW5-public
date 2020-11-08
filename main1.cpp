#include "FastDeliveryCompany.H"
#include "ProfessionalDeliveryCompany.H"
#include "DeliveryCompany.H"
#include "DeliveryVehicle.H"
#include "FastDeliveryVehicle.H"
#include "ProfessionalDeliveryVehicle.H"
#include "Parcel.H"

int main()
{
	DeliveryCompany* fedEks = new DeliveryCompany(150);
	ProfessionalDeliveryCompany* OOPS = new ProfessionalDeliveryCompany(125);
	FastDeliveryCompany* DEEHL = new FastDeliveryCompany();
	DeliveryVehicle* soobaroo = new DeliveryVehicle("soobaroo",bad);
	ProfessionalDeliveryVehicle* cangoo = 
		new ProfessionalDeliveryVehicle("cangoo",ok);
	FastDeliveryVehicle* soosita = 
		new FastDeliveryVehicle("soosita",good);

	fedEks->addVehicle(soobaroo);
	OOPS->addVehicle(cangoo);
	DEEHL->addVehicle(soosita);
	
	Parcel* book = new Parcel("book",1);
	Parcel* treasure = new Parcel("treasure",2);
	Parcel* hot_air = new Parcel("hot_air",3);

	fedEks->receiveParcel(book);
	OOPS->receiveParcel(treasure);
	DEEHL->receiveParcel(hot_air);

	fedEks->performDeliveryDay();
	fedEks->displayFunds();
	
	OOPS->performDeliveryDay();
	OOPS->displayFunds();
	
	DEEHL->performDeliveryDay();
	DEEHL->displayFunds();
	
	delete fedEks;
	delete DEEHL;
	delete OOPS;
	return 0;
}
