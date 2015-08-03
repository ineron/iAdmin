//
//  Service.h
//  iAdmin
//
//  Created by Евгений Илюшин on 20.07.15.
//  Copyright (c) 2015 Евгений Илюшин. All rights reserved.
//

#ifndef __iAdmin__Service__
#define __iAdmin__Service__

#include <apps/Master.h>

namespace apps {
    class Service:public Master  {
    public:
        Service(cppcms::service &srv);
        virtual ~Service();
        void prepare();
        void main(std::string path);
    };
    
}

#endif /* defined(__iAdmin__Service__) */
