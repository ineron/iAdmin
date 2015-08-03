//
//  DbView.h
//  iAdmin
//
//  Created by Евгений Илюшин on 10.07.15.
//  Copyright (c) 2015 Евгений Илюшин. All rights reserved.
//

#ifndef __iAdmin__DbView__
#define __iAdmin__DbView__

#include <apps/Master.h>

namespace apps {
    namespace service {
        class DbView:public Master  {
        public:
            DbView(cppcms::service &srv);
            virtual ~DbView();
            void prepare();
            //void main(std::string path);
        };
    }
}

#endif /* defined(__iAdmin__DbView__) */
