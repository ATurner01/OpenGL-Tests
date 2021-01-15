#ifndef CW2_MATERIALS_HPP
#define CW2_MATERIALS_HPP

#include <GL/glu.h>

typedef struct materialStruct {
    GLfloat ambient[4];
    GLfloat diffuse[4];
    GLfloat specular[4];
    GLfloat shininess;
} materialStruct;

static materialStruct brassMaterial = {
        { 0.33, 0.22, 0.03, 1.0},
        { 0.78, 0.57, 0.11, 1.0},
        { 0.99, 0.91, 0.81, 1.0},
        27.8
};

static materialStruct whiteShinyMaterial = {
        { 1.0, 1.0, 1.0, 1.0},
        { 1.0, 1.0, 1.0, 1.0},
        { 1.0, 1.0, 1.0, 1.0},
        100.0
};

static materialStruct woodenMaterial = {
        { 0.33, 0.22, 0.03, 1.0},
        { 0.78, 0.57, 0.11, 1.0},
        { 0.99, 0.91, 0.81, 1.0},
        10.0
};

#endif //CW2_MATERIALS_HPP
