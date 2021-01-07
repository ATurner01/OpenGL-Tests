#ifndef CW2_SIMPLE_WIDGETS_HPP
#define CW2_SIMPLE_WIDGETS_HPP

typedef struct coords{
    float x,y,z;
} coords;


class SimpleWidgets {
public:
    SimpleWidgets();

    void cuboid(coords pos);

};


#endif //CW2_SIMPLE_WIDGETS_HPP
