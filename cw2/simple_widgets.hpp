#ifndef CW2_SIMPLE_WIDGETS_HPP
#define CW2_SIMPLE_WIDGETS_HPP

#include "materials.hpp"

class SimpleWidgets {
public:
    SimpleWidgets();

    void plane(float scale, materialStruct* material);
    void cuboid(float x, float y, float z, materialStruct* material);
    void cylinder(float scale, int edges, int fineness, materialStruct*
    material);

};


#endif //CW2_SIMPLE_WIDGETS_HPP
