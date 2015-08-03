//
//  Notifications.h
//  iAdmin
//
//  Created by Евгений Илюшин on 16.07.15.
//  Copyright (c) 2015 Евгений Илюшин. All rights reserved.
//

#ifndef __iAdmin__Notifications__
#define __iAdmin__Notifications__

#include <apps/Master.h>

namespace apps {
    namespace  notify {
        class Notifications:public Master  {
        public:
            Notifications(cppcms::service &srv);
            virtual ~Notifications();
            void prepare();
            //void main(std::string path);
        };
    }
}
#endif /* defined(__iAdmin__Notifications__) */
