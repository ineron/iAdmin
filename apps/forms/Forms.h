//
//  Forms.h
//  iAdmin
//
//  Created by Евгений Илюшин on 20.07.15.
//  Copyright (c) 2015 Евгений Илюшин. All rights reserved.
//

#ifndef __iAdmin__Forms__
#define __iAdmin__Forms__

#include <apps/Master.h>

namespace apps {
    class Forms:public Master  {
    public:
        Forms(cppcms::service &srv);
        virtual ~Forms();
        void prepare();
        void main(std::string path);
    };
    
}

#endif /* defined(__iAdmin__Forms__) */
