//
//  Lock.h
//  iAdmin
//
//  Created by Евгений Илюшин on 10.07.15.
//  Copyright (c) 2015 Евгений Илюшин. All rights reserved.
//

#ifndef __iAdmin__Lock__
#define __iAdmin__Lock__

#include <apps/Master.h>

namespace apps {
    class Lock:public Master  {
    public:
        Lock(cppcms::service &srv);
        virtual ~Lock();
        void prepare();
        //void main(std::string path);
    };
}
#endif /* defined(__iAdmin__Lock__) */
