class Vtype
{
   public:
	Vtype();
	~Vtype();
	int GetMinCode() const { return _minCode;}
	int GetMaxCode() const { return _maxCode;}
	int GetLength() const { return _length;}
	int GetNumberOfVtypes() const { return _numberVtypes;}
	char * GetVtypes() const { return _pVtypes;}
	char * GetVtype(int inVtypeCode) const;
	void DisplayVtypes() const;

   private:
	int _minCode;
	int _maxCode;
	int _length;
	int _numberVtypes;
	char * _pVtypes;
	char * _pVtype;
};
