
#ifndef SDDS_COVIDPATIENT_H_
#define SDDS_COVIDPATIENT_H_

#include "Patient.h"

namespace sdds {  


	class CovidPatient : public Patient {
	public:
		CovidPatient();
		char type() const {	return 'C';	}
		virtual ostream& write(std::ostream&)const;
		virtual istream& csvRead(std::istream&);
		virtual istream& read(std::istream&);
	};

}
#endif // !SDDS_COVIDPATIENT_H_



