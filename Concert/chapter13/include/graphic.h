#ifndef GRAPHIC_H
#define GRAPHIC_H

typedef struct Graphic {
    unsigned int figure: 2;
    unsigned int color: 2;
    unsigned int line_color: 2;
    unsigned int line_style: 2;
} GRAPHIC;

void show_attr(GRAPHIC);

#endif //GRAPHIC_H
