#pragma once
#ifndef ANIMAL_H_
#define ANIMAL_H_

typedef struct animal animal_type;
struct animal
{
	const struct animal_vtable_ *vtable_;
	const char *name;
};

struct animal_vtable_
{
	const char *(*sound)(void);
};

static inline const char *animal_sound(animal_type* animal)
{
	return animal->vtable_->sound();
}

extern const struct animal_vtable_ CAT[], DOG[];
#endif // !ANIMAL_H_
