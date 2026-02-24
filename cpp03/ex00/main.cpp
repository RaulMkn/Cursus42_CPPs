#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap clap("Clappy");
	ClapTrap trap("Trappy");

	clap.attack("Trappy");
	trap.takeDamage(0);
	trap.beRepaired(10);
	trap.attack("Clappy");
	clap.takeDamage(0);

	ClapTrap copy(clap);
	copy.attack("some other trap");

	return 0;
}