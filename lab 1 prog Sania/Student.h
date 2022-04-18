class Student
{
public:
	Student();
	Student(const char* name, int course, char student_gender);
	Student(const Student& other);
	void Set(const char* name, int course, char student_gender);
	void SetName(const char* name);
	void SetCourse(int course);
	void SetGender(char student_gender);
	char* GetName();
	char* GetName(char name[], int num);
	int GetCourse();
	char GetGender();
	void Print();
	~Student();
private:
	char* _name;
	int _course;
	char _gender;
};

