//
//  Page.cpp
//  iAdmin
//
//  Created by Евгений Илюшин on 23.07.15.
//  Copyright (c) 2015 Евгений Илюшин. All rights reserved.
//

#include <apps/defines.h>
#include <apps/Page.h>
#include <apps/NavPanel.h>

#include <data/admin/dashboard.h>
#include <cppcms/url_mapper.h>
#include <cppcms/url_dispatcher.h>

namespace apps{
    Page::Page(cppcms::service &srv,std::string pageRef):Master(srv),m_pageRef(pageRef)
    {
        dispatcher().assign("/?",&Page::prepare,this);
        mapper().assign(""); // default empty url
        //dispatcher().assign("/version",&config::version,this);
        //mapper().assign("version","/version"); // default empty url
        
    }
    Page::~Page(){};
    void Page::prepare()
    {
        data::admin::page tmpl;
        /*
        apps::Master::prepare(tmpl);
        data::admin::widget_set ws;
        data::admin::widget_group wg;
        {
            data::admin::widget_set ws;
            ws.headlines = "col-sm-12 col-md-12 col-lg-12";
            ws.widget_id = "1";
            data::admin::FormContent cont;
            cont.is_smart = 1;
            cont.header = " Registration form ";
            {
                data::admin::FormSection section;
                section.type = 1;
                section.placeholder="Контрагент";
                section.icons = "icon-append fa fa-user";
                section.headline = "col col-6";
                cont.sections.push_back(section);
            }
            {
                data::admin::FormSection section;
                section.type = 1;
                section.placeholder="Договор";
                section.icons = "icon-append fa fa-user";
                section.headline = "col col-6";
                cont.sections.push_back(section);
            }
            {
                data::admin::FormSection section;
                section.type = 1;
                section.placeholder="Операция";
                section.icons = "icon-append fa fa-user";
                section.headline = "col col-6";
                cont.sections.push_back(section);
            }
            {
                data::admin::FormSection section;
                section.type = 1;
                section.placeholder="Номер";
                section.icons = "icon-append fa fa-user";
                section.headline = "col col-6";
                cont.sections.push_back(section);
            }
            data::admin::FooterContent footer;
            footer.content= "<button type=\"submit\" class=\"btn btn-primary\">Обработать</button>";
            cont.footer.push_back(footer);
            data::admin::FooterContent footer1;
            footer1.content= "<button type=\"submit\" class=\"btn btn-default\">Сохранить</button>";
            cont.footer.push_back(footer1);
            ws.content = cont;
            wg.widgets.push_back(ws);
        }

        
        data::admin::WidgetGroup groups;
        //groups.push_back(wg);
        
        tmpl.widget_group.push_back(wg);
         */
         render("page",tmpl);
    }
    
    void Page::main(std::string path)
    {
        __DEBUGLINE__;
        prepare();
    }
    
}
