class Date
{
public:
	int _day;
	int	_month;
	int _year;

	void Print();
	
	int IsleapYear(int day, int month, int year);

	int CheckDate(int day, int month, int year);

	void InputDate();

	int SetDate(int day, int month, int year);
};

