class Vmake
{
   public:
	Vmake();
	~Vmake();
	int GetMinCode() const { return _minCode;}
	int GetMaxCode() const { return _maxCode;}
	int GetLength() const { return _length;}
	int GetNumberOfVmakes() const { return _numberVmakes;}
	char * GetVmakes() const { return _pVmakes;}
	char * GetVmake(int inVmakeCode) const;
	void DisplayVmakes() const;

   private:
	int _minCode;
	int _maxCode;
	int _length;
	int _numberVmakes;
	char * _pVmakes;
	char * _pVmake;
};
