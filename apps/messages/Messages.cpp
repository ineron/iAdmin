//
//  Messages.cpp
//  iAdmin
//
//  Created by Евгений Илюшин on 17.07.15.
//  Copyright (c) 2015 Евгений Илюшин. All rights reserved.
//

#include <apps/defines.h>

#include <data/admin/messages/messages.h>

#include <apps/messages/Messages.h>
#include <apps/messages/MailList.h>
#include <apps/messages/MailCompose.h>
#include <apps/messages/MailRead.h>
#include <apps/messages/MailReply.h>
#include <apps/messages/MailTemplate.h>

#include <apps/NavPanel.h>

#include <cppcms/url_mapper.h>
#include <cppcms/url_dispatcher.h>


namespace apps {
    Messages::Messages(cppcms::service &srv): Master(srv)
    {
        __DEBUGLINE__;
        
        dispatcher().assign("/?",&Messages::prepare,this);
        mapper().assign(""); // default empty url
        
        
        attach( new messages::MailList(srv),
               "maillist",
               "/maillist{1}",
               "/maillist((/.*)?)",1);
        
        attach( new messages::MailCompose(srv),
               "mailcompose",
               "/mailcompose{1}",
               "/mailcompose((/.*)?)",1);
        
        attach( new messages::MailRead(srv),
               "mailread",
               "/mailread{1}",
               "/mailread((/.*)?)",1);
        
        attach( new messages::MailReply(srv),
               "mailreply",
               "/mailreply{1}",
               "/mailreply((/.*)?)",1);
        
        attach( new messages::MailTemplate(srv),
               "mailtemplate",
               "/mailtemplate{1}",
               "/mailtemplate((/.*)?)",1);
        
    }
    Messages::~Messages()
    {
        
    }
    void Messages::main(std::string path)
    {
        __DEBUGLINE__;
        std::cout<<path<<std::endl;
        application::main(path);
    }
    void Messages::prepare()
    {
        __DEBUGLINE__;
        data::admin::messages tmpl;
        apps::Master::prepare(tmpl);
        render("messages",tmpl);
        
    }
    
    
}