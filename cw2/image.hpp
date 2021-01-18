#ifndef CW2_IMAGE_HPP
#define CW2_IMAGE_HPP

#include <string>
#include <QImage>
#include <GL/glu.h>

class Image {
public:
    Image(const std::string &file);
    ~Image();

    const GLubyte* imageField() const;
    unsigned int getWidth() const { return width; }
    unsigned int getHeight() const { return height; };

private:
    Image(const Image&);

    unsigned int width;
    unsigned int height;

    QImage *p_qimage;
    GLubyte *image;
};


#endif //CW2_IMAGE_HPP
