#ifndef CW2_COMPLEX_WIDGETS_HPP
#define CW2_COMPLEX_WIDGETS_HPP

#include "simple_widgets.hpp"


class ComplexWidgets {
public:
    ComplexWidgets();

    void table(float x, float y, float z, materialStruct *material);
    void chair(float x, float y, float z, materialStruct *material);
    void bottle(float x, float y, float z, materialStruct *material);
    void glass(float x, float y, float z, materialStruct *material);

};


#endif //CW2_COMPLEX_WIDGETS_HPP
