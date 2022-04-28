#include <string>

using namespace std;

string SSNHyphens(const string & aSSN);
string SSNNoHyphens(const string & aSSN);
string ZipHyphens(const string & aZip);
string ZipNoHyphens(const string & aZip); 

class Person
{
	public:
		Person();
		~Person(){}

		const string & GetSSN() const { return _SSN; }
		string GetSSNWithHyphens() const { return SSNHyphens(_SSN); }
		const string & GetZip() const { return _zip; }
		string GetZipWithHyphens() const { return ZipHyphens(_zip); }
		const string & GetOLN() const { return _OLN; }
		const string & GetStateCode() const { return _stateCode; }
		const string & GetCountyCode() const { return _countyCode; }
		const string & GetLastName() const { return _lastName; }
		const string & GetFirstName() const { return _firstName; }
		const string & GetMiddleInitial() const { return _middleInitial; }
		const string & GetStreet() const { return _street; }
		const string & GetCity() const { return _city; }
		int GetLength() const { return _length; }                       
		bool IsFound() const { return _found; }
		bool IsDeleted() const { return _deleted; }
		void SetDeleted(bool inDeleted) { _deleted = inDeleted; }
		
		void SetSSN(const string & inSSN) { _SSN = SSNNoHyphens(inSSN); }
		void SetOLN(const string & inOLN) { _OLN = inOLN; }
		void SetStateCode(const string &);
		void SetCountyCode(const string &);
		void SetLastName(const string &);
		void SetFirstName(const string &);
		void SetMiddleInitial(const string &);
		void SetStreet(const string &);
		void SetCity(const string &);
		void SetZip(const string & inZip) { _zip = ZipNoHyphens(inZip); }  
		void SetFound(bool inFound) { _found = inFound; } 
		void MakePerson(const string &);
		string UnMakePerson();
		void DisplayPerson() const;
		void PrintPerson() const;

	private:
		string _SSN;
		string _OLN;
		string _stateCode;
		string _countyCode;
		string _lastName;
		string _firstName;
		string _middleInitial;
		string _street;
		string _city;
		string _zip;
		int _length;
		bool _deleted;
		bool _found;
};
