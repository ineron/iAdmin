//
//  Notifications.cpp
//  iAdmin
//
//  Created by Евгений Илюшин on 16.07.15.
//  Copyright (c) 2015 Евгений Илюшин. All rights reserved.
//

#include <apps/defines.h>
#include <apps/notify/Notifications.h>

#include <data/admin/notify/notifications.h>

#include <cppcms/url_mapper.h>
#include <cppcms/url_dispatcher.h>

namespace apps{
    namespace  notify {
        Notifications::Notifications(cppcms::service &srv):Master(srv)
        {
            dispatcher().assign("/?",&Notifications::prepare,this);
            mapper().assign("/"); // default empty url
        }
        Notifications::~Notifications(){};
        
        void Notifications::prepare()
        {
            __DEBUGLINE__;
            data::admin::notify::notifications tmpl;
            render("notifications",tmpl);
        }
    }
}
