//
//  ReportBuilder.h
//  iAdmin
//
//  Created by Евгений Илюшин on 17.07.15.
//  Copyright (c) 2015 Евгений Илюшин. All rights reserved.
//

#ifndef __iAdmin__ReportBuilder__
#define __iAdmin__ReportBuilder__

#include <apps/Master.h>

namespace apps {
    namespace reports {
        class ReportBuilder : public Master {
        public:
            ReportBuilder(cppcms::service &srv);
            virtual ~ReportBuilder();
            void prepare();
        };
    }
}

#endif /* defined(__iAdmin__ReportBuilder__) */
