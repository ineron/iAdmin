//
//  Notify.cpp
//  iAdmin
//
//  Created by Евгений Илюшин on 16.07.15.
//  Copyright (c) 2015 Евгений Илюшин. All rights reserved.
//

#include <apps/defines.h>

#include <apps/notify/Notify.h>
#include <apps/notify/Mail.h>
#include <apps/notify/Notifications.h>
#include <apps/notify/Tasks.h>

namespace apps {
    namespace notify {
        Notify::Notify(cppcms::service &srv): cppcms::application(srv)
        {
            __DEBUGLINE__;
            attach( new Mail(srv),
                   "mail",
                   "/mail{1}",
                   "/mail((/.*)?)",1);
            
            attach( new Notifications(srv),
                   "notifications",
                   "/notifications{1}",
                   "/notifications((/.*)?)",1);
            
            attach( new Tasks(srv),
                   "tasks",
                   "/tasks{1}",
                   "/tasks((/.*)?)",1);
        }
        Notify::~Notify()
        {
        
        }
        void Notify::main(std::string path)
        {
            __DEBUGLINE__;
            std::cout<<path<<std::endl;
            application::main(path);
        }
        
    }
}