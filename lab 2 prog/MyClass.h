class MyClass
{
public:
	MyClass(); //����������� �� �������������
	MyClass(const char* data, int size); //����������� � �����������
	MyClass(const char* data); //��������� ����������� � �����������
	MyClass(const MyClass& other); //����������� ���������
	~MyClass(); //����������
	int SetData(const char* data, int size); //������ ��� �������
	int SetData(const char* data); //��������� ������ ��� �������
	void SetCurrentSize(int currentSize); //������ ��� ��������� ������
	char* GetData(); //������ ��� �������
	int GetCurrentSize(); //������ ��� ������ �������
	int GetMaxSize(); //������ ��� ������������� ������ �������
	int Print(); //���� �������
	MyClass operator-(char element); //�������� ��� ��������� �������� ������� � �������(2 ������)
	int operator<(const MyClass& other); //�������� ��� ��������� ������ ������
	MyClass operator*(const MyClass& other); //�������� ��� ��������� �������-�������� ���� ��������, � ����� ����������� ��������
	MyClass operator=(const MyClass& other); //�������� ������������ ��� ������� ��������� ���� ������ ��'���� �����
private:
	char* _data; //�������� �� ������� �����
	int _currentSize; //�������� �����
	int _maxSize; //������������ ����� �����

	bool DataCheck(const MyClass& other); //��� �������� �� ��, �� ����-�������� �������� ����� ����� �� ������ � ���'��, �� �� NULL-pointer
	bool Compare(int firstSize, int secondSize); //��� ��������� ���� �������� �������� ������
};
