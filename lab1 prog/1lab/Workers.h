class Worker
{
public:
	Worker();
	Worker(const char* name, int age, int work_experience);
	Worker(const Worker& other);
	void Set(const char* name, int age, int work_experience);
	void SetName(const char* name);
	void SetAge(int age);
	void SetExperience(int work_experience);
	char* GetName();
	char* GetName(char name[], int num);
	int GetAge();
	int GetExperience();
	void Print();
	~Worker();
private:
	char* _name;
	int _age;
	int _workExperience;
};
