class Color
{
   public:
	Color();
	~Color();
	int GetMinCode() const { return _minCode;}
	int GetMaxCode() const { return _maxCode;}
	int GetLength() const { return _length;}
	int GetNumberOfColors() const { return _numberColors;}
	char * GetColors() const { return _pColors;}
	char * GetColor(int inColorCode) const;
	void DisplayColors() const;

   private:
	int _minCode;
	int _maxCode;
	int _length;
	int _numberColors;
	char * _pColors;
	char * _pColor;
};
