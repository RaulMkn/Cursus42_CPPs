#include "FragTrap.hpp"

int main(void)
{
	FragTrap frag("Fragy");
	FragTrap trap("Trappy");

	frag.attack("Trappy");
	trap.takeDamage(30);
	trap.beRepaired(10);
	trap.attack("Fragy");
	frag.takeDamage(30);
	frag.highFivesGuys();
	frag.highFivesGuys();

	FragTrap copy(frag);
	copy.attack("some other trap");

	return 0;
}