//
//  Tasks.cpp
//  iAdmin
//
//  Created by Евгений Илюшин on 16.07.15.
//  Copyright (c) 2015 Евгений Илюшин. All rights reserved.
//

#include <apps/defines.h>

#include <apps/notify/Tasks.h>

#include <data/admin/notify/tasks.h>

#include <cppcms/url_mapper.h>
#include <cppcms/url_dispatcher.h>

namespace apps{
    namespace  notify {
        Tasks::Tasks(cppcms::service &srv):Master(srv)
        {
            dispatcher().assign("/?",&Tasks::prepare,this);
            mapper().assign("/"); // default empty url
        }
        Tasks::~Tasks(){};
        
        void Tasks::prepare()
        {
            __DEBUGLINE__;
            data::admin::notify::tasks tmpl;
            render("tasks",tmpl);
        }
    }
}