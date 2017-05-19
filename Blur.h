//
// Created by chelseaw on 01/05/17.
//

#ifndef IMAGE_EDITOR_BLUR_H
#define IMAGE_EDITOR_BLUR_H
#include "Action.h"

class Blur: public Action{

public:
    virtual void run(int pos, Mat& img, Mat& imgFactor);
    virtual string description();

};

#endif //IMAGE_EDITOR_BLUR_H
