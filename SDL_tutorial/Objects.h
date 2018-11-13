//
//  Objects.h
//  SDL_tutorial
//
//  Created by Ashley Lu Couch on 11/13/18.
//  Copyright © 2018 Ashley Lu Couch. All rights reserved.
//

#ifndef Objects_h
#define Objects_h

#include "Color.h"

class Objects{
private:
    int height;
    int width;
    Color array;
    
    
    
public:
    
    Objects ( int h, int w){
        height = h;
        width = w;
    }
    
    int getHeight(){
        return height;
    }

    int getWidth(){
        return width;
    }
    
    
    
};

//class ObjectsDraw{
    
    //Object pickle( 18, 6, Color Pickle[18][6]);
    
    
    
    
    
    
    
//};



#endif /* Objects_h */
