//
//  Forgotpassword.h
//  iAdmin
//
//  Created by Евгений Илюшин on 13.07.15.
//  Copyright (c) 2015 Евгений Илюшин. All rights reserved.
//

#ifndef __iAdmin__Forgotpassword__
#define __iAdmin__Forgotpassword__

#include <apps/Master.h>

namespace apps {
    class Forgotpassword:public Master  {
    public:
        Forgotpassword(cppcms::service &srv);
        virtual ~Forgotpassword();
        void prepare();
        //void main(std::string path);
    };
}
#endif /* defined(__iAdmin__Forgotpassword__) */
