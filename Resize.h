//
// Created by WANG Chelsea on 5/19/17.
//

#ifndef IMAGE_EDITOR_RESIZE_H
#define IMAGE_EDITOR_RESIZE_H

#include "Action.h"

class Resize: public Action {

public:
    virtual void run(int pos, Mat& img, Mat& imgFactor);
    virtual string description();

};


#endif //IMAGE_EDITOR_RESIZE_H
