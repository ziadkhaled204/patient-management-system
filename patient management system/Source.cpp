#include<iostream>
#include<list>
using namespace std;
class Patient {
public:
	string name;
	int age;
	string condition;
	int priority;

	Patient(string Name, int Age, string Condition) {
		name = Name;
		age = Age;
		condition = Condition;
		this->priority = determine_priority(condition);
	}
	int determine_priority(const string& condition) {
		if (condition == "critical") {
			return 3; // Highest priority
		}
		else if (condition == "urgent") {
			return 2; // Medium priority
		}
		else if (condition == "normal") {
			return 1; // Lowest priority
		}

	}
	friend ostream& operator << (ostream& os, const Patient& patient) // to print the removed patient
	{
		os << "Name : " << patient.name << ", Age : " << patient.age << " ,Condition : "
			<< patient.condition << ", priority : " << patient.priority << endl;
		return os;
	}
};
class priorityQueue
{
	list<Patient> pq;// list of patients
	static bool comparePriority(const Patient& p1, const Patient& p2) { // to compare 
		return p1.priority > p2.priority;
	}
public:


	void addPatient(const Patient& patient)
	{
		list<Patient> temp;
		if (pq.empty())
		{
			pq.push_front(patient);
		}
		else
		{
			Patient p = pq.front();
			while (!pq.empty() && pq.front().priority > patient.priority)
			{
				temp.push_front(p);
				pq.pop_front();
			}
			pq.push_front(patient);
			while (!temp.empty())
			{
				pq.push_front(temp.front());
				temp.pop_front();
			}
			cout << "patient added successfully" << endl;
		}
	}
	Patient process_patient() {
		if (pq.empty()) {
			cout << "No patients in the queue\n";
		}
		Patient top = pq.front();
		pq.pop_front();
		return top;
	}
	void update_patient(const string& name, const string& new_condition) {
		list<Patient> temp;
		bool updated = false;

		while (!pq.empty()) {
			Patient p = pq.front();
			pq.pop_front();
			if (p.name == name) {
				p.condition = new_condition;
				p.priority = p.determine_priority(new_condition);
				updated = true;
			}
			temp.push_back(p);
		}
		if (!updated) {
			cout << "Patient not found\n";
		}

		for (const auto& p : temp) {
			pq.push_back(p);
		}
	}

	void displayQueue()
	{

		pq.sort(comparePriority);

		for (const auto& p : pq) {
			cout << "Name: " << p.name << ", Age: " << p.age << ", Condition: "
				<< p.condition << ", Priority: " << p.priority << endl;
		}
	}
	int queue_size() {
		return pq.size();
	}
	string front_name() {
		if (pq.empty()) {
			cout << "No patients in the queue\n";
		}
		return pq.front().name;
	}
};

int main()
{
	priorityQueue pq;
	Patient p1("ahmed", 35, "critical"), p2("mazen", 45, "urgent"), p3("omar", 25, "normal")
		, p4("mohamed", 15, "normal");
	int size;
	cout << "Kindly Enter Number Of Patients : ";
	cin >> size;
	cout << "Enter the name, age, and condition of the patient sequentially.";
	for (int i = 0; i < size; i++)
	{
		string name;
		int age;
		string condition;
		cin >> name >> age >> condition;
		Patient p(name, age, condition);
		pq.addPatient(p);
	}
	pq.displayQueue();
	cout << "processing patient ....." << endl << endl;
	cout << pq.process_patient() << endl;
	cout << "Queue after processing : " << endl << endl;
	pq.displayQueue();
	cout << endl << "condition of mazen has been updated to urgent " << endl << endl;
	pq.update_patient("mazen", "urgent");
	pq.displayQueue();
	cout << endl << "condition of omar has been updated to urgent " << endl << endl;
	pq.update_patient("omar", "critical");
	pq.displayQueue();
	//cout << pq.front_name();

	return 0;

}