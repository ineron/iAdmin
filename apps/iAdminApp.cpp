//
//  iAdminApp.cpp
//  iAdmin
//
//  Created by Евгений Илюшин on 10.07.15.
//  Copyright (c) 2015 Евгений Илюшин. All rights reserved.
//

#include <apps/iAdminApp.h>
#include <apps/Dashboard.h>
#include <apps/service/DbView.h>
#include <apps/Login.h>
#include <apps/Lock.h>
#include <apps/Forgotpassword.h>
#include <apps/notify/Notify.h>
#include <apps/messages/Messages.h>
#include <apps/service/Service.h>
//#include <apps/contracors/Contractors.h>
//#include <apps/users/Users.h>
#include <apps/forms/Forms.h>
#include <apps/reports/Reports.h>
//#include <apps/goods/Goods.h>
#include <apps/Page.h>

#include <cppcms/service.h>
#include <cppcms/applications_pool.h>
#include <cppcms/url_mapper.h>
#include <cppcms/http_response.h>
#include <cppcms/json.h>
#include <cppcms/session_interface.h>


#include <iostream>


namespace apps {
    iAdminApp::iAdminApp(cppcms::service &srv): cppcms::application(srv)
    {

        
        attach( new apps::Dashboard(srv),
               "/",
               "/{1}",
               "/((/.*)?)",1);

        attach( new apps::Login(srv),
               "login",
               "/login{1}",
               "/login((/.*)?)",1);
    
        attach( new apps::Forgotpassword(srv),
               "forgotpassword",
               "/forgotpassword{1}",
               "/forgotpassword((/.*)?)",1);

        attach( new apps::Lock(srv),
               "lock",
               "/lock{1}",
               "/lock((/.*)?)",1);
        
        attach( new apps::notify::Notify(srv),
               "notify",
               "/notify{1}",
               "/notify((/.*)?)",1);

        attach( new apps::Messages(srv),
               "messages",
               "/messages{1}",
               "/messages((/.*)?)",1);

        /*********************************************/
        attach( new apps::Dashboard(srv),
               "dashboard",
               "/dashboard{1}",
               "/dashboard((/.*)?)",1);
        
        attach( new service::DbView(srv),
               "dbview",
               "/dbview{1}",
               "/dbview((/.*)?)",1);
        
        attach( new apps::Page(srv),
               "goods",
               "/goods{1}",
               "/goods((/.*)?)",1);

        attach( new apps::Service(srv),
               "service",
               "/service{1}",
               "/service((/.*)?)",1);

        attach( new apps::Forms(srv),
               "forms",
               "/forms{1}",
               "/forms((/.*)?)",1);

        attach( new apps::Reports(srv),
               "reports",
               "/reports{1}",
               "/reports((/.*)?)",1);

        attach( new apps::Page(srv),
               "contractors",
               "/contractors{1}",
               "/contractors((/.*)?)",1);

        attach( new apps::Page(srv),
               "users",
               "/users{1}",
               "/users((/.*)?)",1);

        
        mapper().root(settings().get<std::string>("admin.root"));
    }
    

    iAdminApp::~iAdminApp()
    {
        
    }
    
    void iAdminApp::main(std::string path)
    {
        std::cout<<path<<std::endl;
        session().load();
        std::cout<<session().is_set("uid")<<std::endl;
        try {
            if(application::session().is_set("uid") || path == "/login" || path == "/login/") {
                application::main(path);
            }
            else {
                response().set_redirect_header(url("/login"));
            }
        }
        catch(apps::database_version_error const &e) {
            response().set_redirect_header(url("/dashboard"));
            return;
        }
        catch(apps::database_is_not_configured_error const &e) {
            response().set_redirect_header(url("/login"));
            return;
        }
    
    }

}