//
//  main.cpp
//  iAdmin
//
//  Created by Евгений Илюшин on 08.07.15.
//  Copyright (c) 2015 Евгений Илюшин. All rights reserved.
//

#include <cppcms/applications_pool.h>
#include <cppcms/service.h>
#include <locale>
#include "apps/iAdminApp.h"


static cppcms::service* srv;
static bool got_sighup;

void handler()
{
    got_sighup = true;
    srv->shutdown();
}


int main(int argc,char **argv)
{
    setlocale(LC_ALL,"");
    while(1) {
        try {
            // создаем сервис
            std::cout<<"START SERVER ADMIN"<<std::endl;
            cppcms::service srv(argc,argv);
            //создаем шаред птр
            cppcms::service service(argc,argv);
            booster::intrusive_ptr<apps::iAdminApp> web=new apps::iAdminApp(service);
            //booster::intrusive_ptr<apps::iTradeRpcApp> rpc=new apps::iTradeRpcApp(service);
            // задаем корень
            //srv.applications_pool().mount(rpc);
            srv.applications_pool().mount(web);
            // запускаем
            srv.run();
        }
        catch(std::exception const &e) {
            std::cerr << "Failed: " << e.what() << std::endl;
            std::cerr << booster::trace(e) << std::endl;
            return 1;
        }
        if(got_sighup) {
            got_sighup = false;
            continue;
        }
        break;
    }
    
    
    return 0;
}
