//
// Created by WANG Chelsea on 5/19/17.
//

#ifndef IMAGE_EDITOR_DILATE_H
#define IMAGE_EDITOR_DILATE_H

#include "Action.h"

class Dilate: public Action{

public:
    virtual void run(int pos, Mat& img, Mat& imgFactor);
    virtual string description();

};


#endif //IMAGE_EDITOR_DILATE_H
