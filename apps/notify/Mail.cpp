//
//  Mail.cpp
//  iAdmin
//
//  Created by Евгений Илюшин on 16.07.15.
//  Copyright (c) 2015 Евгений Илюшин. All rights reserved.
//

#include <apps/defines.h>
#include <apps/notify/Mail.h>

#include <data/admin/notify/mail.h>

#include <cppcms/url_mapper.h>
#include <cppcms/url_dispatcher.h>

namespace apps{
    namespace  notify {
        Mail::Mail(cppcms::service &srv):Master(srv)
        {
            dispatcher().assign("/?",&Mail::prepare,this);
            mapper().assign("/"); // default empty url
        }
        Mail::~Mail(){};
        void Mail::prepare()
        {
            __DEBUGLINE__;
            data::admin::notify::mail tmpl;
            render("mail",tmpl);
        }
        
    }
}