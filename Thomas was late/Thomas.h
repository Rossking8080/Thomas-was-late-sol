#ifndef THOMAS_H
#define THOMAS_H

#include "PlayableCharacter.h"

class Thomas : public playableCharacter
{
public:
	Thomas();
	bool virtual handleInput();

};
#endif THOMAS_H