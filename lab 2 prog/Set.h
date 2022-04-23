class Set
{
public:
	Set(); //����������� �� �������������
	Set(const char* data, int size); //����������� � �����������
	Set(const char* data); //��������� ����������� � �����������
	Set(const Set& other); //����������� ���������
	~Set(); //����������
	int SetData(const char* data, int size); //������ ��� �������
	int SetData(const char* data); //��������� ������ ��� �������
	void SetCurrentSize(int currentSize); //������ ��� ��������� ������
	char* GetData(); //������ ��� �������
	int GetCurrentSize(); //������ ��� ������ �������
	int GetMaxSize(); //������ ��� ������������� ������ �������
	int Print(); //���� �������
	//friend Set operator-(Set& other, char element); //�������� ��� ��������� �������� ������� � �������(1 ������)
	Set operator-(char element); //�������� ��� ��������� �������� ������� � �������(2 ������)
	int operator<(const Set& other); //�������� ��� ��������� ������ ������
	Set operator*(const Set& other); //�������� ��� ��������� �������-�������� ���� ��������, � ����� ����������� ��������
	Set operator=(const Set& other); //�������� ������������ ��� ������� ��������� ���� ������ ��'���� �����
private:
	char* _data; //�������� �� ������� �����
	int _currentSize; //�������� �����
	int _maxSize; //������������ ����� �����

	bool DataCheck(const Set& other); //��� �������� �� ��, �� ����-�������� �������� ����� ����� �� ������ � ���'��, �� �� NULL-pointer
	bool Compare(int firstSize, int secondSize); //��� ��������� ���� �������� �������� ������
};
