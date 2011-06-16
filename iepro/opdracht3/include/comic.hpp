#ifndef COMIC_H_
#define COMIC_H_

#include "nds.h"
#include "video.hpp"

struct Comic
{
	Color* image;
	u16 image_width;
	u16 image_offset;
};

void scroll_comic( Comic *comic, u8 speed );
void copy_comic_to_buffer( Comic *comic, Color *buffer );

/*
** Laat in de methode scroll_comic de offset_x van het plaatje met speed vooruit scrollen 
** Als het plaatje tot het eind is gescrolled, wacht je 1.5 seconden en zet je het plaatje weer terug naar het begin. 
** 
** Laat de methode copy_comic_to_buffer het plaatje kopi�ren naar de buffer. 
** 
** Maak in je main een Comic aan met het plaatje van blackboard. 
** Laat het plaatje scrollen met snelheid 1 (gebruik scroll_comic).
*/

#endif