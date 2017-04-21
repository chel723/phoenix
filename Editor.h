//
// Created by chelseaw on 21/04/17.
//

#ifndef IMAGE_EDITOR_EDITOR_H
#define IMAGE_EDITOR_EDITOR_H

#include <iostream>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>


class Editor2 : public Editor{
    
};

class Editor
{
public:
    Editor(std::string s);
    virtual std::string menu()=0;
    virtual void run()=0;
    virtual ~Editor(){}

private:
    std::string menu_;
};

#endif //IMAGE_EDITOR_EDITOR_H
