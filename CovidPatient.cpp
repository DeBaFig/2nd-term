
#include "CovidPatient.h"

namespace sdds {
	int nextCovidTicket = 1;

	CovidPatient::CovidPatient() : Patient(nextCovidTicket)
	{
		nextCovidTicket++;
	}

	ostream& CovidPatient::write(std::ostream& os) const
   {
	   if (Patient::fileIO())
		   Patient::csvWrite(os);
	   else {
		   os << "COVID TEST" << endl;
		   Patient::write(os);
		   os << endl;
	   }
	   return os;
   }

   istream& CovidPatient::csvRead(std::istream& in)
   {
	   Patient::csvRead(in);
	   nextCovidTicket = (Patient::number() + 1);
	   return in;
   }

   istream& CovidPatient::read(std::istream& in)
   {
	   return Patient::read(in);
   }

}