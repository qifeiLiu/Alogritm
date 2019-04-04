#include "animal.h"
#include <stdio.h>


int main(void)
{
	animal_type kitty = { CAT, "Kitty" };
	animal_type lassie = { DOG, "Lassie" };

	printf("%s says %s\n",kitty.name,animal_sound(&kitty));
	printf("%s says %s\n",lassie.name,animal_sound(&lassie));
	system("pause");
	return 0;
}