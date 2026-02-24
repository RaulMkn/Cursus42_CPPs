#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap scav("Scavy");
	ScavTrap trap("Trappy");

	scav.attack("Trappy");
	trap.takeDamage(20);
	trap.beRepaired(10);
	trap.attack("Scavy");
	scav.takeDamage(20);
	scav.guardGate();
	scav.guardGate();

	ScavTrap copy(scav);
	copy.attack("some other trap");

	return 0;
}