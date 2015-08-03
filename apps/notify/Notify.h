//
//  Notify.h
//  iAdmin
//
//  Created by Евгений Илюшин on 16.07.15.
//  Copyright (c) 2015 Евгений Илюшин. All rights reserved.
//

#ifndef __iAdmin__Notify__
#define __iAdmin__Notify__

#include <apps/Master.h>

namespace apps {
    namespace notify {
        class Notify : public cppcms::application {
        public:
            Notify(cppcms::service &srv);
            virtual ~Notify();
            virtual void main(std::string path);
        };
    }
}

#endif /* defined(__iAdmin__Notify__) */
