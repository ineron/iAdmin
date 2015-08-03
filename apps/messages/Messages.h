//
//  Messages.h
//  iAdmin
//
//  Created by Евгений Илюшин on 17.07.15.
//  Copyright (c) 2015 Евгений Илюшин. All rights reserved.
//

#ifndef __iAdmin__Messages__
#define __iAdmin__Messages__

#include <apps/Master.h>

namespace apps {
    class Messages : public Master {
    public:
        Messages(cppcms::service &srv);
        virtual ~Messages();
        virtual void main(std::string path);
        void prepare();
    };
    
}

#endif /* defined(__iAdmin__Messages__) */
