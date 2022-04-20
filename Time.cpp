

#include "Time.h"
#include "utils.h"
#include <iomanip>
#include<sstream>
#include<istream>


using namespace std;
namespace sdds {

	Time& Time::setToNow()
	{
		m_min = getTime();
		return *this;
	}
	Time::Time(unsigned int min)
	{
		m_min = 0;
		if(min)	m_min = min;
	}
	std::ostream& Time::write(std::ostream& ostr) const
	{
		ostr << setfill('0') << setw(2)<< (int)(m_min / 60) << ":"; // hour
		ostr << setfill('0') << setw(2) << m_min % 60; // min
		return cout;
	}
	std::istream& Time::read(std::istream& istr)
	{
		char sep;
		string str;
		int hour =0, min = 0;
		bool hOk = false, mOk = false, sepOk = false;
		istr >> str;
		istringstream ss(str);
		if(ss >> hour && hour >= 0) hOk = true;
		else istr.setstate(std::ios_base::failbit);
		if (ss >> sep && sep == ':') sepOk = true;
		else istr.setstate(std::ios_base::failbit);
		if (ss >> min && min >= 0) mOk = true;
		else istr.setstate(std::ios_base::failbit);
		if (sepOk && hOk && mOk) this->m_min = (hour * 60) + min;
		return cin;
	}
	Time& Time::operator-=(const Time& D)
	{
		if (this->m_min < D.m_min) {
			int numOfdays = ((int)(D.m_min/ 1440) + (D.m_min % 1440 > 0 ? 1 : 0));
			int result = (1440 +((this->m_min + (1440 * (numOfdays - 1))) - D.m_min));
			this->m_min = result;
		}
		else
			this->m_min -= D.m_min;
		return *this;
	}
	Time Time::operator-(const Time& D) const
	{
		int result;
		if (this->m_min < D.m_min) {
			int numOfdays = ((int)(D.m_min / 1440) + (D.m_min % 1440 > 0 ? 1 : 0));
			result = (1440 + ((this->m_min + (1440 * (numOfdays - 1))) - D.m_min));
		}
		else
			result = this->m_min - D.m_min;
		return Time(result);
	}
	Time& Time::operator+=(const Time& D)
	{
		this->m_min += D.m_min;
		return *this;
	}
	Time Time::operator+(const Time& D) const
	{
		int result = this->m_min + D.m_min;
		return Time(result);
	}
	Time& Time::operator=(unsigned int val)
	{
		this->m_min = val;
		return *this;
	}
	Time& Time::operator*=(unsigned int val)
	{
		this->m_min *= val;
		return *this;
	}
	Time& Time::operator/=(unsigned int val)
	{
		this->m_min /= val;
		return *this;
	}
	Time Time::operator*(unsigned int val) const
	{
		int result = this->m_min * val;
		return Time(result);
	}
	Time Time::operator/(unsigned int val) const
	{
		int result = this->m_min / val;
		return Time(result);
	}
	Time::operator unsigned int() const
	{
		return m_min;
	}
	Time::operator int() const
	{
		return m_min;
	}

	std::ostream& operator<<(std::ostream& ostr, const Time& D)
	{
		return D.write(ostr);
	}
	std::istream& operator>>(std::istream& istr, Time& D)
	{
		return D.read(istr);
	}
}