//
//  MailRead.cpp
//  iAdmin
//
//  Created by Евгений Илюшин on 17.07.15.
//  Copyright (c) 2015 Евгений Илюшин. All rights reserved.
//

#include <apps/defines.h>
#include <apps/messages/MailRead.h>

#include <data/admin/messages/messages.h>

#include <cppcms/url_mapper.h>
#include <cppcms/url_dispatcher.h>

namespace apps{
    namespace  messages {
        MailRead::MailRead(cppcms::service &srv):Master(srv)
        {
            dispatcher().assign("/?",&MailRead::prepare,this);
            mapper().assign("/"); // default empty url
        }
        MailRead::~MailRead(){};
        
        void MailRead::prepare()
        {
            __DEBUGLINE__;
            //data::admin::notify::mail tmpl;
            //render("mail",tmpl);
        }
        
    }
}
