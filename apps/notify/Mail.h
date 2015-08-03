//
//  Mail.h
//  iAdmin
//
//  Created by Евгений Илюшин on 16.07.15.
//  Copyright (c) 2015 Евгений Илюшин. All rights reserved.
//

#ifndef __iAdmin__Mail__
#define __iAdmin__Mail__

#include <apps/Master.h>

namespace apps {
    namespace  notify {
        class Mail:public Master  {
        public:
            Mail(cppcms::service &srv);
            virtual ~Mail();
            void prepare();
            //void main(std::string path);
        };
    }
}
#endif /* defined(__iAdmin__Mail__) */
