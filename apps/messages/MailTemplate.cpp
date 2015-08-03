//
//  MailTemplate.cpp
//  iAdmin
//
//  Created by Евгений Илюшин on 17.07.15.
//  Copyright (c) 2015 Евгений Илюшин. All rights reserved.
//

#include <apps/defines.h>
#include <apps/messages/MailTemplate.h>

#include <data/admin/messages/messages.h>

#include <cppcms/url_mapper.h>
#include <cppcms/url_dispatcher.h>

namespace apps{
    namespace  messages {
        MailTemplate::MailTemplate(cppcms::service &srv):Master(srv)
        {
            dispatcher().assign("/?",&MailTemplate::prepare,this);
            mapper().assign("/"); // default empty url
        }
        MailTemplate::~MailTemplate(){};
        
        void MailTemplate::prepare()
        {
            __DEBUGLINE__;
            //data::admin::messages::mail tmpl;
            //render("mail",tmpl);
        }
        
    }
}
