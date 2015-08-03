//
//  MailList.cpp
//  iAdmin
//
//  Created by Евгений Илюшин on 17.07.15.
//  Copyright (c) 2015 Евгений Илюшин. All rights reserved.
//


#include <apps/defines.h>
#include <apps/messages/MailList.h>

#include <data/admin/messages/messages.h>

#include <cppcms/url_mapper.h>
#include <cppcms/url_dispatcher.h>


namespace apps{
    namespace  messages {
        MailList::MailList(cppcms::service &srv):Master(srv)
        {
            dispatcher().assign("/?",&MailList::prepare,this);
            mapper().assign("/"); // default empty url
        }
        MailList::~MailList(){};
        
        void MailList::prepare()
        {
            __DEBUGLINE__;
            data::admin::messages::message_list tmpl;

            render("message_list",tmpl);
        }
        
    }
}