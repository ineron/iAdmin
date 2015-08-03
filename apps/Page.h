//
//  Page.h
//  iAdmin
//
//  Created by Евгений Илюшин on 23.07.15.
//  Copyright (c) 2015 Евгений Илюшин. All rights reserved.
//

#ifndef __iAdmin__Page__
#define __iAdmin__Page__

#include <apps/Master.h>

namespace apps {
    class Page:public Master  {
        std::string m_pageRef;
    public:
        Page(cppcms::service &srv, std::string pageRef = "00000000-0000-0000-0000-000000000000");
        virtual ~Page();
        void prepare();
        void main(std::string path);
    };
}


#endif /* defined(__iAdmin__Page__) */
