//
//  Forms.cpp
//  iAdmin
//
//  Created by Евгений Илюшин on 20.07.15.
//  Copyright (c) 2015 Евгений Илюшин. All rights reserved.
//

#include <apps/defines.h>

#include <apps/forms/Forms.h>
#include <data/admin/forms/forms.h>

#include <cppcms/url_mapper.h>
#include <cppcms/url_dispatcher.h>


namespace apps {
    Forms::Forms(cppcms::service &srv): Master(srv)
    {
        __DEBUGLINE__;
        dispatcher().assign("/?",&Forms::prepare,this);
        mapper().assign(""); // default empty url
        
    }
    
    Forms::~Forms()
    {
        
    }
    
    void Forms::main(std::string path)
    {
        __DEBUGLINE__;
        std::cout<<path<<std::endl;
        application::main(path);
    }
    
    void Forms::prepare()
    {
        data::admin::forms::forms tmpl;
        apps::Master::prepare(tmpl);
        render("forms",tmpl);
    }
    
}