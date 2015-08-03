//
//  Service.cpp
//  iAdmin
//
//  Created by Евгений Илюшин on 20.07.15.
//  Copyright (c) 2015 Евгений Илюшин. All rights reserved.
//

#include <apps/defines.h>

#include <apps/service/Service.h>

#include <cppcms/url_mapper.h>
#include <cppcms/url_dispatcher.h>

#include <data/admin/service/service.h>

namespace apps {
    Service::Service(cppcms::service &srv): Master(srv)
    {
        __DEBUGLINE__;
        dispatcher().assign("/?",&Service::prepare,this);
        mapper().assign(""); // default empty url
        
    }
    
    Service::~Service()
    {
        
    }
    
    void Service::main(std::string path)
    {
        __DEBUGLINE__;
        std::cout<<path<<std::endl;
        application::main(path);
    }
    
    void Service::prepare()
    {
        data::admin::service::service tmpl;
        apps::Master::prepare(tmpl);
        render("service",tmpl);
    }
    
}

