#include <fstream>
#include <string>

using namespace std;

class Vehicle;

class VehicleFile
{
	public:
	   VehicleFile();
	   ~VehicleFile();
	   int GetNumberOfVehicles() const { return _numberVehicles; }
	   int GetCurrentRecordNumber() const { return _currentRecordNumber; }
	   void SortBySSN();
	   Vehicle VSearchBySSN(const string & aSSN);
	   Vehicle SearchByRecordNumber(int inRecNum);
	   void AddVehicle(Vehicle & aVehicle);
	   void UpdateVehicle(Vehicle & aVehicle);

	private:
	   int _numberVehicles;
	   int _recordSize;
	   int _currentRecordNumber;
	   fstream _vehicleFile;

};
