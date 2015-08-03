//
//  MailTemplate.h
//  iAdmin
//
//  Created by Евгений Илюшин on 17.07.15.
//  Copyright (c) 2015 Евгений Илюшин. All rights reserved.
//

#ifndef __iAdmin__MailTemplate__
#define __iAdmin__MailTemplate__

#include <apps/Master.h>

namespace apps {
    namespace messages {
        class MailTemplate : public Master {
        public:
            MailTemplate(cppcms::service &srv);
            virtual ~MailTemplate();
            void prepare();

        };
    }
}

#endif /* defined(__iAdmin__MailTemplate__) */
