//
//  MailList.h
//  iAdmin
//
//  Created by Евгений Илюшин on 17.07.15.
//  Copyright (c) 2015 Евгений Илюшин. All rights reserved.
//

#ifndef __iAdmin__MailList__
#define __iAdmin__MailList__

#include <apps/Master.h>

namespace apps {
    namespace messages {
        class MailList : public Master {
        public:
            MailList(cppcms::service &srv);
            virtual ~MailList();
            void prepare();
        };
    }
}

#endif /* defined(__iAdmin__MailList__) */
