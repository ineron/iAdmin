//
//  Dushboard.cpp
//  iAdmin
//
//  Created by Евгений Илюшин on 10.07.15.
//  Copyright (c) 2015 Евгений Илюшин. All rights reserved.
//

#include <apps/defines.h>
#include <apps/Dashboard.h>
#include <apps/NavPanel.h>

#include <data/admin/dashboard.h>
#include <cppcms/url_mapper.h>
#include <cppcms/url_dispatcher.h>

namespace apps{
    Dashboard::Dashboard(cppcms::service &srv):Master(srv)
    {
        dispatcher().assign("/?",&Dashboard::prepare,this);
        mapper().assign(""); // default empty url
        //dispatcher().assign("/version",&config::version,this);
        //mapper().assign("version","/version"); // default empty url
    
    }
    Dashboard::~Dashboard(){};
    void Dashboard::prepare()
    {
                //std::cout<<__FILENAME__<<"::"<<__FUNCTION__<<" "<<__LINE__<<std::endl;
        __DEBUGLINE__;
        data::admin::dashboard tmpl;
        apps::Master::prepare(tmpl);

        //NavPanel navPanel(Master::service());
        //tmpl.navItems = navPanel.getDate();
        render("dashboard",tmpl);
    }

}