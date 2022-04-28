class State
{
   public:
	State();
	~State();
	int GetMinCode() const { return _minCode;}
	int GetMaxCode() const { return _maxCode;}
	int GetLength() const { return _length;}
	int GetNumberOfStates() const { return _numberStates;}
	char * GetStates() const { return _pStates;}
	char * GetState(int inStateCode) const;
	void DisplayStates() const;

   private:
	int _minCode;
	int _maxCode;
	int _length;
	int _numberStates;
	char * _pStates;
	char * _pState;
};
