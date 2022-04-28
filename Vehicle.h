#include <string>

using namespace std;

string SSNHyphens(const string & aSSN);
string SSNNoHyphens(const string & aSSN);

class Vehicle
{
	public:
		Vehicle();
		~Vehicle(){}

		const string & GetVtypeCode() const { return _vtypeCode; }
		const string & GetVmakeCode() const { return _vmakeCode; }
		const string & GetTopColorCode() const { return _topColorCode; }
		const string & GetBottomColorCode() const { return _bottomColorCode; }
		const string & GetTag() const { return _tag; }
		const string & GetSSN() const { return _SSN; }
                string GetSSNWithHyphens() const { return SSNHyphens(_SSN); }
		int GetLength() const { return _length; }                       
		bool IsFound() const { return _found; }
		bool IsDeleted() const { return _deleted; }
		void SetDeleted(bool inDeleted) { _deleted = inDeleted; }
		
		void SetSSN(const string & inSSN) { _SSN = SSNNoHyphens(inSSN); }
		void SetVmakeCode(const string &);
		void SetVtypeCode(const string &);
		void SetTopColorCode(const string &);
		void SetBottomColorCode(const string &);  
		void SetTag(const string &);  
		void SetFound(bool inFound) { _found = inFound; } 

		void MakeVehicle(const string &);
		string UnMakeVehicle();
		void DisplayVehicle() const;
		void PrintVehicle() const;

	private:
		string _vtypeCode;
		string _vmakeCode;
		string _topColorCode;
		string _bottomColorCode;
		string _SSN;
		string _tag;
		int _length;
		bool _deleted;
		bool _found;
};
