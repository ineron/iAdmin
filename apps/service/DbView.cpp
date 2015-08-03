//
//  DbView.cpp
//  iAdmin
//
//  Created by Евгений Илюшин on 10.07.15.
//  Copyright (c) 2015 Евгений Илюшин. All rights reserved.
//

#include <apps/service/DbView.h>
#include <cppcms/url_dispatcher.h>

#include <data/admin/service/service.h>

namespace apps{
    namespace  service{
        
        DbView::DbView(cppcms::service &srv):apps::Master(srv)
        {
            dispatcher().assign("/?",&DbView::prepare,this);
            mapper().assign(""); // default empty url
        }
        DbView::~DbView()
        {
            
        }
        void DbView::prepare()
        {
            data::admin::service::service tmpl;
            apps::Master::prepare(tmpl);
            render("service",tmpl);
        }
        
        
    }
}