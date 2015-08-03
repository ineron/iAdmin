//
//  Reports.cpp
//  iAdmin
//
//  Created by Евгений Илюшин on 17.07.15.
//  Copyright (c) 2015 Евгений Илюшин. All rights reserved.
//

#include <apps/defines.h>

#include <apps/reports/Reports.h>
#include <apps/reports/ReportBuilder.h>
#include <data/admin/reports/reports.h>

#include <cppcms/url_mapper.h>
#include <cppcms/url_dispatcher.h>

namespace apps {
    Reports::Reports(cppcms::service &srv): Master(srv)
    {
        __DEBUGLINE__;
        dispatcher().assign("/?",&Reports::prepare,this);
        mapper().assign(""); // default empty url

        attach( new reports::ReportBuilder(srv),
               "/",
               "/{1}",
               "/((/.*)?)",1);
    }
    
    Reports::~Reports()
    {
        
    }
    
    void Reports::main(std::string path)
    {
        __DEBUGLINE__;
        std::cout<<path<<std::endl;
        application::main(path);
    }
    
    void Reports::prepare()
    {
        data::admin::reports::reports tmpl;
        apps::Master::prepare(tmpl);
        render("reports",tmpl);
    }
    
}
