#ifndef CW2_COMPLEX_WIDGETS_HPP
#define CW2_COMPLEX_WIDGETS_HPP

#include "simple_widgets.hpp"


class ComplexWidgets {
public:
    ComplexWidgets();

    void table(materialStruct *material);
    void chair(materialStruct *material);
    void bottle(materialStruct *material);
    void glass(materialStruct *material);
    void fireplace(materialStruct *material);
    void lightWithFan(materialStruct *material, float angle);

private:
    SimpleWidgets *simple;

};


#endif //CW2_COMPLEX_WIDGETS_HPP
