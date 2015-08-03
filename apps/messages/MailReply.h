//
//  MailReply.h
//  iAdmin
//
//  Created by Евгений Илюшин on 17.07.15.
//  Copyright (c) 2015 Евгений Илюшин. All rights reserved.
//

#ifndef __iAdmin__MailReply__
#define __iAdmin__MailReply__

#include <apps/Master.h>

namespace apps {
    namespace messages {
        class MailReply : public Master {
        public:
            MailReply(cppcms::service &srv);
            virtual ~MailReply();
            void prepare();
        };
    }
}

#endif /* defined(__iAdmin__MailReply__) */
