/* Citation and Sources...
Final Project Milestone 5
Module: Ticket
Filename: Ticket.cpp
Version 3.0
Author	(edited) Denize Bassi Figueiredo	 / Original:  Professor Fardad
Revision History
-----------------------------------------------------------
Date            Reason
07/26/2021  Implement of ticket feature	and Implement of
Patient derived class
-----------------------------------------------------------
Material provided to complete my Project
-----------------------------------------------------------
Date            Reason
08/01/2021  Implement of triage of patients with covid
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
Date            Reason
08/02/2021  Implement of PreTriage module and last stage of
the project implementation
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#include "Ticket.h"
#include <sstream>

namespace sdds {
	Ticket::Ticket(int number) {
		m_number = number;
	}
	Ticket::operator Time() const {
		return m_time;
	}
	int Ticket::number() const {
		return m_number;
	}
	void Ticket::resetTime() {
		m_time.setToNow();
	}
	std::ostream& Ticket::csvWrite(std::ostream& ostr) const {
		return ostr << m_number << "," << m_time;
	}
	std::istream& Ticket::csvRead(std::istream& istr) {

		string str;
		getline(istr, str, '\n');
		stringstream ss(str);
		ss >> m_number;
		ss.ignore();
		m_time.read(ss);
		return istr;
	}
	std::ostream& Ticket::write(std::ostream& ostr) const {
		return ostr << "Ticket No: " << m_number << ", Issued at: " << m_time;
	}
	std::istream& Ticket::read(std::istream& istr) {
		return csvRead(istr);
	}
}
