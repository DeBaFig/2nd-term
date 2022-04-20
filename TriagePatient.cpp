
#include "TriagePatient.h"
#include <sstream>
#include <string>


namespace sdds {
	int nextTriageTicket = 1;

	TriagePatient::TriagePatient() : Patient(nextTriageTicket)
	{
		m_symptoms = nullptr;
		nextTriageTicket++;
	}


	ostream& TriagePatient::csvWrite(std::ostream& os) const
	{
		Patient::csvWrite(os);
		os<< "," << m_symptoms;
		return os;
	}

	ostream& TriagePatient::write(std::ostream& os) const
	{
		if (Patient::fileIO()) {
			csvWrite(os);
		}
		else {
			os << "TRIAGE" << endl;
			Patient::write(os);
			os << endl << "Symptoms: " << m_symptoms << endl;
		}
		return os;
	}

	istream& TriagePatient::csvRead(std::istream& in)
	{
		string str, name;
		getline(in, str, '\n');
		stringstream ss(str), ss2(str);
		Patient::csvRead(ss);
		for (int i = 0; i < 4; i++)
			getline(ss2, name, ',');
		getline(ss2, name, '\n');
		setSymptoms(name.c_str());
		nextTriageTicket = (Patient::number() + 1);
		return in;
	}

	istream& TriagePatient::read(std::istream& in)
	{
		string str;
		if (Patient::fileIO())
			csvRead(in);
		else {
			Patient::read(in);
			cout << "Symptoms: ";
			getline(in, str, '\n');
			setSymptoms(str.c_str());
		}
		return in;
	}

	void TriagePatient::setSymptoms(const char* str)
	{
		if (str) {
			if(m_symptoms != nullptr)
				delete[] m_symptoms;
			m_symptoms = nullptr;
			m_symptoms = new char[(strLen(str) + 1)];
			strCpy(m_symptoms, str);
		}
	}

	TriagePatient::~TriagePatient()
	{
		delete[] m_symptoms;
		m_symptoms = nullptr;
	}

}