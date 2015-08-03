//
//  MailCompose.h
//  iAdmin
//
//  Created by Евгений Илюшин on 17.07.15.
//  Copyright (c) 2015 Евгений Илюшин. All rights reserved.
//

#ifndef __iAdmin__MailCompose__
#define __iAdmin__MailCompose__

#include <apps/Master.h>

namespace apps {
    namespace messages {
        class MailCompose : public Master {
        public:
            MailCompose(cppcms::service &srv);
            virtual ~MailCompose();
            void prepare();
        };
    }
}

#endif /* defined(__iAdmin__MailCompose__) */
