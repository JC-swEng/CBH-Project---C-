class County
{
   public:
	County();
	~County();
	int GetMinCode() const { return _minCode;}
	int GetMaxCode() const { return _maxCode;}
	int GetLength() const { return _length;}
	int GetNumberOfCountys() const { return _numberCountys;}
	char * GetCountys() const { return _pCountys;}
	char * GetCounty(int inCountyCode) const;
	void DisplayCountys() const;

   private:
	int _minCode;
	int _maxCode;
	int _length;
	int _numberCountys;
	char * _pCountys;
	char * _pCounty;
};
