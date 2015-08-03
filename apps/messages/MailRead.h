//
//  MailRead.h
//  iAdmin
//
//  Created by Евгений Илюшин on 17.07.15.
//  Copyright (c) 2015 Евгений Илюшин. All rights reserved.
//

#ifndef __iAdmin__MailRead__
#define __iAdmin__MailRead__

#include <apps/Master.h>

namespace apps {
    namespace messages {
        class MailRead : public Master {
        public:
            MailRead(cppcms::service &srv);
            virtual ~MailRead();
            void prepare();
        };
    }
}

#endif /* defined(__iAdmin__MailRead__) */
