//
//  Login.h
//  iAdmin
//
//  Created by Евгений Илюшин on 10.07.15.
//  Copyright (c) 2015 Евгений Илюшин. All rights reserved.
//

#ifndef __iAdmin__Login__
#define __iAdmin__Login__

#include <apps/Master.h>

namespace apps {
    class Login:public Master  {
    public:
        Login(cppcms::service &srv);
        virtual ~Login();
        void prepare();
        //void main(std::string path);
    };
}

#endif /* defined(__iAdmin__Login__) */
