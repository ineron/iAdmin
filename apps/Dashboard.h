//
//  Dashboard.h
//  iAdmin
//
//  Created by Евгений Илюшин on 10.07.15.
//  Copyright (c) 2015 Евгений Илюшин. All rights reserved.
//

#ifndef __iAdmin__Dashboard__
#define __iAdmin__Dashboard__

#include <apps/Master.h>

namespace apps {
    class Dashboard:public Master  {
    public:
        Dashboard(cppcms::service &srv);
        virtual ~Dashboard();
        void prepare();
        //void main(std::string path);
    };
}

#endif /* defined(__iAdmin__Dashboard__) */
