#include "fixed"

class Fixed{

	public:
		Fixed();
		Fixed(std::string num);
		Fixed(Fixed & other);
		int getRawBits( void ) const;
		void setRawBits( int const raw );

	private:
		int sisuBu;
		static const syousuBu;
}


