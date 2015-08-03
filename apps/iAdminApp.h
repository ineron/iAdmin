//
//  iAdminApp.h
//  iAdmin
//
//  Created by Евгений Илюшин on 10.07.15.
//  Copyright (c) 2015 Евгений Илюшин. All rights reserved.
//

#ifndef __iAdmin__iAdminApp__
#define __iAdmin__iAdminApp__

#include <cppcms/application.h>
#include <apps/Master.h>

namespace apps {
    class iAdminApp : public cppcms::application {
    public:
        iAdminApp(cppcms::service &srv);
        virtual ~iAdminApp();
        virtual void main(std::string path);
    };
}

#endif /* defined(__iAdmin__iAdminApp__) */
