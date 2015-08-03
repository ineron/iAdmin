//
//  Reports.h
//  iAdmin
//
//  Created by Евгений Илюшин on 17.07.15.
//  Copyright (c) 2015 Евгений Илюшин. All rights reserved.
//

#ifndef __iAdmin__Reports__
#define __iAdmin__Reports__

#include <apps/Master.h>

namespace apps {
        class Reports : public Master {
        public:
            Reports(cppcms::service &srv);
            virtual ~Reports();
            virtual void main(std::string path);
            void prepare();
        };
    
}

#endif /* defined(__iAdmin__Reports__) */
