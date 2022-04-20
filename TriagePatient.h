
#ifndef SDDS_TRIAGEPATIENT_H
#define SDDS_TRIAGEPATIENT_H

#include "Patient.h"

namespace sdds {

	class TriagePatient : public Patient {
		char* m_symptoms;
	public:
		TriagePatient();
		char type() const { return 'T'; }
		virtual ostream& csvWrite(std::ostream&) const;
		virtual ostream& write(std::ostream&)const;
		virtual istream& csvRead(std::istream&);
		virtual istream& read(std::istream&);
		void setSymptoms(const char*);
		~TriagePatient();
	};
}
#endif // !SDDS_TRIAGEPATIENT_H


