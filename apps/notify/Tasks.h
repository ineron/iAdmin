//
//  Tasks.h
//  iAdmin
//
//  Created by Евгений Илюшин on 16.07.15.
//  Copyright (c) 2015 Евгений Илюшин. All rights reserved.
//

#ifndef __iAdmin__Tasks__
#define __iAdmin__Tasks__

#include <apps/Master.h>

namespace apps {
    namespace  notify {
        class Tasks:public Master  {
        public:
            Tasks(cppcms::service &srv);
            virtual ~Tasks();
            void prepare();
            //void main(std::string path);
        };
    }
}
#endif /* defined(__iAdmin__Tasks__) */
